import QtQuick 2.12
import QtQuick.Controls 2.12

import ChatBot 1.0

Page {
    id: root

    header: ToolBar {
        Label {
            text: qsTr("Topics")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }

    ListView {
        id: listView
        anchors.fill: parent
        topMargin: 48
        leftMargin: 48
        bottomMargin: 48
        rightMargin: 48
        spacing: 20
        model: SqlTopicModel {}
        delegate: ItemDelegate {
            text: model.name
            width: listView.width - listView.leftMargin - listView.rightMargin
            height: avatar.implicitHeight
            leftPadding: avatar.implicitWidth + 32
            onClicked: root.StackView.view.push("qrc:/ConversationPage.qml", { inConversationWith: model.name })

            Image {
                id: avatar
                source: "qrc:/resources/public/png/" + model.icon
            }
        }
    }
}
