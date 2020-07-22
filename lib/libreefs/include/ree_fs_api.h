#ifndef TRX_REE_FS_API_H
#define TRX_REE_FS_API_H

#include <tee_internal_api.h>

TEE_Result ree_fs_api_create(char *filename, size_t filename_size, int *fd);

TEE_Result ree_fs_api_open(char *filename, size_t filename_size, int *fd);

TEE_Result ree_fs_api_close(int fd);

TEE_Result ree_fs_api_write(int fd, int64_t offset, void *data, size_t data_size);

TEE_Result ree_fs_api_read(int fd, int64_t offset, void *data, size_t *data_size);

#endif //TRX_REE_FS_API_H