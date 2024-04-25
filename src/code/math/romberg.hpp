#ifndef TIFALIBS_MATH_ROMBERG
#define TIFALIBS_MATH_ROMBERG

#include "../util/util.hpp"

namespace tifa_libs::math {

template <std::floating_point FP, class F>
requires requires(FP fp, F f) {
  { f(fp) } -> std::same_as<FP>;
}
class romberg_impl {
  F f;
  CEXP FP ctqf(FP a, FP b, FP h) const {
    FP ans = 0;
    for (FP i = a + h * .5; i < b; i += h) ans += f(i);
    return ans;
  }

 public:
  explicit CEXP romberg_impl(F func) : f(func) {}

  CEXP FP operator()(FP a, FP b, FP eps = eps_v<FP>) const {
    FP h = b - a;
    FP T1 = (f(a) + f(b)) * h * .5, T2 = 0, S1 = 0, S2 = 0, C1 = 0, C2 = 0, R1 = 0, R2 = 0;
    for (int k = 1; k < 4; h *= .5, ++k) {
      T2 = (T1 + h * ctqf(a, b, h)) * .5;
      S2 = (4 * T2 - T1) / 3;
      T1 = T2;
      if (k == 1) {
        S1 = S2;
        continue;
      };
      C2 = (16 * S2 - S1) / 15;
      if (k == 2) {
        C1 = C2;
        continue;
      };
      R1 = (64 * C2 - C1) / 63;
    }
    for (;; h /= 2, T1 = T2, S1 = S2, C1 = C2, R1 = R2)
      if (abs(R1 - (R2 = (64 * (C2 = (16 * (S2 = (4 * (T2 = (T1 + h * ctqf(a, b, h)) * .5) - T1) / 3) - S1) / 15) - C1) / 63)) < eps) break;
    return R2;
  }
};

}  // namespace tifa_libs::math

#endif