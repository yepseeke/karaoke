import QtQuick 2.0
import Sailfish.Silica 1.0
import Karaoke 1.0
import ".."

Page {
    id: page

    SilicaListView {
        anchors.fill: parent
        model: bands
        header: PageHeader {
            title: qsTr("Bands")
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
                text: model.element
            }
            Component{
                id:songsViewPage;
                SongsListPage{}
            }
            onClicked:{
                bands.setKey(model.element);
                songList.getSongList("/home/defaultuser/karaoke/base-all.json", language.getKey(), bands.getKey());
                pageStack.push(Qt.resolvedUrl("SongsListPage.qml"));
            }
        }
         VerticalScrollDecorator {}
    }
}
