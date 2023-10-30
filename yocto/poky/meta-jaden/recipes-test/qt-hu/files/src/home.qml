import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item {
    id:home
    width: 1024
    height: 600

    Image{
        id:background
        width: 980
        height: 570
        source: "img/benz.jpg"
        anchors{
            right: parent.right
            bottom: parent.bottom
        }
        fillMode: Image.PreserveAspectFit

        Image{
            id:head_light_left
            width: 470
            height: 260
            anchors{
                verticalCenter: parent.verticalCenter
                left: parent.left
            }
            source: "img/head_light.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id:head_light_right
            width: 470
            height: 260
            anchors{
                verticalCenter: parent.verticalCenter
                right: parent.right
            }
            source: "img/head_light.png"
            fillMode: Image.PreserveAspectFit
        }
        Image {
            width: 760
            height: 262
            anchors{
                horizontalCenter: parent.horizontalCenter
                top: head_light_right.bottom
            }
            source: "img/ground_shadow.png"
            fillMode: Image.PreserveAspectFit
        }

    }
    Row{
        anchors{
            right: parent.right
            top: parent.top
            topMargin: 52
            rightMargin: 180
        }
        spacing: 200
        Button {
            id: music_icon
            width: 70
            height: 70
            background: Image {
                source: "img/music.jpeg"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            onClicked: {
                stackview.push(Qt.resolvedUrl("/music.qml"))
            }
        }

        Button {
            id: light_icon
            width: 70
            height: 70
            background: Image {
                source: "img/setting.jpeg"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            onClicked: {
                stackview.push(Qt.resolvedUrl("/light.qml"))
            }
        }

        Button {
            id: video_icon
            width: 70
            height: 70
            background: Image {
                source: "img/video.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            onClicked: {
                stackview.push(Qt.resolvedUrl("/video.qml"))
            }
        }
    }

    Column{
        anchors{
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: 32
        }
        spacing: 50
        Button {
            id: p_gear
            width: 60
            height: 60
            background: Image {
                source: "img/p.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            onClicked: {

            }
        }

        Button {
            id: r_gear
            width: 60
            height: 60
            background: Image {
                source: "img/r.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            onClicked: {

            }
        }

        Button {
            id: n_gear
            width: 60
            height: 60
            background: Image {
                source: "img/n.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            onClicked: {

            }
        }
        Button {
            id: d_gear
            width: 60
            height: 60
            background: Image {
                source: "img/d.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            onClicked: {

            }
        }
    }

}
