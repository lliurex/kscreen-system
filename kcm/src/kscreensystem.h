/**
 * SPDX-FileCopyrightText: Year Author <author@domain.com>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once
#include <KQuickConfigModule>

class KScreenSystemSettingsHandler: public QObject{
    Q_OBJECT
    public:
	explicit KScreenSystemSettingsHandler(QObject *parent);
	Q_INVOKABLE void saluda();

};


class KScreenSystemSettings : public KQuickConfigModule
{
    Q_OBJECT
    public:
	KScreenSystemSettings(QObject *parent, const KPluginMetaData &data);
    private:
	KScreenSystemSettingsHandler* handler;
};



