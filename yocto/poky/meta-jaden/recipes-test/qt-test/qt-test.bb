DESCRIPTION = "QT Test Application"
LICENSE = "CLOSED"

inherit cmake_qt5
DEPENDS = " qtbase qtquickcontrols2"

SRC_URI += "file://CMakeLists.txt \
            file://CMakeLists.txt.user \
            file://main.cpp \
            file://main.qml \
            file://qml.qrc"

S = "${WORKDIR}"

do_install(){
    install -d ${D}${bindir}
    install -m 0755 test1003 ${D}${bindir}
}

