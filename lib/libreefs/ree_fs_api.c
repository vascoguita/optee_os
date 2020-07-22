#include <ree_fs_api.h>

#include <tee_internal_api.h>
#include <utee_syscalls.h>

TEE_Result ree_fs_api_create(char *filename, size_t filename_size, int *fd)
{
    return ree_fs_create(filename, filename_size, fd);
}

TEE_Result ree_fs_api_open(char *filename, size_t filename_size, int *fd)
{
    return ree_fs_open(filename, filename_size, fd);
}

TEE_Result ree_fs_api_close(int fd)
{
    return ree_fs_close(fd);
}

TEE_Result ree_fs_api_write(int fd, int64_t offset, void *data, size_t data_size)
{
    return ree_fs_write(fd, offset, data, data_size);
}

TEE_Result ree_fs_api_read(int fd, int64_t offset, void *data, size_t *data_size)
{
    return ree_fs_read(fd, offset, data, data_size);
}
