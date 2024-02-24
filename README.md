# DES_Head-Unit

## Preview
![IMG_5692 중간](https://github.com/SEA-ME-Team6/DES_Head-Unit/assets/106136905/0da57d5a-7234-4e59-b969-6b20ccee820f)


## Introduction

This project aims to develop a Head Unit Qt application running on a Raspberry Pi (RPi) alongside the previously developed PiRacer Instrument Cluster Qt application (was developed to display real-time speed data from the speed sensor on the car).  The project uses Yocto as the build system for the RPi.

The head unit application is a critical component of the in-car infotainment system, providing a user interface for various functions, such as navigation system, ambient lighting, gear selection, and media playback.


You can check with each repository

### [app-ipi](https://github.com/SEA-ME-Team6/app-ipi/tree/main): applications for this project 
### [meta-ipi](https://github.com/SEA-ME-Team6/meta-ipi/tree/main): custom layer for yocto


## Key Concepts
### SOME/IP(Scalable service-Oriented MiddlewarE over IP):
SOME/IP is a protocol designed based on SOA (Service Oriented Architecture). Each service is divided into a provider (Server) that provides a service and a consumer (Client) that uses the service. SOME/IP is a communication protocol widely used in automotive and embedded systems for efficient SOA

### Qt Application Manager
Qt Application Manager, based on the Qt framework, is a tool for managing applications in a multi-process, multi-application environment. It ensures stable execution and management of applications in embedded systems.
In our project, Qt Application Manager effectively handles GUI and various applications.

### Yocto
Yocto is an open-source project for building embedded Linux systems. Utilizing custom recipes, configurations, and layers, Yocto generates optimized images tailored to specific hardware platforms.
In our project, Yocto is instrumental in configuring the system, integrating packages, and applications to deliver an optimal embedded solution.

## Head Unit


### Gear Selection

- **Current Gear Display:** Clearly indicates the current gear.
- **Manual Selection:** Able to switch between different gear modes
  
### Ambient Lighting

- **Color Palette:** Select from a predefined color palette or customize ambient lighting colors.

### Head Lamp
- **Head Lamp Control:** Control the head lamp through gamepad

### Media App

- **Start USB Scan** Initiates the USB scanning process.
- **Playlist View:** Displays the list of available songs with relevant details.
- **Playback Controls:** Play, pause, next, previous buttons for music control.
- **Volume Control:** Slider for adjusting media volume.


### Qt Framework

The GUI is developed using the Qt framework, leveraging QML for declarative UI design and interaction. QObject-based C++ classes handle backend logic and communication with other components.

## Hardware Architecture
![HW_architecture drawio (1)](https://github.com/SEA-ME-Team6/DES_Head-Unit/assets/106136905/0fed61fa-2bc6-4965-886b-cb55bad98cd1)


