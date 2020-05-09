import QtQuick 2.12
import QtQuick.Controls 2.12
import QtWebView 1.1

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

    footer: ToolBar {
        id: toolBar
        Button {
            text: qsTr("Help")
            font.pixelSize: 14
            onClicked: popup.open()
        }
        Label {
            text: qsTr("Copyright Stoian Minaev <stoyan.minaev@gmail.com> 2020 ©")
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 10
            anchors.bottomMargin: 10
            font.pixelSize: 14
        }
    }

    Popup {
        id: popup
        height: parent.height
        width: parent.width
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
        contentChildren: WebView {
            anchors.fill: parent
            url: "qrc:/resources/public/sample-usage.html"
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
            onClicked:
                root.StackView.view.push(
                    "qrc:/ConversationPage.qml", {
                        inConversationWith: model.name,
                        topicId: model.id
                    })

            Image {
                id: avatar
                source: "qrc:/resources/public/png/" + model.icon
            }
        }
    }
}
