#include <stdio.h>
#include <string.h>

#include "c-lib1/to-upper.h"

// to upper echo
int main() {
  ToUpperCtx* ctx = ToUpper_create();
  char inBuf[1 << 10]{};
  char outBuf[1 << 5]{};
  while (fgets(inBuf, sizeof(inBuf), stdin)) {
    ToUpperInputBuffer in = { inBuf, strlen(inBuf), 0 };
    ToUpperOutputBuffer out = { outBuf, sizeof(outBuf), 0 };

    while (ToUpper_next(ctx, &out, &in) > 0 || out.pos > 0) {
      fwrite(outBuf, 1, out.pos, stdout);
      out.pos = 0;
    }
  }
  ToUpperOutputBuffer null_buffer = { NULL, 0, 0 };
  ToUpper_end(ctx, &null_buffer);  // flush
  ToUpper_free(ctx);
  return 0;
}
