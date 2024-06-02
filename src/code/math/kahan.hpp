#ifndef TIFALIBS_MATH_KAHAN
#define TIFALIBS_MATH_KAHAN

#include "../util/util.hpp"

namespace tifa_libs::math {

template <std::floating_point FP>
class kahan_fp {
  FP sum, c;

 public:
  CEXP kahan_fp(FP val = 0) : sum(val), c(0) {}

  CEXP kahan_fp& operator+=(FP x) {
    const FP y = x - c;
    volatile FP t = sum + y, z = t - sum;
    return c = z - y, sum = t, *this;
  }
  CEXP operator FP() const { return sum; }
};
template <class FP>
using kahan = std::conditional_t<std::is_floating_point_v<FP>, kahan_fp<FP>, FP>;

}  // namespace tifa_libs::math

#endif