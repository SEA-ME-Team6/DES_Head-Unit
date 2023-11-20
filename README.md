# DES_Head-Unit
Head Unit Project Documentation
Overview
The Head Unit project is a Qt-based application designed for in-vehicle entertainment systems. It includes features such as USB media scanning, color customization, and various control options.

## Components
1. USBManager Class
The USBManager class handles USB-related operations, including scanning for USB drives, mounting, unmounting, and loading media files.

## Properties
 fileList: List of media files available on the connected USB drive.
 usbDrivePath: Path of the mounted USB drive.
## Signals
 usbInserted(): Signal emitted when a USB drive is inserted.
 usbRemoved(): Signal emitted when a USB drive is removed.
 fileListChanged(): Signal emitted when the list of media files changes.
## Methods
 startUSBScan(): Initiates the USB drive scanning process.
 mountUSB(): Mounts the USB drive.
 isUSBDriveMounted(): Checks if the USB drive is mounted.
 loadSongsFromUSB(): Loads media files from the USB drive.
 findUSBDevice(): Finds the device path of the connected USB drive.
 umountUSB(): Unmounts the USB drive.
 removeUsbDirectory(): Removes the USB mount directory.
## 2. Color Customization
The application provides sliders for customizing the background color of the interface.

## 3. Main QML Interface
The main QML interface includes a grid layout for different functionalities, such as media playback controls and a playlist view.

## Controls
Start USB Scan Button: Initiates the USB scanning process.
Playlist View: Displays the list of available media files.
Media Playback Controls: Play, pause, stop, next, previous buttons.
Volume Slider: Controls the volume level.
## 4. Main Application
The main application file (main.cpp) initializes the application, registers the USBManager class with QML, and sets up the initial QML file.

## Usage
Start the application.
Use the Start USB Scan button to detect and mount the connected USB drive.
Customize the background color using the color sliders.
Navigate through the playlist and control media playback.

## Dependencies
Qt version 5.15 or higher.

## Building and Running
Open the project in Qt Creator.
Configure the build settings.
Build and run the application on the target platform.

## Notes
Ensure that the required multimedia components are installed on the target system.

## Future Enhancements
Implement support for additional media formats.
Enhance the user interface for a better user experience.




