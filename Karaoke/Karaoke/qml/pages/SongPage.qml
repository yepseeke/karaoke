import QtQuick 2.0
import QtMultimedia 5.6
import Sailfish.Silica 1.0
import Karaoke 1.0
import ".."

Page {
    id: page
    SilicaListView {
        anchors.fill: parent
        model:txt
        header: PageHeader {
            title: ""
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
                color: "white";
            }
        }
        Item{
            id: playerItem
            x: parent.width/3
            width:parent.width
            Audio{
                id:player
                source: "/home/defaultuser/karaoke/"+songList.getKey()+".mp3";
            }
            Row{
                id:buttons
                anchors{
                    top:pgb.bottom
                }

                IconButton{
                    icon.source:"image://theme/icon-m-play"
                    onClicked:player.play()
                }
                IconButton{
                    icon.source:"image://theme/icon-m-pause"
                    onClicked:player.pause()
                }
            }
        }
    }

}



