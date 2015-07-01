import QtQuick 2.0
import Sailfish.Silica 1.0
import CommandLib 1.0


Page {
    id: detailPage
    property int index
    property Command command

    PageHeader {
        title: command.title
    }

    Rectangle {
        anchors.topMargin: 300
        anchors.fill: parent

        width: parent.width - 30

        color: "transparent"

        Label {
            id: labelCommand
            text: "Command to execute :"
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            color: "steelblue"
            font.pointSize: 20
        }

        TextInput {
            id: editCommand
            text: command.commandTxt
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: labelCommand.bottom
            anchors.topMargin: 20

            onAccepted: {
                // Baisser le clavier :
                focus = false
            }
        }

        Button {
            anchors.top: editCommand.bottom
            anchors.topMargin: 50
            anchors.horizontalCenter: parent.horizontalCenter

            text: "Modify"
            onClicked: modifyCommand(editCommand.text)
        }
    }

    function modifyCommand(value) {
        command.setCommandTxt(value)
        pageStack.pop()
    }
}
