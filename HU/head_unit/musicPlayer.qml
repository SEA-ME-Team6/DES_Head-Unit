import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.0
import USBManager 1.0
import Qt.labs.folderlistmodel 2.1

Item {
    id: music
    visible: true
    width: 1024
    height: 600

    Image {
        id: backgroundImage1
        anchors.fill: parent
        source: "background.png"
    }
    Button {
        id: loadSongsButton
        text: "Load Songs from USB"
        anchors.right: parent.right

        onClicked: {
            // Specify the folder path to your USB drive here
            var usbDrivePath =  "file:///D:/media"; // Change to your USB drive path

            // Set the folderListModel to the USB drive path
            folderListModel.folder = usbDrivePath;
            folderListModel.nameFilters = ["*.mp3"];
        }
    }






    // USBManager is defined separately
    USBManager {
        id: usbManager

    }
    Connections {
        target: usbManager
        function onUsbInserted() {
            console.log("USB Inserted");
            Qt.debug("USB device detected");

                    // Add the songs to the playlistModel automatically
                    for (var i = 0; i < usbManager.mp3Files.length; i++) {
                        var musicFile = usbManager.mp3Files[i];
                        var fileName = musicFile.substring(musicFile.lastIndexOf("/") + 1);
                        playlistModel.append({ title: fileName, source: musicFile });
                    }
            // Rest of your code for USB insertion
        }

        function onUsbRemoved() {
            console.log("USB Removed");
            // Rest of your code for USB removal
        }
    }
    FolderListModel {
        id: folderListModel
        nameFilters: ["*.mp3"]  // Specify the file filter for songs
        folder: "" // Leave it empty for now, we'll set it in the button's handler

        onFolderChanged: {
            if (folderListModel.folder !== "") {
                playlistModel.clear(); // Clear the existing list
                for (var i = 0; i < folderListModel.count; i++) {
                    var source = folderListModel.get(i, "filePath");
                    var title = source.substring(source.lastIndexOf("/") + 1);


                    playlistModel.append({ title: title, source: source });
                }
            }
        }
    }





    Button {
        id: backButton3
        width: 100
        height: 100
        Image {
            width: parent.width
            height: parent.height
            source: "back.jpg"
        }
        onClicked: mainLoader.source = "stackViewPage.qml"
        anchors {
            bottom: parent.bottom
            right: parent.right
            margins: 40
        }
    }

    ListView {
        id: playlistView
        width: parent.width / 3
        height: parent.height / 2
        model: ListModel {
            id: playlistModel


        }
        delegate: Item {
            x: 100
            width: 924
            height: 50
            Rectangle {
                width: parent.width
                height: 50
                color: "lightblue"
                border.color: "blue"
                Text {
                    anchors.centerIn: parent
                    text: model.title
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mediaPlayer.stop()
                        mediaPlayer.source = model.source
                        mediaPlayer.play()
                        playlistView.currentIndex = index
                    }
                }
            }
        }
    }

    MediaPlayer {
        id: mediaPlayer
        autoPlay: false
    }


   /* FileDialog {

        id: fileDialog
        title: "Select Songs"
        folder: "file:///D:/"  // Set your initial folder here

        onAccepted: {
            console.log("Folder path1: " + folder);
            var files = fileDialog.fileUrls;
            console.log("Folder path2: " + files);
            for (var i = 0; i < files.length; i++) {

                var selectedFile = files[i].toString();
                var fileName = selectedFile.substring(selectedFile.lastIndexOf("/") + 1);
                var isDuplicate = false;
                for (var j = 0; j < playlistModel.count; j++) {
                    if (playlistModel.get(j).source === selectedFile) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    playlistModel.append({ title: fileName, source: selectedFile });
                }
            }
        }
        onRejected: {
            // User canceled the file selection
        }
    }*/

    Slider {
        id: s1
        x: 250
        y: 400
        width: 600
        from: 0
        to: mediaPlayer.duration
        value: mediaPlayer.position
        onValueChanged: {
            mediaPlayer.position = value
        }
    }

    Column {
        anchors {
            bottom: parent.bottom
            left: playlistView.right
            right: parent.right
        }
        Row {
            spacing: 10
            Button {
                width: 100
                height: 100
                Image {
                    width: parent.width
                    height: parent.height
                    source: "b.jpg"
                }
                onClicked: {
                    var newIndex = playlistView.currentIndex - 1;
                    if (newIndex >= 0) {
                        mediaPlayer.stop();
                        mediaPlayer.source = playlistModel.get(newIndex).source;
                        mediaPlayer.play();
                        playlistView.currentIndex = newIndex;
                    }
                }
            }
            Button {
                width: 100
                height: 100
                Image {
                    width: parent.width
                    height: parent.height
                    source: mediaPlayer.playbackState === MediaPlayer.PlayingState ? "ps.jpg" : "p.jpg"
                }
                onClicked: {
                    if (mediaPlayer.playbackState === MediaPlayer.PlayingState) {
                        mediaPlayer.pause();
                    } else {
                        mediaPlayer.play();
                    }
                }
            }
            Button {
                width: 100
                height: 100
                Image {
                    width: parent.width
                    height: parent.height
                    source: "s.jpg"
                }
                onClicked: mediaPlayer.stop();
            }
            Button {
                id: next
                width: 100
                height: 100
                Image {
                    width: parent.width
                    height: parent.height
                    source: "f.jpg"
                }
                onClicked: {
                    var newIndex = playlistView.currentIndex + 1;
                    if (newIndex < playlistModel.count) {
                        mediaPlayer.stop();
                        mediaPlayer.source = playlistModel.get(newIndex).source;
                        mediaPlayer.play();
                        playlistView.currentIndex = newIndex;
                    }
                }
            }
        }

        Slider {
            id: s2
            width: 430
            from: 0
            to: 1
            value: mediaPlayer.volume
            onValueChanged: {
                mediaPlayer.volume = value
            }
        }
    }
}
