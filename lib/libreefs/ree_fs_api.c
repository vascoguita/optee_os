#include <ree_fs_api.h>

#include <tee_internal_api.h>
#include <utee_syscalls.h>

TEE_Result ree_fs_write(const char *filename, size_t filename_size,
                 const void *data, size_t data_size) {
    TEE_Result res;
    DMSG("ree_fs_write called\n"
         "filename:%s\nfilename_size:%u\ndata:%s\ndata_size:%u",
         filename, filename_size, data, data_size);

    res = reefs_write(filename, filename_size, data, data_size);

    return res;
}