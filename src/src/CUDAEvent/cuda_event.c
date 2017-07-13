#include <stdio.h>
#include <cuda_runtime.h>

#include "sac.h"
#include "cuda_event.h"

cudaEvent_t * create_cuda_event( )
{
  cudaEvent_t * event;
  event = SAC_MALLOC( sizeof(cudaEvent_t));
  cudaError( cudaEventCreate(event));
  return event;
}

void cuda_event_record( cudaEvent_t * event)
{
  cudaError( cudaEventRecord(*event, 0));
}

void cuda_event_sync( cudaEvent_t * event)
{
  cudaError( cudaEventSynchronize(*event));
}

float cuda_elapsed_time( cudaEvent_t * event1, cudaEvent_t * event2)
{
  float elps;
  cudaError( cudaEventElapsedTime(&elps, *event1, *event2));
  return elps;
}
