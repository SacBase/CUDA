#include <cuda_runtime.h>
#include <stdio.h>

#include "sac.h"
#include "free_event.h"

void free_event( cudaEvent_t * event)
{
  cudaError( cudaEventDestroy(*event));
  SAC_FREE( event);
}
