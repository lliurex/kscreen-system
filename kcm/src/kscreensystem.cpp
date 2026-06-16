/**
 * SPDX-FileCopyrightText: Year Author <author@domain.com>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "kscreensystem.h"
#include <QDebug>
#include <KPluginFactory>

#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusPendingReply>

K_PLUGIN_CLASS_WITH_JSON(KScreenSystemSettings, "kcm_kscreensystem.json")

KScreenSystemSettingsHandler::KScreenSystemSettingsHandler(QObject *parent)
	:QObject(parent)
{

}

void KScreenSystemSettingsHandler::test_function(){
	qDebug() << "hello world";
}


KScreenSystemSettings::KScreenSystemSettings(QObject *parent, const KPluginMetaData &data)
    : KQuickConfigModule(parent, data)
{
    //KScreenSystemSettingsHandler *handler = new KScreenSystemSettingsHandler(parent);
    //qmlRegisterSingletonInstance<KScreenSystemSettingsHandler>("org.kde.private.kcm.kscreensystem",1,0,"KScreenSystemSettingsHandler",handler);
    setButtons( Apply | Default);
}

void KScreenSystemSettings::saveSettingsFile(){
	qDebug() << "save settings file";
	// call dbus function to save file
	setNeedsSave(true);
}

void KScreenSystemSettings::changeWorkingMode(int index){
	currentWorkingMode = index;
	setNeedsSave(true);
}

void KScreenSystemSettings::defaults(){
	qDebug() << "set default values";
	Q_EMIT defaultValues();
	setNeedsSave(true);
}

void KScreenSystemSettings::save(){
	qDebug() << currentWorkingMode;
	// Set by DBUS 
	setNeedsSave(true);
}

void KScreenSystemSettings::load(){
	qDebug() << "restore button";
	// Get info from DBUS
	Q_EMIT loadValues(2);
	setNeedsSave(false);
}

#include "kscreensystem.moc"
