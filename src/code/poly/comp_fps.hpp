#ifndef TIFALIBS_POLY_COMP_FPS
#define TIFALIBS_POLY_COMP_FPS

#include "inv_fps.hpp"

namespace tifa_libs::math {

// @return f(g(x))
template <class mint, class ccore>
CEXP poly<mint, ccore> comp_fps(poly<mint, ccore> f, poly<mint, ccore> g) {
  using poly_t = poly<mint, ccore>;
  ccore core2, core4;
  auto dfs = [&](auto&& dfs, vec<mint> b, u32 n, u32 h, u32 k) -> vec<mint> {
    if (!n) {
      poly_t _{b.begin(), b.begin() + k};
      _.data().push_back(1), _.reverse(), (_ = inv_fps(_)).reverse();
      poly_t g_ = f * _;
      vec<mint> a(k * h);
      flt_ (u32, i, 0, (u32)f.size()) a[k - i - 1] = g_[i + k];
      return a;
    }
    vec<mint> bb(k * h * 4), cc(k * h * 2);
    flt_ (u32, i, 0, k) std::copy(b.begin() + i * h, b.begin() + i * h + n + 1, bb.begin() + i * h * 2);
    bb[k * h * 2] += 1, core4.dif(bb);
    for (u32 i = 0; i < k * h * 4; i += 2) swap(bb[i], bb[i + 1]);
    flt_ (u32, i, 0, k * h * 2) cc[i] = bb[i * 2] * bb[i * 2 + 1];
    core2.dit(cc), cc[0] -= 1, b.assign(k * h, 0);
    flt_ (u32, i, 0, k * 2)
      fle_ (u32, j, 0, n / 2) b[i * h / 2 + j] = cc[i * h + j];
    vec<mint> a = dfs(dfs, b, n / 2, h / 2, k * 2), aa(k * h * 4);
    flt_ (u32, i, 0, k * 2)
      fle_ (u32, j, 0, n / 2) aa[(i * h + j) * 2 + n % 2] = a[i * h / 2 + j];
    core4.dif(aa);
    for (u32 i = 1; i < k * h * 4; i *= 2) std::reverse(bb.begin() + i, bb.begin() + i * 2);
    flt_ (u32, i, 0, k * h * 4) aa[i] *= bb[i];
    core4.dit(aa), a.assign(k * h, 0);
    flt_ (u32, i, 0, k) std::copy(aa.begin() + i * h * 2, aa.begin() + i * h * 2 + n + 1, a.begin() + i * h);
    return a;
  };
  const u32 n = max(g.size(), f.size()), h = std::bit_ceil(n);
  poly_t b(h);
  auto _ = f[0];
  g.resize(n), f.resize(n), f[0] = 0;
  flt_ (u32, i, 0, n) b[i] = -g[i];
  core2.bzr(h * 2), core4.bzr(h * 4);
  poly_t a(dfs(dfs, b.data(), n - 1, h, 1));
  return a.resize(n), a.reverse(), a[0] += _, a;
}

}  // namespace tifa_libs::math

#endif