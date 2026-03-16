#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef struct ToUpperCtx ToUpperCtx;

typedef struct {
  const void* src;
  size_t size;
  size_t pos;
} ToUpperInputBuffer;

typedef struct {
  void* dst;
  size_t size;
  size_t pos;
} ToUpperOutputBuffer;

ToUpperCtx* ToUpper_create(void);
void ToUpper_free(ToUpperCtx* ctx);
void ToUpper_reset(ToUpperCtx* ctx);
size_t ToUpper_next(ToUpperCtx* ctx, ToUpperOutputBuffer* output, const ToUpperInputBuffer* input);
int ToUpper_end(ToUpperCtx* ctx, ToUpperOutputBuffer* output);

size_t ToUpper_inSize(void);
size_t ToUpper_outSize(void);

#ifdef __cplusplus
}
#endif
