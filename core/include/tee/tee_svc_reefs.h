#ifndef TEE_SVC_REEFS_H
#define TEE_SVC_REEFS_H

#include <tee_api_types.h>
#include <kernel/tee_ta_manager.h>
#include <tee/tee_fs.h>

TEE_Result syscall_reefs_write(void *filename, size_t filename_size,
                               void *data, size_t data_size);

#endif /* TEE_SVC_REEFS_H */
