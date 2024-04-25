#ifndef TIFALIBS_MATH_DIV64
#define TIFALIBS_MATH_DIV64

#include "../util/util.hpp"

namespace tifa_libs::math {

CEXP i64 div_i64d(i64 a, i64 b) { return i64(f64(a) / f64(b)); }
CEXP u64 div_u64d(u64 a, u64 b) { return u64(f64(a) / f64(b)); }
CEXP i64 div_i64(i64 a, i64 b) { return a <= 1000000000000 ? div_i64d(a, b) : a / b; }
CEXP u64 div_u64(u64 a, u64 b) { return a <= 1000000000000 ? div_u64d(a, b) : a / b; }

}  // namespace tifa_libs::math

#endif