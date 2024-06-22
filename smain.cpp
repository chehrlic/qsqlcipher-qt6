// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include <qsqldriverplugin.h>
#include <qstringlist.h>
#include "qsql_sqlite_p.h"
#include "qsql_sqlite_vfs_p.h"

QT_BEGIN_NAMESPACE

using namespace Qt::StringLiterals;

class QSQLCiperDriverPlugin : public QSqlDriverPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QSqlDriverFactoryInterface" FILE "sqlite.json")

public:
    QSQLCiperDriverPlugin();

    QSqlDriver* create(const QString &) override;
};

QSQLCiperDriverPlugin::QSQLCiperDriverPlugin()
    : QSqlDriverPlugin()
{
    register_qt_vfs();
}

QSqlDriver* QSQLCiperDriverPlugin::create(const QString &name)
{
    if (name == "QSQLCIPHER"_L1) {
        QSQLiteDriver* driver = new QSQLiteDriver();
        return driver;
    }

    return nullptr;
}

QT_END_NAMESPACE

#include "smain.moc"
