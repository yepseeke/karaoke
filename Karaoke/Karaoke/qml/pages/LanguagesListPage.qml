import QtQuick 2.0
import Sailfish.Silica 1.0
import Karaoke 1.0
import ".."

Page {
    id: page
    SilicaListView {
        anchors.fill: parent
        model: language
        header: PageHeader {
            title: qsTr("Languages")
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
                id:bandsViewPage;
                BandsListPage{}
            }
            onClicked:{
                language.setKey(model.element);
                bands.getBands("/home/defaultuser/karaoke/base-all.json", model.element);
                pageStack.push(Qt.resolvedUrl("BandsListPage.qml"));
            }
        }
        Rectangle{
            width:160
            height: 45
            anchors{
                bottom:parent.bottom
                right: parent.right
            }
            Text{
                anchors.centerIn: parent
                text: "Top Songs"
            }
            Component{
                id:topsongsView
                TopSongsPage{}
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    //songList.setKey(model.key);
                    //topsongList.readList(" ");
                    topsongList.sortList();
                    pageStack.push(Qt.resolvedUrl("TopSongsPage.qml"));
                }
            }
        }
        VerticalScrollDecorator {}
    }
}
