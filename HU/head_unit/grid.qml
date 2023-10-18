import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12


Item {
    visible: true
    width: 1024
    height: 600



        Column {
            x:5
            y:20
            anchors.left: parent.left
            spacing: 10
            Button {
                //text: "P"

                Image {
                    width: parent.width
                    height: parent.height
                    source: "pg.jpg"
                               }

                /*contentItem: Text {
                        text: parent.text
                        color: "white" // Set the text color to red
                        font.pixelSize: 50
                        horizontalAlignment: Text.AlignHCenter // Center text horizontally
                        verticalAlignment: Text.AlignVCenter // Center text vertically
                                   }*/
                width: 130 // Set the width of the button
                height:130 // Set the height of the button

                onClicked: {
                    gearState = "Park"
                }
                background: Rectangle {
                    color: gearState === "Park" ? "green" : "black"
                    radius: 5
                }
            }

            Button {
                //text: "P"

                Image {
                    width: parent.width
                    height: parent.height
                    source: "rg.jpg"
                               }

                /*contentItem: Text {
                        text: parent.text
                        color: "white" // Set the text color to red
                        font.pixelSize: 50
                        horizontalAlignment: Text.AlignHCenter // Center text horizontally
                        verticalAlignment: Text.AlignVCenter // Center text vertically
                                   }*/
                width: 130 // Set the width of the button
                height:130 // Set the height of the button

                onClicked: {
                    gearState = "Reverse"
                }
                background: Rectangle {
                    color: gearState === "Reverse" ? "green" : "black"
                    radius: 5
                }
            }

            Button {
                //text: "P"

                Image {
                    width: parent.width
                    height: parent.height
                    source: "NG.jpg"
                               }

                /*contentItem: Text {
                        text: parent.text
                        color: "white" // Set the text color to red
                        font.pixelSize: 50
                        horizontalAlignment: Text.AlignHCenter // Center text horizontally
                        verticalAlignment: Text.AlignVCenter // Center text vertically
                                   }*/
                width: 130 // Set the width of the button
                height:130 // Set the height of the button

                onClicked: {
                    gearState = "Neutral"
                }
                background: Rectangle {
                    color: gearState === "Neutral" ? "green" : "black"
                    radius: 5
                }
            }

            Button {
                //text: "P"

                Image {
                    width: parent.width
                    height: parent.height
                    source: "dg.jpg"
                               }

                /*contentItem: Text {
                        text: parent.text
                        color: "white" // Set the text color to red
                        font.pixelSize: 50
                        horizontalAlignment: Text.AlignHCenter // Center text horizontally
                        verticalAlignment: Text.AlignVCenter // Center text vertically
                                   }*/
                width: 130 // Set the width of the button
                height:130 // Set the height of the button
                font.pixelSize: 18 // Set the font size of the button text
                onClicked: {
                    gearState = "Drive"
                }
                background: Rectangle {
                    color: gearState === "Drive" ? "green" : "black"
                    radius: 5
                }

            }
        }


    property string gearState: "Park"



        ListModel {
            id: listModel
            ListElement { page: "light.qml"; iconSource: "light.jpg" }
            ListElement { page: "musicPlayer.qml"; iconSource: "musicPlayer.jpg" }
            ListElement { page: "video.qml"; iconSource: "video.jpg" }

        }

        GridView {
            id: gridView
            x:400
            y:200
            width:600
            height:300

            model: listModel
            cellHeight:300
            cellWidth: 200


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

