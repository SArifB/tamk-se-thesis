#include "thesis/c-lib1/to-upper.h"

#include <stdlib.h>

#define TO_UPPER_IN_SIZE 1 << 13   // 8192
#define TO_UPPER_OUT_SIZE 1 << 13  // 8192

struct ThesisToUpperCtx {
  int endCalled;
};

ThesisToUpperCtx* ThesisToUpperCtx_make(void) {
  ThesisToUpperCtx* ctx = malloc(sizeof(ThesisToUpperCtx));
  if (ctx) {
    ThesisToUpperCtx_reset(ctx);
  }
  return ctx;
}

void ThesisToUpperCtx_free(ThesisToUpperCtx* ctx) { free(ctx); }

void ThesisToUpperCtx_reset(ThesisToUpperCtx* ctx) { ctx->endCalled = 0; }

size_t ThesisToUpperCtx_run_to_completion(
  ThesisToUpperCtx* ctx, ThesisToUpperOutputBuffer* output, const ThesisToUpperInputBuffer* input) {
  (void)ctx;
  size_t inPos = input->pos;
  size_t outPos = output->pos;
  const char* src = (const char*)input->src;
  char* dst = (char*)output->dst;

  while (inPos < input->size && outPos < output->size) {
    unsigned char c = (unsigned char)src[inPos++];
    if (c >= 'a' && c <= 'z') {
      c = c - 'a' + 'A';
    }
    dst[outPos++] = (char)c;
  }

  output->pos = outPos;
  ((ThesisToUpperInputBuffer*)input)->pos = inPos;

  return input->size - inPos;
}

int ThesisToUpperCtx_end(ThesisToUpperCtx* ctx, ThesisToUpperOutputBuffer* output) {
  (void)ctx;
  (void)output;
  ctx->endCalled = 1;
  return 0;
}

size_t ThesisToUpperInputBuffer_size(void) { return TO_UPPER_IN_SIZE; }

size_t ThesisToUpperOutputBuffer_size(void) { return TO_UPPER_OUT_SIZE; }
