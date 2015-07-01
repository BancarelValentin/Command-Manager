#ifndef SETTINGS_H
#define SETTINGS_H
#include <QObject>

class Settings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString adressIP
                       READ adressIP
                       WRITE setAdressIP
                       NOTIFY adressIPChanged)
public:
    Settings();

    QString adressIP() const;

public slots:
    void setAdressIP(QString arg);

signals:
    void adressIPChanged(QString arg);

private:
    QString m_adressIP;
};

#endif // SETTINGS_H
