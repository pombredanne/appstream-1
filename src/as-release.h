/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2014-2015 Matthias Klumpp <matthias@tenstral.net>
 *
 * Licensed under the GNU Lesser General Public License Version 2.1
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the license, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined (__APPSTREAM_H) && !defined (AS_COMPILATION)
#error "Only <appstream.h> can be included directly."
#endif

#ifndef __AS_RELEASE_H
#define __AS_RELEASE_H

#include <glib-object.h>
#include "as-enums.h"

G_BEGIN_DECLS

#define AS_TYPE_RELEASE (as_release_get_type ())
G_DECLARE_DERIVABLE_TYPE (AsRelease, as_release, AS, RELEASE, GObject)

struct _AsReleaseClass
{
	GObjectClass		parent_class;
	/*< private >*/
	void (*_as_reserved1)	(void);
	void (*_as_reserved2)	(void);
	void (*_as_reserved3)	(void);
	void (*_as_reserved4)	(void);
	void (*_as_reserved5)	(void);
	void (*_as_reserved6)	(void);
};

/**
 * AsChecksumKind:
 * @AS_CHECKSUM_KIND_NONE:	No checksum
 * @AS_CHECKSUM_KIND_SHA1:	SHA1
 * @AS_CHECKSUM_KIND_SHA256:	SHA256
 *
 * Checksums supported by #AsRelease
 **/
typedef enum  {
	AS_CHECKSUM_KIND_NONE,
	AS_CHECKSUM_KIND_SHA1,
	AS_CHECKSUM_KIND_SHA256,
	/*< private >*/
	AS_CHECKSUM_KIND_LAST
} AsChecksumKind;

const gchar	*as_checksum_kind_to_string (AsChecksumKind kind);
AsChecksumKind	as_checksum_kind_from_string (const gchar *kind_str);

/**
 * AsSizeKind:
 * @AS_SIZE_KIND_UNKNOWN:	Unknown size
 * @AS_SIZE_KIND_DOWNLOAD:	Size of download of component
 * @AS_SIZE_KIND_INSTALLED:	Size of installed component
 *
 * The release size kind.
 *
 * Since: 0.8.6
 **/
typedef enum {
	AS_SIZE_KIND_UNKNOWN,
	AS_SIZE_KIND_DOWNLOAD,
	AS_SIZE_KIND_INSTALLED,
	/*< private >*/
	AS_SIZE_KIND_LAST
} AsSizeKind;

const gchar	*as_size_kind_to_string (AsSizeKind size_kind);
AsSizeKind	as_size_kind_from_string (const gchar *size_kind);

AsRelease	*as_release_new (void);

const gchar	*as_release_get_version (AsRelease *release);
void		as_release_set_version (AsRelease *release,
						const gchar *version);

guint64		as_release_get_timestamp (AsRelease *release);
void		as_release_set_timestamp (AsRelease *release,
						guint64 timestamp);

const gchar	*as_release_get_description (AsRelease *release);
void		as_release_set_description (AsRelease *release,
						const gchar *description,
						const gchar *locale);

gchar		*as_release_get_active_locale (AsRelease *release);
void		as_release_set_active_locale (AsRelease	*release,
						const gchar *locale);

GPtrArray	*as_release_get_locations (AsRelease *release);
void		as_release_add_location (AsRelease *release,
						const gchar *location);

const gchar	*as_release_get_checksum (AsRelease *release,
						AsChecksumKind kind);
void		as_release_set_checksum (AsRelease *release,
						const gchar *checksum,
						AsChecksumKind kind);

AsUrgencyKind	as_release_get_urgency (AsRelease *release);
void		as_release_set_urgency (AsRelease *release,
						AsUrgencyKind urgency);

guint64		as_release_get_size (AsRelease *release,
					AsSizeKind kind);
void		as_release_set_size (AsRelease *release,
					guint64 size,
					AsSizeKind kind);

G_END_DECLS

#endif /* __AS_RELEASE_H */
