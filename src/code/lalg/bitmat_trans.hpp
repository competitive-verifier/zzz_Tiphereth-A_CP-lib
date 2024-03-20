#ifndef TIFALIBS_LALG_BITMAT_TRANS
#define TIFALIBS_LALG_BITMAT_TRANS

#include "bitmat.hpp"

namespace tifa_libs::math {

template <usz R, usz C>
constexpr bitmat<C, R> bitmat_trans(bitmat<R, C> const &bmat) {
  bitmat<C, R> ret;
  for (usz r = 0; r < R; ++r)
    for (u32 c = 0; c < C; ++c) ret[c][r] = bmat[r][c];
  return ret;
}

}  // namespace tifa_libs::math

#endif