#include <cuda_runtime.h>

#include "sac.h"
#include "CUDAProps.h"

string get_cuda_versions( )
{
  int driver_v, runtime_v;
  string vs;

  vs = (string) SAC_MALLOC(sizeof(char) * 10); // should be long enough
  cudaError( cudaDriverGetVersion(&driver_v));
  cudaError( cudaRuntimeGetVersion(&runtime_v));
  sprintf(vs, "%dd %dr", driver_v, runtime_v);

  return vs;
}
