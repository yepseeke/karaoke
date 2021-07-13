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
                text: model.band + " " + model.songname + " " + model.totalview
            }
//            onClicked:{

//            }
        }
        VerticalScrollDecorator {}
    }
}
