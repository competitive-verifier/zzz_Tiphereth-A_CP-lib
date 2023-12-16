#ifndef TIFALIBS_POLY_POLY_CTSH
#define TIFALIBS_POLY_POLY_CTSH

#include "../comb/gen_ifact.hpp"
#include "poly.hpp"

namespace tifa_libs::math {

template <class T>
constexpr poly<T> poly_ctsh(poly<T> const &f, typename T::value_type c, vec<u64> const &ifact, u32 m = 0) {
  u32 n = f.size(), k = f.size() - 1;
  if (!m) m = n;
  using mint = typename T::value_type;
  u64 t = c.val();
  if (t <= k) {
    poly<T> ret(m);
    u32 ptr = 0;
    for (u32 i = (u32)t; i <= k && ptr < m; ++i) ret[ptr++] = f[i];
    if (k + 1 < t + m) {
      auto suf = poly_ctsh(f, k + 1, ifact, m - ptr);
      for (u32 i = k + 1; i < t + m; ++i) ret[ptr++] = suf[i - (k + 1)];
    }
    return ret;
  }
  if (t + m > mint::mod()) {
    auto pref = poly_ctsh(f, t, ifact, u32(mint::mod() - t)), suf = poly_ctsh(f, 0, ifact, m - pref.size());
    std::copy(suf.data().begin(), suf.data().end(), std::back_inserter(pref.data()));
    return pref;
  }
  poly<T> d(k + 1);
  for (u32 i = 0; i <= k; ++i) {
    d[i] = ifact[i];
    (d[i] *= ifact[k - i]) *= f[i];
    if ((k - i) & 1) d[i] = -d[i];
  }
  poly<T> h(m + k);
  for (u32 i = 0; i < m + k; ++i) h[i] = mint(t - k + i).inv();
  auto dh = d * h;
  poly<T> ret(m);
  mint cur = t;
  for (u32 i = 1; i <= k; ++i) cur *= t - i;
  for (u32 i = 0; i < m; ++i) {
    ret[i] = cur * dh[k + i];
    (cur *= t + i + 1) *= h[i];
  }
  return ret;
}
template <class T>
constexpr poly<T> poly_ctsh(poly<T> const &f, typename T::value_type c, u32 m = 0) { return poly_ctsh(f, c, gen_ifact(f.size(), T::value_type::mod()), m); }

}  // namespace tifa_libs::math

#endif