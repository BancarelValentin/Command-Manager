#ifndef COMMAND_H
#define COMMAND_H
#include <QObject>

class Command : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title
                       READ title
                       WRITE setTitle
                       NOTIFY titleChanged)

    Q_PROPERTY(QString commandTxt
               READ commandTxt
               WRITE setCommandTxt
               NOTIFY commandTxtChanged)
public:
    Command();
    Command(QString aTitle, QString aCommand);

    QString title() const;
    QString commandTxt() const;

    void write(QJsonObject &json) const;
    void read(const QJsonObject &json);

public slots:
    void setTitle(QString arg);
    void setCommandTxt(QString arg);

signals:
    void titleChanged(QString arg);
    void commandTxtChanged(QString arg);

private:
    QString m_title;
    QString m_commandTxt;
};

#endif // COMMAND_H
