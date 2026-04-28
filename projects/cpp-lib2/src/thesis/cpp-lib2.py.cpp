#include "thesis/cpp-lib2.hpp"

#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
  using namespace pybind11::literals;
  m.doc() = "Python bindings for mylib.add";

  m.def("add", &thesis::cpp_lib2::add, "Add two numbers", "left"_a, "right"_a);
}
