#include <stdio.h>
#include <string.h>

#include "thesis/c-lib1/to-upper.h"

// to upper echo
int main() {
  ThesisToUpperCtx* ctx = ThesisToUpperCtx_make();
  char inBuf[1 << 10]{};
  char outBuf[1 << 5]{};
  while (fgets(inBuf, sizeof(inBuf), stdin)) {
    ThesisToUpperInputBuffer in = { inBuf, strlen(inBuf), 0 };
    ThesisToUpperOutputBuffer out = { outBuf, sizeof(outBuf), 0 };

    while (ThesisToUpperCtx_run_to_completion(ctx, &out, &in) > 0 || out.pos > 0) {
      fwrite(outBuf, 1, out.pos, stdout);
      out.pos = 0;
    }
  }
  ThesisToUpperOutputBuffer null_buffer = { NULL, 0, 0 };
  ThesisToUpperCtx_end(ctx, &null_buffer);  // flush
  ThesisToUpperCtx_free(ctx);
  return 0;
}
