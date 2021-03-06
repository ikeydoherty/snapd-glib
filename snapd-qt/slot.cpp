/*
 * Copyright (C) 2017 Canonical Ltd.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#include <snapd-glib/snapd-glib.h>

#include "Snapd/slot.h"

QSnapdSlot::QSnapdSlot (void *snapd_object, QObject *parent) : QSnapdWrappedObject (g_object_ref (snapd_object), g_object_unref, parent) {}

QString QSnapdSlot::name () const
{
    return snapd_slot_get_name (SNAPD_SLOT (wrapped_object));
}

QString QSnapdSlot::snap () const
{
    return snapd_slot_get_snap (SNAPD_SLOT (wrapped_object));
}

QString QSnapdSlot::interface () const
{
    return snapd_slot_get_interface (SNAPD_SLOT (wrapped_object));
}

QString QSnapdSlot::label () const
{
    return snapd_slot_get_label (SNAPD_SLOT (wrapped_object));
}

int QSnapdSlot::connectionCount () const
{
    GPtrArray *connections;

    connections = snapd_slot_get_connections (SNAPD_SLOT (wrapped_object));
    return connections != NULL ? connections->len : 0;
}

QSnapdConnection *QSnapdSlot::connection (int n) const
{
    GPtrArray *connections;

    connections = snapd_slot_get_connections (SNAPD_SLOT (wrapped_object));
    if (connections == NULL || n < 0 || (guint) n >= connections->len)
        return NULL;
    return new QSnapdConnection (connections->pdata[n]);
}
