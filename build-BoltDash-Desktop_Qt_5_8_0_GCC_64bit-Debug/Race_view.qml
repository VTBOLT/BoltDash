import QtQuick 2.5
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0

Item {
    id: item
    signal toDebugSignal
    property alias needle: needle
    property alias myRot: myRot.angle
    property alias green_bar: green_bar.width
    //property alias qmlToDebug: qmlToDebug

    RowLayout {
        antialiasing: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top
    }

    Image {
        id: dial
        x: 0
        y: 0
        width: 1024
        height: 600
        fillMode: Image.PreserveAspectFit
        antialiasing: true
        source: "../images/dash_background_with_meter.png"
    }

        /*Button {
            id: qmlToDebug
            text: "To Debug Screen"
            onClicked: item.toDebugSignal()
        }*/

    Image {
        id: needle
        x: 248
        y: 298
        width: 526
        height: 143
        fillMode: Image.PreserveAspectFit
        antialiasing: true
        z: 1
        source: "../images/needle_w_green_dot.png"

        transform: Rotation{
            id: myRot
            origin.x: 263
            origin.y: 71.5
            angle: 0
        }
        function setRotation (angle) {
            text_test: text = angle
        }
        MouseArea{
            width: needle.width
            height: needle.height
            onClicked: item.toDebugSignal()
            //onClicked: console.log("Mouse Area Clicked!")
        }
      }

        Image {
            id: battery
            x: 0
            y: 0
            z: 3
            width: 1024
            height: 600
            fillMode: Image.PreserveAspectFit
            antialiasing: true
            source: "../images/battery_sized_to_fit_screen.png"

        }

        //put rectangle here
        Rectangle {
            id: green_bar
            color: "#39B54A"
            x: 255
            y: 482
            z: 2
            width: 515 // max = 515
            height: 75
            antialiasing: true
        }
}
