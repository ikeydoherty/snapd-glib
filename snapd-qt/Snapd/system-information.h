/*
 * Copyright (C) 2016 Canonical Ltd.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#ifndef SNAPD_SYSTEM_INFORMATION_H
#define SNAPD_SYSTEM_INFORMATION_H

#include <QtCore/QObject>
#include <Snapd/WrappedObject>

class Q_DECL_EXPORT QSnapdSystemInformation : public QSnapdWrappedObject
{
    Q_OBJECT

    Q_PROPERTY(QString binariesDirectory READ binariesDirectory)
#ifdef SNAPD_QT_USE_UNSTABLE_API
    Q_PROPERTY(QSnapdSystemConfinement confinement READ confinement)
#endif
    Q_PROPERTY(QString kernelVersion READ kernelVersion)
    Q_PROPERTY(bool managed READ managed)
    Q_PROPERTY(QString mountDirectory READ mountDirectory)
    Q_PROPERTY(bool onClassic READ onClassic)
    Q_PROPERTY(QString osId READ osId)
    Q_PROPERTY(QString osVersion READ osVersion)
    Q_PROPERTY(QString series READ series)
    Q_PROPERTY(QString store READ store)
    Q_PROPERTY(QString version READ version)

public:
#ifdef SNAPD_QT_USE_UNSTABLE_API
    enum QSnapdSystemConfinement
    {
        ConfinementUnknown,
        ConfinementStrict,
        ConfinementPartial
    };
    Q_ENUM(QSnapdSystemConfinement)
#endif

    explicit QSnapdSystemInformation (void *snapd_object, QObject* parent = 0);

    QString binariesDirectory () const;
#ifdef SNAPD_QT_USE_UNSTABLE_API
    QSnapdSystemConfinement confinement () const;
#endif
    QString kernelVersion () const;
    bool managed () const;
    QString mountDirectory () const;
    bool onClassic () const;
    QString osId () const;
    QString osVersion () const;
    QString series () const;
    QString store () const;
    QString version () const;
};

#endif
