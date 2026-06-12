/**
 * SPDX-FileCopyrightText: Year Author <author@domain.com>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */


import QtQuick.Controls as Controls
import QtQuick.Layouts as Layouts

import org.kde.kirigami as Kirigami
import org.kde.kcmutils as KCMUtils

import org.kde.private.kcm.kscreensystem as K

KCMUtils.SimpleKCM {
	Layouts.ColumnLayout{
	Kirigami.InlineMessage{
			id: revertMsg
			Layouts.Layout.fillWidth: true
			position: Kirigami.InlineMessage.Position.Header
			type: Kirigami.MessageType.Information
			text: i18n("Display configuration reverted")
			visible: true
			showCloseButton: true
		}

	Kirigami.FormLayout{
		Layouts.GridLayout{
			id: grid
			columns: 2
			Controls.Label{
				text:i18n("Apply system kscreen settings")
				Layouts.Layout.alignment: Qt.AlignRight
			}
			Controls.ComboBox{
				model: [ 
					i18n("Never"),
					i18n( "Only for new users"),
					i18n("All users")]
				
			}

			Controls.Label{
				horizontalAlignment: Text.AlignRight
				text:i18n("Use current settings as system settings")
				Layouts.Layout.alignment: Qt.AlignRight
			}
			Controls.Button{
				text: i18n("Update")	
				onClicked:{
					K.Miclase.saluda()
				}
			}


		}
		}
	}}


