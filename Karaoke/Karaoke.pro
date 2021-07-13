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
TARGET = Karaoke

CONFIG += sailfishapp

SOURCES += src/Karaoke.cpp \
    src/datawork.cpp \
    src/filtr.cpp \
    src/line.cpp \
    src/song.cpp \
    src/songlist.cpp \
    src/word.cpp

DISTFILES += qml/Karaoke.qml \
    qml/cover/CoverPage.qml \
    qml/pages/LanguagesListPage.qml \
    qml/pages/SongPage.qml \
    qml/pages/SongsListPage.qml \
    qml/pages/TopSongsPage.qml \
    rpm/Karaoke.changes.in \
    rpm/Karaoke.changes.run.in \
    rpm/Karaoke.spec \
    rpm/Karaoke.yaml \
    translations/*.ts \
    Karaoke.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

QT += multimedia

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/Karaoke-de.ts

HEADERS += \
    src/datawork.h \
    src/filtr.h \
    src/line.h \
    src/song.h \
    src/songlist.h \
    src/word.h
