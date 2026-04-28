#include "thesis/c-lib1/to-upper.h"

#include <string.h>

typedef struct {
  char const* inData;
  size_t inLen;
  size_t inPos;
  char* outBuf;
  size_t outCap;
  size_t outLen;
  int flushed;
} ThesisToUpperCtxImpl;

#define CTX_IMPL(ctx) ((ThesisToUpperCtxImpl*)(ctx)->buf)

ThesisToUpperCtx ThesisToUpperCtx_make(void) {
  ThesisToUpperCtx ctx = { 0 };
  return ctx;
}

void ThesisToUpperCtx_free(ThesisToUpperCtx* inctx) {
  if (inctx) {
    ThesisToUpperCtxImpl* ctx = CTX_IMPL(inctx);
    if (!ctx->flushed) {
      ThesisToUpperCtx_flush(inctx);
    }
  }
}

void ThesisToUpperCtx_set_input(ThesisToUpperCtx* inctx, char const* data, size_t len) {
  ThesisToUpperCtxImpl* ctx = CTX_IMPL(inctx);
  ctx->inData = data;
  ctx->inLen = len;
  ctx->inPos = 0;
}

void ThesisToUpperCtx_set_output(ThesisToUpperCtx* inctx, char* buf, size_t cap) {
  ThesisToUpperCtxImpl* ctx = CTX_IMPL(inctx);
  ctx->outBuf = buf;
  ctx->outCap = cap;
  ctx->outLen = 0;
}

ThesisToUpperResult ThesisToUpperCtx_process(ThesisToUpperCtx* inctx) {
  ThesisToUpperCtxImpl* ctx = CTX_IMPL(inctx);
  if (!ctx->outBuf) {
    return THESIS_TO_UPPER_ERROR_NO_OUTPUT;
  }

  while (ctx->inPos < ctx->inLen && ctx->outLen < ctx->outCap) {
    uint8_t c = (uint8_t)ctx->inData[ctx->inPos++];
    if (c >= 'a' && c <= 'z') {
      c = c - 'a' + 'A';
    }
    ctx->outBuf[ctx->outLen++] = (char)c;
  }

  if (ctx->inPos < ctx->inLen) {
    return THESIS_TO_UPPER_OUTPUT_FULL;
  }

  return THESIS_TO_UPPER_OK;
}

void ThesisToUpperCtx_flush(ThesisToUpperCtx* inctx) {
  ThesisToUpperCtxImpl* ctx = CTX_IMPL(inctx);
  ctx->flushed = 1;
  ctx->outLen = 0;
}

size_t ThesisToUpperCtx_input_remaining(ThesisToUpperCtx const* inctx) {
  ThesisToUpperCtxImpl const* ctx = CTX_IMPL(inctx);
  return ctx->inLen - ctx->inPos;
}

size_t ThesisToUpperCtx_output_pending(ThesisToUpperCtx const* inctx) {
  ThesisToUpperCtxImpl const* ctx = CTX_IMPL(inctx);
  return ctx->outLen;
}
