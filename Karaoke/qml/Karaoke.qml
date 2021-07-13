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
    Filter{
        id: language
    }
    Filter{
        id:bands
    }
    Component.onCompleted: {language.getLanguages(); topsongList.readList();}
    Component.onDestruction: {topsongList.storeList();}
}
