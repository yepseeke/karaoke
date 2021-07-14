import QtQuick 2.0
import Sailfish.Silica 1.0
import Karaoke 1.0
import "pages"

ApplicationWindow
{
    initialPage: Component { LanguagesListPage { }}
    cover: Qt.resolvedUrl("cover/CoverPage.qml")
    allowedOrientations: defaultAllowedOrientations
    SongList {
        id: songList
    }
    SongList {
        id: topsongList
    }
    Filtr{
        id: language
    }
    Filtr{
        id:bands
    }
    Filtr{
        id:txt
    }

    Component.onCompleted: {language.getLanguages("/home/defaultuser/karaoke/base-all.json"); songList.readList(" ");
                                topsongList.readList(" "); txt.readText("/home/defaultuser/karaoke/1.txt");}
    Component.onDestruction: {topsongList.storeList();}
}
