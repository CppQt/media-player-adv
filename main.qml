import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.12

Window {
    visible: true
    width: 320
    height: videooutput.height + playButton.height
    title: qsTr("Hello World")

    VideoOutput {
        id: videooutput

        width: 320
        height: 240

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        source: mediaplayer
    }

    Button {
        id: playButton
        anchors.top: videooutput.bottom
        anchors.left: videooutput.left
        text: qsTr("Play")
        onClicked: {
            mediaplayer.play()
        }
    }

    Button {
        id: stopButton
        anchors.top: videooutput.bottom
        anchors.right: videooutput.right
        text: qsTr("Stop")
        onClicked: {
            mediaplayer.stop()
        }
    }
}
