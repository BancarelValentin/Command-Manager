#include "settings.h"

Settings::Settings()
{
}

QString Settings::adressIP() const
{
    return m_adressIP;
}

void Settings::setAdressIP(QString arg)
{
    if (m_adressIP != arg) {
        m_adressIP = arg;
        emit adressIPChanged(arg);
    }
}
