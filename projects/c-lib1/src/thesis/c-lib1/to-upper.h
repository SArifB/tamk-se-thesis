#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef struct ThesisToUpperCtx ThesisToUpperCtx;

typedef struct {
  const void* src;
  size_t size;
  size_t pos;
} ThesisToUpperInputBuffer;

typedef struct {
  void* dst;
  size_t size;
  size_t pos;
} ThesisToUpperOutputBuffer;

ThesisToUpperCtx* ThesisToUpperCtx_make(void);
void ThesisToUpperCtx_free(ThesisToUpperCtx* ctx);
void ThesisToUpperCtx_reset(ThesisToUpperCtx* ctx);
size_t ThesisToUpperCtx_run_to_completion(
  ThesisToUpperCtx* ctx, ThesisToUpperOutputBuffer* output, const ThesisToUpperInputBuffer* input);
int ThesisToUpperCtx_end(ThesisToUpperCtx* ctx, ThesisToUpperOutputBuffer* output);

size_t ThesisToUpperInputBuffer_size(void);
size_t ThesisToUpperOutputBuffer_size(void);

#ifdef __cplusplus
}
#endif
