import QtQuick 2.15
import QtQuick.Window 2.0

import mpv 1.0

Window {
    visible: true
    width: 400
    height: 300
    title: "Mediaclient"

	MpvObject {
      id: renderer
	  anchors.fill: parent
      
        MouseArea {
            anchors.fill: parent
            onClicked: renderer.command(["loadfile", "/home/chris/The Single Greatest Record in Trackmania History [8hrpj6tJ68Y].webm"])
        }
	}
}

