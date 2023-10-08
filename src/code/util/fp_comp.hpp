#ifndef TIFA_LIBS_UTIL_FP_COMP
#define TIFA_LIBS_UTIL_FP_COMP

#include "fp_const.hpp"

namespace tifa_libs {

template <class FP, std::enable_if_t<std::is_integral_v<FP>>* = nullptr>
constexpr int sgn(FP x) { return x < 0 ? -1 : x > 0; }
template <class FP, std::enable_if_t<std::is_floating_point_v<FP>>* = nullptr>
constexpr int sgn(FP x) { return x < -EPS<FP> ? -1 : x > EPS<FP>; }
template <class FP>
constexpr bool is_neg(FP x) { return sgn(x) < 0; }
template <class FP>
constexpr bool is_zero(FP x) { return sgn(x) == 0; }
template <class FP>
constexpr bool is_pos(FP x) { return sgn(x) > 0; }

template <class FP>
constexpr int comp(FP l, FP r) { return sgn(l - r); }
template <class FP>
constexpr bool is_lt(FP l, FP r) { return is_neg(l - r); }
template <class FP>
constexpr bool is_eq(FP l, FP r) { return is_zero(l - r); }
template <class FP>
constexpr bool is_gt(FP l, FP r) { return is_pos(l - r); }

}  // namespace tifa_libs

#endif