/**
 * SPDX-FileCopyrightText: Year Author <author@domain.com>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "kscreensystem.h"
#include <QDebug>
#include <KPluginFactory>
K_PLUGIN_CLASS_WITH_JSON(KScreenSystemSettings, "kcm_kscreensystem.json")

KScreenSystemSettingsHandler::KScreenSystemSettingsHandler(QObject *parent)
	:QObject(parent)
{

}

void KScreenSystemSettingsHandler::saluda(){
	qCritical() << "Hola que tal";
}


KScreenSystemSettings::KScreenSystemSettings(QObject *parent, const KPluginMetaData &data)
    : KQuickConfigModule(parent, data)
{
    KScreenSystemSettingsHandler *handler = new KScreenSystemSettingsHandler(parent);
    setButtons( Apply | Default);
    //qmlRegisterType<KScreenSystemSettingsHandler>("org.kde.private.kcm.kscreensystem",1,0,"Miclase");

    qmlRegisterSingletonInstance<KScreenSystemSettingsHandler>("org.kde.private.kcm.kscreensystem",1,0,"Miclase",handler);
}



#include "kscreensystem.moc"
