#include <tee_api_types.h>
#include <tee/ree_fs_rpc.h>
#include <tee/ree_fs_svc.h>
#include <util.h>

TEE_Result syscall_ree_fs_create(char *filename, size_t filename_size, int *fd)
{
    return ree_fs_rpc_create(filename, filename_size, fd);
}

TEE_Result syscall_ree_fs_open(char *filename, size_t filename_size, int *fd)
{
    return ree_fs_rpc_open(filename, filename_size, fd);
}

TEE_Result syscall_ree_fs_close(int fd)
{
    return ree_fs_rpc_close(fd);
}

TEE_Result syscall_ree_fs_write(int fd, int64_t offset, void *data, size_t data_size)
{
    return ree_fs_rpc_write(fd, offset, data, data_size);
}

TEE_Result syscall_ree_fs_read(int fd, int64_t offset, void *data, size_t *data_size)
{
    return ree_fs_rpc_read(fd, offset, data, data_size);
}

