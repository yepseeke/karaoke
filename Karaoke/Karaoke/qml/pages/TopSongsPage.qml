import QtQuick 2.0
import Sailfish.Silica 1.0
import Karaoke 1.0
import ".."

Page {
    id: page

    SilicaListView {
        anchors.fill: parent
        model: topsongList
        header: PageHeader {
            title: qsTr("Top Songs")
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
                text: model.singer + " " + model.song + " " + model.totalview
            }
            onClicked:{
                songList.setKey(model.id);
                songList.setSing(model.song);
                topsongList.findaddelemandplusplusList(model.language, model.singer, model.song, model.id);
                pageStack.push(Qt.resolvedUrl("SongPage.qml"));
            }
        }
        VerticalScrollDecorator {}
    }
}
