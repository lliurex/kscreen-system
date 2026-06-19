/**
 * SPDX-FileCopyrightText: Year Author <author@domain.com>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "kscreensystem.h"
#include <pwd.h>
#include <QDebug>
#include <KPluginFactory>
#include <QString>
#include <QDir>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusReply>

K_PLUGIN_CLASS_WITH_JSON(KScreenSystemSettings, "kcm_kscreensystem.json")

/**
KScreenSystemSettingsHandler::KScreenSystemSettingsHandler(QObject *parent)
	:QObject(parent)
{

}

void KScreenSystemSettingsHandler::test_function(){
	qDebug() << "hello world";
}

*/
/*
 *     
 *
 */

KScreenSystemSettings::KScreenSystemSettings(QObject *parent, const KPluginMetaData &data)
    : KQuickConfigModule(parent, data),
      m_iface(
		    QStringLiteral("net.lliurex.KScreenSystem"),
		    QStringLiteral("/net/lliurex/KScreenSystem"),
		    QStringLiteral("net.lliurex.KScreenSystem"),
		    QDBusConnection::systemBus())
{
    //KScreenSystemSettingsHandler *handler = new KScreenSystemSettingsHandler(parent);
    //qmlRegisterSingletonInstance<KScreenSystemSettingsHandler>("org.kde.private.kcm.kscreensystem",1,0,"KScreenSystemSettingsHandler",handler);
    setButtons( Apply );
}

void KScreenSystemSettings::saveSettingsFile(){
	qDebug() << "save settings file";

	struct passwd* pw = getpwuid(getuid());
	QString kwinout_path = QDir(QString::fromUtf8(pw->pw_dir)).filePath(QStringLiteral(".config/kwinoutputconfig.json"));

	QDBusReply<bool> reply = m_iface.call(QStringLiteral("UpdateGlobalConfig"), kwinout_path );
	if ( reply.isValid() ){
		if (reply.value()){
			Q_EMIT updatedGlobalConfig();
		}
	}
	else{
		qDebug() << "error en la peticion de dbus";
		qDebug() << reply.error();
	}
}

void KScreenSystemSettings::changeWorkingMode(int index){
	currentWorkingMode = index;
	setNeedsSave(true);
}

void KScreenSystemSettings::save(){
	bool allUsers = false;
	if (currentWorkingMode == 0){
		QDBusReply<bool> reply = m_iface.call(QStringLiteral("RemoveGlobalConfig"));
		if (reply.isValid()) Q_EMIT saveConfig();
		else setNeedsSave(true);
	}
	else{
		QDBusReply<bool> reply = m_iface.call(QStringLiteral("ExistsGlobalConfig"));
		if (reply.isValid()){
			if(!reply.value()){
				Q_EMIT errorNotExistsFile();
			}
			else{
				if (currentWorkingMode == 2) allUsers= true; 
				reply = m_iface.call(QStringLiteral("SetGlobalConfig"), allUsers );
				if (reply.isValid()){
					if (reply.value()){
						Q_EMIT saveConfig();
					}
					qDebug() << reply.value();
				}
				else qDebug() << reply.error();
			}
		}
	}
}

void KScreenSystemSettings::load(){
	QDBusReply<int> reply = m_iface.call(QStringLiteral("StatusGlobalConfig"));
	if (reply.isValid()){
		currentWorkingMode = reply.value();
	}
	else{
		qDebug() << "falla?";
		qDebug() << reply.error();
	}

	Q_EMIT loadValues(currentWorkingMode);
	setNeedsSave(false);
}

#include "kscreensystem.moc"
