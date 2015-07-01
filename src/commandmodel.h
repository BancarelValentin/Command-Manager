#ifndef COMMANDMODEL_H
#define COMMANDMODEL_H
#include <QObject>
#include <QAbstractListModel>
#include <QtQuick>
#include "command.h"

class CommandModel : public QAbstractListModel {
    Q_OBJECT

public:

    enum CommandRoles {
        TitleRole,
        CommandTextRole
    };

    CommandModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    void addCommand(Command* command);
    Q_INVOKABLE void addCommand(QString title, QString commandTxt);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

    Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex &parent= QModelIndex());
    Q_INVOKABLE bool insertRows(int row, int count, const QModelIndex &parent= QModelIndex());

    Q_INVOKABLE Command *getCommand(int row);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    bool loadData();
    Q_INVOKABLE bool saveData();

    Q_INVOKABLE void executeCommand(Command* command);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Command*> m_commandsList;
    QSettings m_phoneSettings;

signals:
    Q_INVOKABLE void titleChanged(QString arg);
    Q_INVOKABLE void commandTxtChanged(QString arg);

};

#endif // COMMANDMODEL_H
