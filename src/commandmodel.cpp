#include "commandmodel.h"
#include "command.h"
#include <QDebug>
#include <QObject>

CommandModel::CommandModel(QObject *parent)
    :QAbstractListModel(parent)
{
    loadData();
}

int CommandModel::rowCount(const QModelIndex &) const {
    return m_commandsList.count();
}

void CommandModel::addCommand(Command *command) {
    beginInsertRows(QModelIndex(), m_commandsList.count(), m_commandsList.count());
    m_commandsList << command;
    endInsertRows();
}

void CommandModel::addCommand(QString title, QString commandTxt) {
    Command * newCommand = new Command(title, commandTxt);
    beginInsertRows(QModelIndex(), m_commandsList.count(), m_commandsList.count());
    m_commandsList << newCommand;
    endInsertRows();
}

Command* CommandModel::getCommand(int row) {
    return m_commandsList.at(row);
}

bool CommandModel::loadData() {
    QFile loadFile("save.json");

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Impossible d'ouvrir le fichier");
        return false;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDocument(QJsonDocument::fromJson(saveData));

    read(loadDocument.object());

    return true;
}

bool CommandModel::saveData() {
    qDebug("Sauvegarde des données...");

    QFile saveFile("save.json");

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Impossible d'ouvrir le fichier");
        return false;
    }

    QJsonObject commandsJson;
    write(commandsJson);
    QJsonDocument saveDocument(commandsJson);
    saveFile.write(saveDocument.toJson());

    qDebug("Sauvegarde terminée !");
    return true;
}

void CommandModel::executeCommand(Command *command) {
    qDebug("EXECUTION DE LA COMMANDE " + command->commandTxt().toLatin1());
}

void CommandModel::read(const QJsonObject &json) {

    m_commandsList.clear();
    QJsonArray commandsArray = json["commands"].toArray();

    for (int index = 0; index < commandsArray.size(); ++index) {
        QJsonObject commandJson = commandsArray[index].toObject();

        Command* command = new Command();
        command->read(commandJson);
        m_commandsList.append(command);
    }
}

void CommandModel::write(QJsonObject &json) const{

    QJsonArray commandsArray;

    foreach (const Command* command, m_commandsList) {

        qDebug("write");
        QJsonObject commandJson;
        command->write(commandJson);
        commandsArray.append(commandJson);
    }

    json["commands"] = commandsArray;
}

QVariant CommandModel::data(const QModelIndex &index, int role) const {

    if(index.row() < 0 || index.row() >= m_commandsList.count()) {
        return QVariant();
    }

    Command* command = m_commandsList[index.row()];
    if (role == TitleRole) {
        return command->title();
    }
    else if (role == CommandTextRole) {
        return command->commandTxt();
    }

    return QVariant();
}

bool CommandModel::setData(const QModelIndex &index, const QVariant &value, int role) {

    if(index.row() < 0 || index.row() >= m_commandsList.count()) {
        return false;
    }

    if(data(index, role) == value) {
        return true;
    }

    Command* command = m_commandsList[index.row()];
    if (role == TitleRole) {
        command->setTitle(value.toString());
    }
    if (role == CommandTextRole) {
        command->setCommandTxt(value.toString());
    }

    QVector<int> roles;
    roles.append(role);

    QModelIndex topLeft = index.sibling(0, 0);
    QModelIndex bottomRight = index.sibling(m_commandsList.count()-1, 0);

    emit dataChanged(topLeft, bottomRight, roles);

    return true;
}

bool CommandModel::removeRows(int row, int count, const QModelIndex &parent) {

    if(row < 0 || row+count >= m_commandsList.count()) {
        return false;
    }
    qDebug("SUPPPRRRIM");
    beginRemoveRows(parent, row, row+count);

    //for (int i = 0; i < count; ++i) {
        m_commandsList.removeAt(row);
    //}

    endRemoveRows();

    return true;
}

bool CommandModel::insertRows(int row, int count, const QModelIndex &parent) {

    beginInsertRows(parent, row, row+count-1);

    for (int i = 0; i < count ; ++i) {
        m_commandsList.insert(row, new Command("test", "test"));
    }

    endInsertRows();

    return true;
}

QHash<int, QByteArray> CommandModel::roleNames() const {

    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[CommandTextRole] = "commandText";
    return roles;
}
