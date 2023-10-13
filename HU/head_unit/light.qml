import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Ambient Lighting Control"

    Rectangle {
        width: parent.width
        height: parent.height
        color: Qt.rgba(redSlider.value, greenSlider.value, blueSlider.value, opacitySlider.value)

        Column {
            spacing: 10
            anchors.centerIn: parent

            Slider {
                id: redSlider
                value: 0.5 // Initial value (range: 0.0 to 1.0)
                orientation: Qt.Horizontal
                onValueChanged: updateColor()
            }

            Slider {
                id: greenSlider
                value: 0.5 // Initial value (range: 0.0 to 1.0)
                orientation: Qt.Horizontal
                onValueChanged: updateColor()
            }

            Slider {
                id: blueSlider
                value: 0.5 // Initial value (range: 0.0 to 1.0)
                orientation: Qt.Horizontal
                onValueChanged: updateColor()
            }

            Slider {
                id: opacitySlider
                value: 1.0 // Initial value (range: 0.0 to 1.0)
                orientation: Qt.Horizontal
                onValueChanged: updateColor()
            }
        }
    }

    function updateColor() {
        // Update the color and opacity based on the slider values
        ambientLight.color = Qt.rgba(redSlider.value, greenSlider.value, blueSlider.value, opacitySlider.value);
    }
}
