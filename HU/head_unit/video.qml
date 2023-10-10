// VideoPlayerWithPlaylist.qml

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15

Item {
    width:1024
    height: 600

    property int currentVideoIndex: -1
    property bool isPlaying: false
    Button{
        id:backButton2
        text:"Back"
        onClicked: mainLoader.source="stackViewPage.qml"
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
            right: parent.right
            margins: 40

        }



        //onClicked: mainLoader.source="stackViewPage.qml"

    }
    ListView {
        id: playlistView
        width: 100
        height: parent.height
        model: playlistModel
        currentIndex: currentVideoIndex

        delegate: Item {
            width: parent.width
            height: 50

            Rectangle {
                color: (playlistView.currentIndex === index) ? "lightblue" : "transparent"
                width: parent.width
                height: 50

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mediaPlayer.stop()
                        mediaPlayer.source = model.source
                        mediaPlayer.play()
                        currentVideoIndex = index
                        isPlaying = true
                    }
                }

                Text {
                    text: model.title
                    anchors.centerIn: parent
                    color: "white"
                }
            }
        }
    }

    VideoOutput {
        height:300

        id: videoOutput
        anchors.fill: parent
        source: mediaPlayer
    }

    MediaPlayer {
        id: mediaPlayer
        autoPlay: false

        onStopped: {
            if (!isStopped && currentVideoIndex >= 0 && currentVideoIndex < playlistModel.count && isPlaying) {
                currentVideoIndex++;
                playVideo();
            } else {
                isStopped = false;
            }
        }
    }

    ListModel {
        id: playlistModel

        ListElement { title: "Video 1"; source: "video1.mp4" }
        ListElement { title: "Video 2"; source: "video4.mp4" }
        ListElement { title: "Video 3"; source: "video3.mp4" }
        // Add more videos as needed
    }

    Row {
        anchors.bottom: parent.bottom
        x:400
        spacing: 10

        Button {
            width: 50
            height: 50

            Image {
                    source: "b.jpg"
                    width: parent.width
                    height: parent.height
                    MouseArea {
                        anchors.fill: parent
                        onClicked: playPreviousVideo()
                    }
                }
            onClicked: playPreviousVideo()
        }

        Button {
            width: 50
            height: 50
            Image {
                    source: isPlaying ? "ps.jpg" : "p.jpg"
                    width: parent.width
                    height: parent.height
                    MouseArea {
                        anchors.fill: parent
                        onClicked: togglePlayPause()
                    }
                }
            onClicked: togglePlayPause()
        }

        Button {
            width: 50
            height: 50

            Image {
                    source: "s.jpg"
                    width: parent.width
                    height: parent.height
                    MouseArea {
                        anchors.fill: parent
                        onClicked: stopVideo()
                    }
                }
            onClicked: stopVideo()
        }

        Button {
            id:next
            width: 50
            height: 50

            Image {
                    source: "f.jpg"
                    width: parent.width
                    height: parent.height
                    MouseArea {
                        anchors.fill: parent
                        onClicked: playNextVideo()
                    }
                }
            onClicked: playNextVideo()
        }
    }

    function playVideo() {
        if (currentVideoIndex >= 0 && currentVideoIndex < playlistModel.count) {
            mediaPlayer.source = playlistModel.get(currentVideoIndex).source;
            mediaPlayer.play();
            isPlaying = true;
        }
    }

    function togglePlayPause() {
        if (isPlaying) {
            mediaPlayer.pause();
            isPlaying = false;
        } else {
            mediaPlayer.play();
            isPlaying = true;
        }
    }

    function stopVideo() {
        mediaPlayer.stop();
        isPlaying = false;
        isStopped = true; // Set isStopped to true when explicitly stopping the video
    }



    function playNextVideo() {
        if (currentVideoIndex < playlistModel.count - 1) {
            currentVideoIndex++;
            playVideo();
        }
    }

    function playPreviousVideo() {
        if (currentVideoIndex > 0) {
            currentVideoIndex--;
            playVideo();
        }
    }
    Slider {
            id: volumeSlider
            anchors.left:parent.left
            anchors.bottom: parent.bottom
            width: 350
            from: 0
            to: 1
            value: mediaPlayer.volume
            onValueChanged: mediaPlayer.volume = value
        }
}
