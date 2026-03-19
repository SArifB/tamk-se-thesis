#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#define THESIS_TO_UPPER_CTX_SIZE 64
#define THESIS_TO_UPPER_CTX_ALIGN 8

typedef struct ThesisToUpperCtx {
  alignas(THESIS_TO_UPPER_CTX_ALIGN) uint8_t buf[THESIS_TO_UPPER_CTX_SIZE];
} ThesisToUpperCtx;

ThesisToUpperCtx ThesisToUpperCtx_make(void);
void ThesisToUpperCtx_free(ThesisToUpperCtx* ctx);

void ThesisToUpperCtx_set_input(ThesisToUpperCtx* ctx, char const* data, size_t len);
void ThesisToUpperCtx_set_output(ThesisToUpperCtx* ctx, char* buf, size_t cap);

typedef enum {
  THESIS_TO_UPPER_OK,
  THESIS_TO_UPPER_OUTPUT_FULL,
  THESIS_TO_UPPER_ERROR_NO_OUTPUT
} ThesisToUpperResult;

ThesisToUpperResult ThesisToUpperCtx_process(ThesisToUpperCtx* ctx);

void ThesisToUpperCtx_flush(ThesisToUpperCtx* ctx);

size_t ThesisToUpperCtx_input_remaining(ThesisToUpperCtx const* ctx);
size_t ThesisToUpperCtx_output_pending(ThesisToUpperCtx const* ctx);

#ifdef __cplusplus
}
#endif
