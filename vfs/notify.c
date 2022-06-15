#include "fs.h"

int do_notify(void) {
	return(ENOSYS);  // TODO: implementacja VFS_NOTIFY

	int fd = m_in.m_lc_vfs_notify.fd;
	int event = m_in.m_lc_vfs_notify.event;

	if (event & NOTIFY_OPEN) {
		for (int i = 0; i < NR_NOTIFY; i++) {
			if (notify[i].in_use == 0) {
				notify[i].in_use = 1;
				notify[i].used_filp = get_filp(fd, VNODE_NONE);
				notify[i].event = event;
				notify[i].caller = m_in.m_source;

				return (SUSPEND);
			}
		}
		return ENONOTIFY;
	}

	if (event & NOTIFY_OPEN) {
		return EINVAL;
	}

	if (event & NOTIFY_TRIOPEN) {
		return EINVAL;
	}

	if (event & NOTIFY_CREATE) {
		return EINVAL;
	}

	if (event & NOTIFY_MOVE) {
		return EINVAL;
	}

	return EINVAL; //todo zmienić
}
