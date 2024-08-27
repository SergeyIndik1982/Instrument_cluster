import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import InstrumentCluster 1.0

ApplicationWindow {
    visible: true
    width: 1280
    height: 400
    title: "Instrument Cluster"

    Component.onCompleted: {
        if (!speedUpdateManager) {
            console.error("Failed to load SpeedUpdateManager");
        }
    }

    Rectangle {
        width: 1280
        height: 400
        color: "black"

        FilterButtons {
            id: filterButtons
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 10
            anchors.leftMargin: 10
        }

        Speedometer {
            id: speedometer
            anchors.centerIn: parent
            speed: 0
        }

        Connections {
            target: speedUpdateManager
            onSpeedUpdated: speed => {
                speedometer.speed = speed
            }
        }

        Text {
            id: batteryLevelText
            text: "Battery: " + batteryChecker.batteryLevel + "%"
            color: "white"
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.topMargin: 10
            anchors.rightMargin: 10
            font.pixelSize: 20
        }

    }
}
