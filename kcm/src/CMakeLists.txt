# SPDX-FileCopyrightText: Year Author <email@company.com>
#
# SPDX-License-Identifier: BSD-2-Clause

kcmutils_add_qml_kcm(kcm_kscreensystem)
target_sources(kcm_kscreensystem PRIVATE
   kscreen-system.cpp
   kscreen-system.h
)
target_link_libraries(kcm_time PRIVATE
    Qt::Quick
    KF6::CoreAddons
    KF6::KCMUtils
    KF6::I18n
)
