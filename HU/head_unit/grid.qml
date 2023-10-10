import QtQuick 2.15
import QtQuick.Layouts 1.12

Item {
    
    x:150
    y:100
    ListModel{
        id:listModel
        ListElement {  page: "gear.qml"; iconSource: "gearIcon.jpg" }
        ListElement {  page: ""; iconSource: "light.jpg" }
        ListElement { page: "musicPlayer.qml"; iconSource: "musicPlayer.jpg" }
        ListElement {  page: "video.qml"; iconSource: "video.jpg" }
        ListElement {  page: "map2.qml"; iconSource: "map.jpg" }
    }
    GridView{
        id:gridView
        anchors.fill:parent


        model:listModel
        cellHeight:300
        cellWidth: 300
        delegate:Rectangle{
            width:100
            height: 100
            color: "grey"
            radius: 5
            Image {
                source: iconSource // Use the iconSource property from ListElement
                width: parent.width // Set the width of the image
                height: parent.height // Set the height of the image
                anchors.centerIn: parent
                        }

            Text {
                color:"white"
                text:name
                anchors.centerIn:parent
            }
            MouseArea{
                anchors.fill:parent
                onClicked: mainLoader.source=page
            }



    }


    }

}
