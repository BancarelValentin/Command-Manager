#include "command.h"
#include <QJsonObject>

Command::Command()
{
}

Command::Command(QString aTitle, QString aCommand)
{
    m_title = aTitle;
    m_commandTxt = aCommand;
}

QString Command::title() const
{
    return m_title;
}

QString Command::commandTxt() const
{
    return m_commandTxt;
}

void Command::write(QJsonObject &json) const
{
    json["title"] = m_title;
    json["commandText"] = m_commandTxt;
}

void Command::read(const QJsonObject &json)
{
    m_title = json["title"].toString();
    m_commandTxt = json["commandText"].toString();
}

void Command::setTitle(QString arg)
{
    if (m_title != arg) {
        m_title = arg;
        emit titleChanged(arg);
    }
}

void Command::setCommandTxt(QString arg)
{
    if (m_commandTxt != arg) {
        m_commandTxt = arg;
        emit commandTxtChanged(arg);
    }
}
