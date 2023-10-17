import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0



import"."



Window {
    id:root
    width: 1024
    height: 600
    visible: true
    title: qsTr("Head Unit")
    Image{
        id:backgroundImage
        anchors.fill:parent
        source: "background.png"
        }
    Rectangle {
        id:statusBar

        anchors{
            left:parent.left
            top: parent.top
            right:parent.right
        }
        color:Qt.rgba(0,0,0,0)
        RowLayout{
            id:buttonRow
            height:statusBar.height
            width:statusBar.width/3
            spacing: 0
            anchors{
                left:statusBar.left
                top:statusBar.top
            }
           /* Button{
                id:button1
                width:parent.width/2
                text: "Back"
            }
            Button{
                id:button2
                width:parent.width/2
                text: "Home"
                onClicked: mainLoader.source="stackViewPage"
            }








           // Text {
            //    id:statusText
             //   anchors{
              //  top:parent.top
             //   right: parent.right
              //  }
              //  width: parent.width/4
              //  verticalAlignment: Text.AlignVCenter
              //  color:"white"
               // text: qsTr("text")*/
            }

        }
    Loader{
        id: mainLoader
        anchors{
                    left:parent.left
                    right: parent.right
                    top: statusBar.bottom
                    bottom:parent.bottom
        }
        source: "stackViewPage.qml"

    }



}
