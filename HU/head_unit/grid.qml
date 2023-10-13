import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12


Item {
    visible: true
    width: 1024
    height: 600
    anchors.fill: parent




    Rectangle {

        id:leftb
        width: 50
        height: 600

        gradient: Gradient {
            GradientStop { position: redSlider.value; color: "lime" }
            GradientStop { position: greenSlider.value; color: "magenta" }
            GradientStop { position: blueSlider.value; color: "blue" }
        }


    }

    Rectangle {
        id:rightb
        x: 974
        width: 50
        height: 600

        gradient: Gradient {
            GradientStop { position: redSlider.value; color: "lime" }
            GradientStop { position: greenSlider.value; color: "magenta" }
            GradientStop { position: blueSlider.value; color: "blue" }
        }
    }

    Rectangle {
        id:topb
        anchors.top: parent.top
        x: 50
        width: 924
        height: 50

        gradient: Gradient {
            GradientStop { position: redSlider.value; color: "lime" }
            GradientStop { position: greenSlider.value; color: "magenta" }
            GradientStop { position: blueSlider.value; color: "blue" }
        }
    }

    Rectangle {
        id:bottomb
        anchors.bottom: parent.bottom
        x: 50
        width: 924
        height: 50

        gradient: Gradient {
            GradientStop { position: greenSlider.value; color: "lime" }
            GradientStop { position: redSlider.value; color: "magenta" }

            GradientStop { position: blueSlider.value; color: "blue" }
        }
    }
    Column {
        spacing: 5
        x: 460
        y: 420

        Slider {
            id: redSlider
            value: 0.0
            orientation: Qt.Horizontal
            onValueChanged: updateGradient()
        }

        Slider {
            id: greenSlider
            value: 0.0
            orientation: Qt.Horizontal
            onValueChanged: updateGradient()
        }

        Slider {
            id: blueSlider
            value: 0.0
            orientation: Qt.Horizontal
            onValueChanged: updateGradient()
        }
    }

    function updateGradient() {
        // Update the gradient based on the slider values
        // The gradient is defined in the Rectangle's gradient property.
    }

    // Grid
    Item {
        x: 150
        y: 100

        ListModel {
            id: listModel
            ListElement { page: "gear.qml"; iconSource: "gearIcon.jpg" }
            ListElement { page: "musicPlayer.qml"; iconSource: "musicPlayer.jpg" }
            ListElement { page: "video.qml"; iconSource: "video.jpg" }

        }

        GridView {
            id: gridView
            width:900
            height:300

            model: listModel
            cellHeight:300
            cellWidth: 300


            delegate: Rectangle {
                width: 120
                height: 120

                radius: 5

                Image {
                    source: iconSource
                    width: parent.width
                    height: parent.height
                    anchors.centerIn: parent
                }



                MouseArea {
                    anchors.fill: parent
                    onClicked: mainLoader.source = page
                }
            }
        }
    }
}

