#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

#include "config.h"

/* Cuda related error handling - no synchronising is done... */
#ifdef ENABLE_CUDA_CHECK
#define cudaError(ans) { __cudaAssert((ans), __FILE__, __LINE__); }
static inline
void __cudaAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
  if (code != cudaSuccess)
  {
    fprintf(stderr, "cudaError: %s in %s:%d\n", cudaGetErrorString(code), file, line);
    if (abort) exit(code);
  }
  return;
}
#else
#define cudaError(ans) ans;
#endif
