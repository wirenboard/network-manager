/* NetworkManager -- Network link manager
 *
 * Backend implementation for the Linux From Scratch http://www.linuxfromscratch.org/
 *
 * Wayne Blaszczyk <wblaszcz@bigpond.net.au>
 * Armin K. <krejzi@email.com>
 *
 * Heavily based on NetworkManagerRedhat.c by Dan Williams <dcbw@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * (C) Copyright 2004 Tom Parker
 * (C) Copyright 2004 Matthew Garrett
 * (C) Copyright 2004 - 2012 Red Hat, Inc.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "NetworkManagerGeneric.h"
#include "NetworkManagerUtils.h"

void nm_backend_enable_loopback (void)
{
	nm_generic_enable_loopback ();
}

void nm_backend_update_dns (void)
{
	if (g_file_test("/var/run/nscd/nscd.pid", G_FILE_TEST_EXISTS))
		nm_spawn_process ("/usr/sbin/nscd -i hosts");
}

int nm_backend_ipv6_use_tempaddr (void)
{
	return nm_generic_ipv6_use_tempaddr ();
}