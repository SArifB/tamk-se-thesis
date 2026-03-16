#pragma once
#include <ostream>
#include <string_view>

#include "cpp-lib1/append-to-upper.hpp"

namespace cpp_lib1 {

struct to_upper_appender {
  std::string_view str;

  friend auto operator<<(std::ostream& os, to_upper_appender const& self) -> std::ostream& {
    return append_to_upper(os, self.str);
  }
};

}  // namespace cpp_lib1
