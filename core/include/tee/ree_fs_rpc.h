#ifndef TRX_REE_FS_RPC_H
#define TRX_REE_FS_RPC_H

#include <tee_api_types.h>

TEE_Result ree_fs_rpc_create(char *filename, size_t filename_size, int *fd);

TEE_Result ree_fs_rpc_open(char *filename, size_t filename_size, int *fd);

TEE_Result ree_fs_rpc_close(int fd);

TEE_Result ree_fs_rpc_write(int fd, int64_t offset, void *data, size_t data_size);

TEE_Result ree_fs_rpc_read(int fd, int64_t offset, void *data, size_t *data_size);

#endif //TRX_REE_FS_RPC_H
