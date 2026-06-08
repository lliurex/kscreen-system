/**
 * SPDX-FileCopyrightText: Year Author <author@domain.com>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "kscreen-system.h"

#include <KPluginFactory>

K_PLUGIN_CLASS_WITH_JSON(KScreenSystemSettings, "kcm_kscreen-system.json")

KScreenSystemSettings::KScreenSystemSettings(QObject *parent, const KPluginMetaData &data)
    : KQuickConfigModule(parent, data)
{
    setButtons(Help | Apply | Default);}

#include "kscreensystem.moc"
