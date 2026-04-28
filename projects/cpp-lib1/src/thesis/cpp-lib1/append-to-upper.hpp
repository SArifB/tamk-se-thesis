#pragma once
#include <ostream>
#include <string_view>

namespace thesis {
namespace cpp_lib1 {

auto append_to_upper(std::ostream& os, std::string_view str) -> std::ostream&;

}  // namespace cpp_lib1
}  // namespace thesis
