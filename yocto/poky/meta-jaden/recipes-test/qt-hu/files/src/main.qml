import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id:root
    width: 1024
    height: 600
    visible: true
    color: "black"

    StackView{
        id:stackview
        initialItem: "/home.qml"
    }
}
