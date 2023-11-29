#ifndef TIFA_LIBS_UTIL_TSEARCH
#define TIFA_LIBS_UTIL_TSEARCH

#include "fp_const.hpp"
#include "traits.hpp"

namespace tifa_libs {

// F: T(I)
// @return $\argmin_{l\leq x\leq r}\{f\}$
template <class I, class F, class T = decltype(std::declval<F>()(std::declval<I>())), std::enable_if_t<is_arithm<I>::value>* = nullptr>
constexpr std::pair<I, T> tsearch(I l, I r, F f) {
  assert(l <= r);
  I ml, mr;
  T fl = f(l), fr = f(r), fml, fmr;
  using PT = std::conditional_t<std::is_floating_point_v<I>, I, double>;
  fml = f(ml = l + (r - l) * (1 - PHI<PT>)), fmr = f(mr = r - (r - l) * (1 - PHI<PT>));

  do {
    if constexpr (is_int<I>::value) {
      if (r - l < 8) {
        I x = l, fx = fl;
        if (fr < fx) x = r, fx = fr;
        if (fml < fx) x = ml, fx = fml;
        if (fmr < fx) x = mr, fx = fmr;
        for (I i = l + 1; i < r; ++i) {
          if (i == ml || i == mr) continue;
          if (T fi = f(i); fi < fx) x = i, fx = fi;
        }
        return {x, fx};
      }
    } else if ((r - l) / std::max({l, r, (I)1}) < EPS<I>) return {l, fl};
    if (fml < fmr) {
      r = mr, fr = fmr;
      mr = ml, fmr = fml;
      fml = f(ml = l - mr + r);
    } else {
      l = ml, fl = fml;
      ml = mr, fml = fmr;
      fmr = f(mr = r - ml + l);
    }
  } while (1);
}

}  // namespace tifa_libs

#endif