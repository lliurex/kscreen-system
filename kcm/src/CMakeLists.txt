# SPDX-FileCopyrightText: Year Author <email@company.com>
#
# SPDX-License-Identifier: BSD-2-Clause

add_definitions(-DTRANSLATION_DOMAIN="kcm_kscreensystem")

kcmutils_add_qml_kcm(kcm_kscreensystem)
target_sources(kcm_kscreensystem PRIVATE
   kscreensystem.cpp
   kscreensystem.h
)
target_link_libraries(kcm_kscreensystem PRIVATE
    Qt::Quick
    KF6::CoreAddons
    KF6::KCMUtils
    KF6::I18n
    Qt::DBus
)
