#ifndef TEE_SVC_REEFS_H
#define TEE_SVC_REEFS_H

#include <tee_api_types.h>

TEE_Result syscall_ree_fs_create(char *filename, size_t filename_size, int *fd);

TEE_Result syscall_ree_fs_open(char *filename, size_t filename_size, int *fd);

TEE_Result syscall_ree_fs_close(int fd);

TEE_Result syscall_ree_fs_write(int fd, int64_t offset, void *data, size_t data_size);

TEE_Result syscall_ree_fs_read(int fd, int64_t offset, void *data, size_t *data_size);

#endif /* TEE_SVC_REEFS_H */