/* Target-dependent code for FreeBSD, architecture independent.

   Copyright (C) 2009-2018 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef FBSD_TDEP_H
#define FBSD_TDEP_H

extern void fbsd_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch);

/* Output the header for "info proc files".  */

extern void fbsd_info_proc_files_header ();

/* Output description of a single file descriptor for "info proc
   files".  The KF_TYPE, KF_FD, KF_FLAGS, KF_OFFSET, KF_VNODE_TYPE,
   KF_SOCK_DOMAIN, KF_SOCK_TYPE, and KF_SOCK_PROTOCOL parameters
   should contain the value of the corresponding fields in a 'struct
   kinfo_file'.  The KF_SA_LOCAL, KF_SA_PEER, and KF_PATH parameters
   should contain pointers to the corresponding fields in a 'struct
   kinfo_file'. */

extern void fbsd_info_proc_files_entry (int kf_type, int kf_fd, int kf_flags,
					LONGEST kf_offset, int kf_vnode_type,
					int kf_sock_domain, int kf_sock_type,
					int kf_sock_protocol,
					const void *kf_sa_local,
					const void *kf_sa_peer,
					const void *kf_path);

/* Helper function to generate mappings flags for a single VM map
   entry in 'info proc mappings'.  The KVE_FLAGS and KVE_PROTECTION
   parameters should contain the values of the corresponding fields in
   a 'struct kinfo_vmentry'.  */

extern const char *fbsd_vm_map_entry_flags (int kve_flags, int kve_protection);

#endif /* fbsd-tdep.h */
