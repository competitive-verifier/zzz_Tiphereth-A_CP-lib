#ifndef TIFALIBS_POLY_POLYNTT
#define TIFALIBS_POLY_POLYNTT

#include "../conv/conv_dft.hpp"
#include "../conv/ntt.hpp"
#include "poly.hpp"

namespace tifa_libs::math {

namespace polyntt_impl_ {
template <class mint>
struct cconv_ntt : public NTT<mint> {
  static constexpr auto ct_cat = ct_NTT;
  constexpr void conv(vec<mint> &l, vec<mint> const &r, u32 sz = 0) { l = conv_dft(*this, l, r, sz); }
};
}  // namespace polyntt_impl_

template <class mint>
using polyntt = poly<mint, polyntt_impl_::cconv_ntt<mint>>;

}  // namespace tifa_libs::math

#endif