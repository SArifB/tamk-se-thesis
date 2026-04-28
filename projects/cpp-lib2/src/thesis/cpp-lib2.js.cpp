#include "thesis/cpp-lib2.hpp"

#include <emscripten/bind.h>
#include <emscripten/emscripten.h>

EMSCRIPTEN_BINDINGS(add_module) {
  emscripten::function("add", &thesis::cpp_lib2::add);
}
