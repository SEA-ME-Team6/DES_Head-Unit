import QtQuick 2.15
import QtPositioning 5.12
import QtLocation 5.12


ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Mapbox GL Example"

    // Add MapboxMap to the application window
    MapboxMap {
        id: map
        anchors.fill: parent
        accessToken: "pk.eyJ1IjoiZGFla3l1bmc5OTA1IiwiYSI6ImNsbmVmZmkwdTBkbHcya3A0YjhpYjc5b3oifQ.3WCWSwTO2Z2TOjRzdvuB-g" // Replace with your Mapbox access token

        // Set the initial center and zoom level
        center {
            latitude: 40.7128 // Replace with your desired latitude
            longitude: -74.0060 // Replace with your desired longitude
        }
        zoomLevel: 10 // Adjust the zoom level as needed

        onMapLoaded: {
            // Map has loaded, you can add custom actions here if needed
        }
    }
}
