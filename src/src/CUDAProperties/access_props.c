#include <stdio.h>
#include <string.h>
#include <cuda_runtime.h>

#include "sac.h"
#include "CUDAProps.h"

struct cudaDeviceProp * load_cuda_properties( int device_id)
{
  struct cudaDeviceProp * prop;
  prop = SAC_MALLOC(sizeof(struct cudaDeviceProp));
  cudaError( cudaGetDeviceProperties(prop, device_id));
  return prop;
}

string get_gpu_name( struct cudaDeviceProp * prop)
{
  string name;
  STRDUP(name, prop->name);
  return name;
}

string get_gpu_cc( struct cudaDeviceProp * prop)
{
  string cc;
  cc = (string) SAC_MALLOC(sizeof(char) * 10); // should be long enough
  sprintf(cc, "%d.%d", prop->major, prop->minor);

  return cc;
}
