#include "to-upper.h"

#include <stdlib.h>

#define TO_UPPER_IN_SIZE 1 << 13   // 8192
#define TO_UPPER_OUT_SIZE 1 << 13  // 8192

struct ToUpperCtx {
  int endCalled;
};

ToUpperCtx* ToUpper_create(void) {
  ToUpperCtx* ctx = malloc(sizeof(ToUpperCtx));
  if (ctx) {
    ToUpper_reset(ctx);
  }
  return ctx;
}

void ToUpper_free(ToUpperCtx* ctx) { free(ctx); }

void ToUpper_reset(ToUpperCtx* ctx) { ctx->endCalled = 0; }

size_t ToUpper_next(ToUpperCtx* ctx, ToUpperOutputBuffer* output, const ToUpperInputBuffer* input) {
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
  ((ToUpperInputBuffer*)input)->pos = inPos;

  return input->size - inPos;
}

int ToUpper_end(ToUpperCtx* ctx, ToUpperOutputBuffer* output) {
  (void)ctx;
  (void)output;
  ctx->endCalled = 1;
  return 0;
}

size_t ToUpper_inSize(void) { return TO_UPPER_IN_SIZE; }

size_t ToUpper_outSize(void) { return TO_UPPER_OUT_SIZE; }
