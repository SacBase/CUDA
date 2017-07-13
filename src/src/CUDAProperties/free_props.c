#include <cuda_runtime.h>

#include "sac.h"
#include "CUDAProps.h"

void free_props( struct cudaDeviceProp * prop)
{
  SAC_FREE(prop);
}
