/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia. For licensing terms and
** conditions see http://qt.digia.com/licensing. For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights. These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QLIBRARYINFO_H
#define QLIBRARYINFO_H

#include <QtCore/qstring.h>
#include <QtCore/qdatetime.h>

QT_BEGIN_NAMESPACE

class QStringList;

class Q_CORE_EXPORT QLibraryInfo
{
public:
    static QString licensee();
    static QString licensedProducts();

#ifndef QT_NO_DATESTRING
    static QDate buildDate();
#endif //QT_NO_DATESTRING

    static const char * build() Q_DECL_NOTHROW;

    static bool isDebugBuild();

    enum LibraryLocation
    {
        PrefixPath = 0,
        DocumentationPath,
        HeadersPath,
        LibrariesPath,
        LibraryExecutablesPath,
        BinariesPath,
        PluginsPath,
        ImportsPath,
        Qml2ImportsPath,
        ArchDataPath,
        DataPath,
        TranslationsPath,
        ExamplesPath,
        TestsPath,
        // Insert new values above this line
        // Please read the comments in qlibraryinfo.cpp before adding
#ifdef QT_BOOTSTRAPPED
        // These are not subject to binary compatibility constraints
        SysrootPath,
        HostPrefixPath,
        HostBinariesPath,
        HostLibrariesPath,
        HostDataPath,
        TargetSpecPath,
        HostSpecPath,
        LastHostPath = HostSpecPath,
#endif
        SettingsPath = 100
    };
    static QString location(LibraryLocation); // ### Qt 6: consider renaming it to path()
#ifdef QT_BOOTSTRAPPED
    enum PathGroup { FinalPaths, EffectivePaths, EffectiveSourcePaths };
    static QString rawLocation(LibraryLocation, PathGroup);
#endif

    static QStringList platformPluginArguments(const QString &platformName);

private:
    QLibraryInfo();
};

QT_END_NAMESPACE

#endif // QLIBRARYINFO_H
