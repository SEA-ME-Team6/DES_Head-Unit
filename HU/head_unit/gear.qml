import QtQuick 2.15
import QtQuick.Controls 2.15

Item {



    Rectangle {

        width: parent.width
        height: parent.height
        Image{
               id:gearImage
               anchors.fill:root
               source: "background.png"
               }
        Button{
            id:backButton
            text:"Back"
            contentItem: Text {
                    text: parent.text
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter // Center text horizontally
                    verticalAlignment: Text.AlignVCenter // Center text vertically
                }
            background: Rectangle{
                color:"black"
            }

            anchors{
                bottom:parent.bottom
                left: parent.left
                margins: 40

            }



            onClicked: mainLoader.source="stackViewPage.qml"

        }

        Column {
            anchors.centerIn: parent
            spacing: 10

            Text {
                text: "Select Gear:"
                color: "white"
                font.pixelSize: 38
                horizontalAlignment: Text.AlignHCenter
            }


            Button {
                text: "P"
                contentItem: Text {
                        text: parent.text
                        color: "white" // Set the text color to red
                        font.pixelSize: 50
                        horizontalAlignment: Text.AlignHCenter // Center text horizontally
                        verticalAlignment: Text.AlignVCenter // Center text vertically
                                   }
                width: 100 // Set the width of the button
                height:100 // Set the height of the button

                onClicked: {
                    gearState = "Park"
                }
                background: Rectangle {
                    color: gearState === "Park" ? "green" : "black"
                    radius: 5
                }
            }

            Button {
                text: "R"
                contentItem: Text {
                        text: parent.text
                        color: "white" // Set the text color to red
                        font.pixelSize: 50
                        horizontalAlignment: Text.AlignHCenter // Center text horizontally
                        verticalAlignment: Text.AlignVCenter // Center text vertically
                    }
                width: 100 // Set the width of the button
                height:100 // Set the height of the button

                onClicked: {
                    gearState = "Reverse"
                }
                background: Rectangle {
                    color: gearState === "Reverse" ? "green" : "black"
                    radius: 5
                }
            }

            Button {
                text: "N"
                contentItem: Text {
                        text: parent.text
                        color: "white" // Set the text color to red
                        font.pixelSize: 50
                        horizontalAlignment: Text.AlignHCenter // Center text horizontally
                        verticalAlignment: Text.AlignVCenter // Center text vertically
                                   }
                width: 100 // Set the width of the button
                height:100 // Set the height of the button

                onClicked: {
                    gearState = "Neutral"
                }
                background: Rectangle {
                    color: gearState === "Neutral" ? "green" : "black"
                    radius: 5
                }
            }

            Button {
                text: "D"
                contentItem: Text {
                        text: parent.text
                        color: "white" // Set the text color to red
                        font.pixelSize: 50
                        horizontalAlignment: Text.AlignHCenter // Center text horizontally
                        verticalAlignment: Text.AlignVCenter // Center text vertically
                                   }
                width: 100 // Set the width of the button
                height:100 // Set the height of the button
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
    }

    property string gearState: "Park"
}