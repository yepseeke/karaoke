import QtQuick 2.0
import QtMultimedia 5.6
import Sailfish.Silica 1.0
import Karaoke 1.0
import ".."

Page {
    id: page

    SilicaFlickable {
        anchors.fill: parent
        Item{
            id: playerItem
            y:150
            width:parent.width
            Audio{
                id:player
                source: "/home/defaultuser/karaoke/"+songList;
            }
            ProgressBar{
                id:pgb
                label: "%1-%2".arg(player.metaData.author).arg(player.metaData.title)

                value: player.position
                maximumValue: player.duration
            }
            Row{
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
            Label {
                id: counterLabel
                anchors {
                    left: parent.left
                    right: parent.right
                    top: playerItem.bottom
                    topMargin: Theme.horizontalPageMargin + 300
                }
                property int counter: 0
                text: "Counter: " + counter
                Timer {
                    interval: 1000
                    running: page.status === PageStatus.Active
                    repeat: true
                    onTriggered: {
                        counterLabel.counter = counterLabel.counter + 0.01
                    }
                }
            }
        }

        //            onClicked:{

        //            }
    }
    //VerticalScrollDecorator {}
}

