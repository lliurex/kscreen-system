/**
 * SPDX-FileCopyrightText: Year Author <author@domain.com>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once
#include <KQuickConfigModule>
#include <QDBusInterface>

/**
class KScreenSystemSettingsHandler: public QObject{
    Q_OBJECT
    public:
	explicit KScreenSystemSettingsHandler(QObject *parent);
	Q_INVOKABLE void test_function();

};
*/

class KScreenSystemSettings : public KQuickConfigModule
{
    Q_OBJECT
    public:
	KScreenSystemSettings(QObject *parent, const KPluginMetaData &data);

	QDBusInterface m_iface;
	Q_INVOKABLE void changeWorkingMode( int index);
	Q_INVOKABLE void saveSettingsFile();
	Q_INVOKABLE void save() override;
	Q_INVOKABLE void load() override;

    Q_SIGNALS:
	void defaultValues();
	void errorNotExistsFile();
	void updatedGlobalConfig();
	void saveConfig();
	void loadValues(int index);
    private:
	//KScreenSystemSettingsHandler* handler;
	int currentWorkingMode ;
};



