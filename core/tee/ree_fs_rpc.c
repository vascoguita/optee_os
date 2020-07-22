#include <stdlib.h>
#include <tee/tee_fs_rpc.h>
#include <kernel/thread.h>
#include <tee/ree_fs_rpc.h>
#include <util.h>
#include <string.h>
#include <optee_rpc_cmd.h>

TEE_Result ree_fs_rpc_create(char *filename, size_t filename_size, int *fd)
{
    struct mobj *mobj;
    TEE_Result res;
    void *va;
    size_t num_params;
    struct thread_param params[THREAD_RPC_MAX_NUM_PARAMS];

    va = tee_fs_rpc_cache_alloc(filename_size, &mobj);
    if (!va)
        return TEE_ERROR_OUT_OF_MEMORY;

    memcpy(va, filename, filename_size);

    num_params = 3;
    params[0] = THREAD_PARAM_VALUE(IN, OPTEE_RPC_FS_CREATE, 0, 0);
    params[1] = THREAD_PARAM_MEMREF(IN, mobj, 0, filename_size);
    params[2] = THREAD_PARAM_VALUE(OUT, 0, 0, 0);

    res = thread_rpc_cmd(OPTEE_RPC_CMD_FS, num_params, params);
    if (res == TEE_SUCCESS)
        *fd = params[2].u.value.a;
    return res;
}

TEE_Result ree_fs_rpc_open(char *filename, size_t filename_size, int *fd)
{
    struct mobj *mobj;
    TEE_Result res;
    void *va;
    size_t num_params;
    struct thread_param params[THREAD_RPC_MAX_NUM_PARAMS];

    va = tee_fs_rpc_cache_alloc(TEE_FS_NAME_MAX, &mobj);
    if (!va)
        return TEE_ERROR_OUT_OF_MEMORY;

    memcpy(va, filename, filename_size);

    num_params = 3;
    params[0] = THREAD_PARAM_VALUE(IN, OPTEE_RPC_FS_OPEN, 0, 0);
    params[1] = THREAD_PARAM_MEMREF(IN, mobj, 0, filename_size);
    params[2] = THREAD_PARAM_VALUE(OUT, 0, 0, 0);

    res = thread_rpc_cmd(OPTEE_RPC_CMD_FS, num_params, params);
    if (res == TEE_SUCCESS)
        *fd = params[2].u.value.a;
    return res;
}

TEE_Result ree_fs_rpc_close(int fd)
{
    size_t num_params;
    struct thread_param params[THREAD_RPC_MAX_NUM_PARAMS];

    num_params = 1;
    params[0] = THREAD_PARAM_VALUE(IN, OPTEE_RPC_FS_CLOSE, fd, 0);

    return thread_rpc_cmd(OPTEE_RPC_CMD_FS, num_params, params);
}

TEE_Result ree_fs_rpc_write(int fd, int64_t offset, void *data, size_t data_size)
{
    struct mobj *mobj;
    uint8_t *va;
    size_t num_params;
    struct thread_param params[THREAD_RPC_MAX_NUM_PARAMS];

    if (offset < 0)
        return TEE_ERROR_BAD_PARAMETERS;

    va = tee_fs_rpc_cache_alloc(data_size, &mobj);
    if (!va)
        return TEE_ERROR_OUT_OF_MEMORY;

    num_params = 2;
    params[0] = THREAD_PARAM_VALUE(IN, OPTEE_RPC_FS_WRITE, fd, offset);
    params[1] = THREAD_PARAM_MEMREF(IN, mobj, 0, data_size);

    memcpy(va, data, data_size);

    return thread_rpc_cmd(OPTEE_RPC_CMD_FS, num_params, params);
}

TEE_Result ree_fs_rpc_read(int fd, int64_t offset, void *data, size_t *data_size)
{
    struct mobj *mobj;
    TEE_Result res;
    void *va;
    size_t num_params;
    struct thread_param params[THREAD_RPC_MAX_NUM_PARAMS];

    if (offset < 0)
        return TEE_ERROR_BAD_PARAMETERS;

    va = tee_fs_rpc_cache_alloc(*data_size, &mobj);
    if (!va)
        return TEE_ERROR_OUT_OF_MEMORY;

    num_params = 2;
    params[0] = THREAD_PARAM_VALUE(IN, OPTEE_RPC_FS_READ, fd, offset);
    params[1] = THREAD_PARAM_MEMREF(OUT, mobj, 0, *data_size);

    thread_rpc_cmd(OPTEE_RPC_CMD_FS, num_params, params);
    if (res == TEE_SUCCESS) {
        *data_size = params[1].u.memref.size;
        memcpy(data, va, *data_size);
    }

    return res;
}