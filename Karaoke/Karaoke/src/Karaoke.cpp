#include <sailfishapp.h>
#include <QtQuick>
#include "songlist.h"
#include "filtr.h"
#include "song.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<SongList>("Karaoke", 1, 0, "SongList");
    qmlRegisterType<Filtr>("Karaoke", 1, 0, "Filtr");

    return SailfishApp::main(argc, argv);
}
