#include <stdio.h>
#include <string.h>

#include "thesis/c-lib1/to-upper.h"

int main() {
  ThesisToUpperCtx ctx = ThesisToUpperCtx_make();

  char inBuf[1024];
  char outBuf[32];

  while (fgets(inBuf, sizeof(inBuf), stdin)) {
    ThesisToUpperCtx_set_input(&ctx, inBuf, strlen(inBuf));
    ThesisToUpperCtx_set_output(&ctx, outBuf, sizeof(outBuf));

    ThesisToUpperResult result;
    while ((result = ThesisToUpperCtx_process(&ctx)) == THESIS_TO_UPPER_OUTPUT_FULL) {
      fwrite(outBuf, sizeof(char), ThesisToUpperCtx_output_pending(&ctx), stdout);
      ThesisToUpperCtx_set_output(&ctx, outBuf, sizeof(outBuf));
    }

    if (result != THESIS_TO_UPPER_OK) {
      return 1;
    }

    size_t pending = ThesisToUpperCtx_output_pending(&ctx);
    if (pending > 0) {
      fwrite(outBuf, sizeof(char), pending, stdout);
    }
  }

  ThesisToUpperCtx_flush(&ctx);
  ThesisToUpperCtx_free(&ctx);
  return 0;
}
