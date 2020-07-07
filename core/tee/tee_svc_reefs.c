#include <kernel/mutex.h>
#include <kernel/tee_misc.h>
#include <kernel/tee_ta_manager.h>
#include <mm/tee_mmu.h>
#include <string.h>
#include <tee_api_defines_extensions.h>
#include <tee_api_defines.h>
#include <tee/fs_dirfile.h>
#include <tee/tee_fs.h>
#include <tee/tee_obj.h>
#include <tee/tee_pobj.h>
#include <tee/tee_svc_cryp.h>
#include <tee/tee_svc.h>
#include <tee/tee_svc_storage.h>
#include <trace.h>

TEE_Result syscall_reefs_write(void *filename, size_t filename_size,
                               void *data, size_t data_size)
{
	TEE_Result res = TEE_SUCCESS;
    DMSG("syscall_reefs_write called\n"
          "filename:%s\nfilename_size:%u\ndata:%s\ndata_size:%u",
         (char *)filename, filename_size, (char *)data, data_size);
	return res;
}