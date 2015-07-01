import QtQuick 2.0
import Sailfish.Silica 1.0
import CommandModelLib 1.0
import CommandLib 1.0

Page {
    id: newCommandPage

    property CommandModel commandModel

    PageHeader {
        title: "New Command"
    }

    Rectangle {
        anchors.topMargin: 300
        anchors.fill: parent

        width: parent.width - 30

        color: "transparent"

        Label {
            id: labelCommandTitle
            text: "Title of the command :"
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            color: "steelblue"
            font.pointSize: 20
        }

        TextInput {
            id: newCommandTitle
            text: "My Title"
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: labelCommandTitle.bottom
            anchors.topMargin: 20

            onAccepted: {
                focus = false
            }
        }

        Label {
            id: labelCommand
            text: "Command to execute :"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: newCommandTitle.bottom
            anchors.topMargin: 50

            font.bold: true
            color: "steelblue"
            font.pointSize: 20
        }

        TextInput {
            id: newCommandText
            anchors.top: labelCommand.bottom
            anchors.topMargin: 20
            text: "My Command (ex: ls -a)"
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter

            onAccepted: {
                focus = false
            }
        }

        Button {
            anchors.top: newCommandText.bottom
            anchors.topMargin: 100
            anchors.horizontalCenter: parent.horizontalCenter

            text: "Add"
            onClicked: validate()
        }
    }

    function validate(){
        commandModel.addCommand(newCommandTitle.text, newCommandText.text);
        pageStack.pop();
    }
}
