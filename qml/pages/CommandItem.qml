import QtQuick 2.0
import Sailfish.Silica 1.0

ListItem{
    id: commandItem

    Label {
        text: title;
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 100
    }

    onClicked: {
        console.log(commandModel.getCommand(index))
        commandModel.executeCommand(commandModel.getCommand(index))
    }

    menu: ContextMenu{
        MenuItem{
            text: "Edit"
            onClicked: pageStack.push(Qt.resolvedUrl("CommandDetail.qml"), {index: index, command: commandModel.getCommand(index)})
        }
        MenuItem{
            text: "Delete"
            onClicked: remove()
        }
    }

    function remove(){
        remorseAction("Deleting",function(){
            //listView.model.removeRows(index, 0)
            commandModel.removeRows(index, 0)
        })
    }

}
