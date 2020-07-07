#ifndef TRX_REE_FS_API_H
#define TRX_REE_FS_API_H

#include <tee_internal_api.h>

TEE_Result ree_fs_write(const char *filename, size_t filename_size,
                 const void *data, size_t data_size);

#endif //TRX_REE_FS_API_H