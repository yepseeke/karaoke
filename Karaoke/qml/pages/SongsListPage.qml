import QtQuick 2.0
import Sailfish.Silica 1.0
import Karaoke 1.0
import ".."

Page {
    id: page

    SilicaListView {
        anchors.fill: parent
        model: songList
        header: PageHeader {
            title: qsTr(bands.getKey())
        }
        delegate: BackgroundItem {
            Label {
                anchors {
                    left: parent.left
                    right: parent.right
                    verticalCenter: parent.verticalCenter
                    leftMargin: Theme.horizontalPageMargin
                    rightMargin: Theme.horizontalPageMargin
                }
                text: model.song
            }
            Component{
                id:songPageView
                SongPage{}
            }

            onClicked:{
                songList.setKey(model.key);
                //topsongList.readList(" ");
                topsongList.findaddelemandplusplusList(model.language, model.singer, model.song, model.id);
                topsongList.sortList();
                pageStack.push(Qt.resolvedUrl("SongPage.qml"));
            }
        }
         VerticalScrollDecorator {}
    }
}
