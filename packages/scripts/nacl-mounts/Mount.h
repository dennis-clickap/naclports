/*
 * Copyright (c) 2011 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef PACKAGES_SCRIPTS_NACL_MOUNTS_MOUNT_H_
#define PACKAGES_SCRIPTS_NACL_MOUNTS_MOUNT_H_

#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string>
#include "macros.h"

// Mount serves as the base mounting class that will be used by
// the mount manager (class MountManager).  The mount manager
// relies heavily on the GetNode method as a way of directing
// system calls that take a path as an argument.
class Mount {
 public:
  Mount() {}
  virtual ~Mount() {}

  // Given a path and a stat struct, return the inode associated with the path
  virtual int GetNode(const std::string& path, struct stat *st) {
    return -1;
  }

  // Increase the reference count for a given inode
  virtual void Ref(ino_t node) {}
  // Decrease the reference count for a given inode
  virtual void Unref(ino_t node) {}

  // System calls that can be overridden by a mount implementation
  virtual int Creat(const std::string& path, mode_t mode,
                    struct stat *st) {
    errno = ENOSYS;
    return -1;
  }
  virtual int Mkdir(const std::string& path, mode_t mode,
                    struct stat *st) {
    errno = ENOSYS;
    return -1;
  }
  virtual int Unlink(const std::string& path) {
    errno = ENOSYS;
    return -1;
  }
  virtual int Rmdir(ino_t node) {
    errno = ENOSYS;
    return -1;
  }
  virtual int Chmod(ino_t node, mode_t mode) {
    errno = ENOSYS;
    return -1;
  }
  virtual int Stat(ino_t node, struct stat *buf) {
    errno = ENOSYS;
    return -1;
  }
  virtual int Fsync(ino_t node) {
    errno = ENOSYS;
    return -1;
  }
  virtual int Getdents(ino_t node, off_t offset, struct dirent *dirp,
                       unsigned int count) {
    errno = ENOSYS;
    return -1;
  }
  virtual ssize_t Read(ino_t node, off_t offset, void *buf,
                       size_t count) {
    errno = ENOSYS;
    return -1;
  }
  virtual ssize_t Write(ino_t node, off_t offset, const void *buf,
                        size_t count) {
    errno = ENOSYS;
    return -1;
  }

 private:
  DISALLOW_COPY_AND_ASSIGN(Mount);
};

#endif  // PACKAGES_SCRIPTS_NACL_MOUNTS_MOUNT_H_