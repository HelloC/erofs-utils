/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * erofs_utils/include/erofs/config.h
 *
 * Copyright (C) 2018-2019 HUAWEI, Inc.
 *             http://www.huawei.com/
 * Created by Li Guifu <bluce.liguifu@huawei.com>
 */
#ifndef __EROFS_CONFIG_H
#define __EROFS_CONFIG_H

#include "defs.h"

#ifdef HAVE_LIBSELINUX
#include <selinux/selinux.h>
#include <selinux/label.h>
#endif

enum {
	FORCE_INODE_COMPACT = 1,
	FORCE_INODE_EXTENDED,
};

struct erofs_configure {
	const char *c_version;
	int c_dbg_lvl;
	bool c_dry_run;
	bool c_legacy_compress;

#ifdef HAVE_LIBSELINUX
	struct selabel_handle *sehnd;
#endif
	/* related arguments for mkfs.erofs */
	char *c_img_path;
	char *c_src_path;
	char *c_compr_alg_master;
	int c_compr_level_master;
	int c_force_inodeversion;
	/* < 0, xattr disabled and INT_MAX, always use inline xattrs */
	int c_inline_xattr_tolerance;
	u64 c_unix_timestamp;
};

extern struct erofs_configure cfg;

void erofs_init_configure(void);
void erofs_show_config(void);
void erofs_exit_configure(void);

void erofs_set_fs_root(const char *rootdir);
const char *erofs_fspath(const char *fullpath);

#endif

