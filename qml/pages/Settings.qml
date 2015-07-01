import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: settingsPage

    PageHeader {
        title: "Settings"
    }

    Rectangle {
        anchors.topMargin: 300
        anchors.fill: parent

        width: parent.width - 30

        color: "transparent"

        Label {
            id: labelIPAdress
            text: "IP Adress :"
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            color: "steelblue"
            font.pointSize: 20
        }

        TextInput {
            id: editIP
            text: "192.168.0.3"
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: labelIPAdress.bottom
            anchors.topMargin: 20

            onAccepted: {
                // Baisser le clavier :
                focus = false
            }
        }

        Button {
            anchors.top: editIP.bottom
            anchors.topMargin: 50
            anchors.horizontalCenter: parent.horizontalCenter

            text: "OK"
            onClicked: changeAdressIP(editIP.text)
        }
    }

    function changeAdressIP(value) {
        console.log(value)
        pageStack.pop()
    }
}
