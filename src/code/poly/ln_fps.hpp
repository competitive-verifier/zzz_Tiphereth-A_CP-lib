#ifndef TIFALIBS_POLY_LN_FPS
#define TIFALIBS_POLY_LN_FPS

#include "deriv_fps.hpp"
#include "int_fps.hpp"
#include "inv_fps.hpp"

namespace tifa_libs::math {

template <class mint, class ccore>
constexpr poly<mint, ccore> ln_fps(poly<mint, ccore> const &p, u32 n = 0) {
  assert(p[0] == 1);
  if (!n) n = p.size();
  auto _ = deriv_fps(p).pre(n);
  _.conv(inv_fps(p, n));
  return int_fps(_).pre(n);
}

}  // namespace tifa_libs::math

#endif