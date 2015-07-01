# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = TP3-Sailfish

CONFIG += sailfishapp

SOURCES += src/TP3-Sailfish.cpp \
    src/command.cpp \
    src/commandmodel.cpp \
    settings.cpp

OTHER_FILES += qml/TP3-Sailfish.qml \
    qml/cover/CoverPage.qml \
    rpm/TP3-Sailfish.changes.in \
    rpm/TP3-Sailfish.spec \
    rpm/TP3-Sailfish.yaml \
    translations/*.ts \
    TP3-Sailfish.desktop \
    qml/pages/MainPage.qml \
    qml/CommandItem.qml \
    qml/pages/CommandItem.qml \
    qml/pages/CommandDetail.qml \
    qml/pages/NewCommand.qml \
    qml/pages/Settings.qml

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/TP3-Sailfish-de.ts

HEADERS += \
    src/command.h \
    src/commandmodel.h \
    settings.h

