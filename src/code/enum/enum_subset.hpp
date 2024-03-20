#ifndef TIFALIBS_ENUM_ENUM_SUBSET
#define TIFALIBS_ENUM_ENUM_SUBSET

#include "../util/util.hpp"

namespace tifa_libs {

// enumerate x : x \subset b
constexpr vec<u32> enum_subset(u32 b) {
  vec<u32> res;
  for (u32 i = b; ~i; --i) res.push_back(i &= b);
  return res;
}

}  // namespace tifa_libs

#endif