#ifndef TIFALIBS_POLY_COMP_FPSSPS
#define TIFALIBS_POLY_COMP_FPSSPS

#include "../comb/gen_fact.hpp"
#include "../comb/gen_ifact.hpp"
#include "../conv/conv_subset.hpp"
#include "tsh_fps.hpp"

namespace tifa_libs::math {

template <class mint, class ccore, u32 N = 21>
vec<mint> comp_fpssps(u32 n, poly<mint, ccore> f, vec<mint> g, vecu64 const &fact, vecu64 const &ifact) {
  assert(n <= N);
  static conv_subset<mint, N> ss;
  if (!f.size()) return vec<mint>(1 << n);
  if (g[0] != 0) {
    f = tsh_fps(f, g[0], fact, ifact);
    g[0] = 0;
  }
  f.resize(n + 1);
  g.resize(1 << n);
  for (u32 i = 0; i <= n; ++i) f[i] *= fact[i];
  v3ec<mint> h(n + 1, vvec<mint>(n + 1, vec<mint>{}));
  for (u32 i = 0; i <= n; ++i) h[0][i] = {f[i]};
  for (u32 k = 1; k <= n; ++k) {
    auto A = ss.lift({g.begin() + (1 << (k - 1)), g.begin() + (1 << k)});
    ss.zeta(A);
    for (u32 j = 0; j <= n - k; ++j) {
      h[k][j] = h[k - 1][j];
      auto B = ss.lift(h[k - 1][j + 1]);
      ss.zeta(B);
      ss.prod(B, A);
      ss.mobius(B);
      auto c = ss.unlift(B);
      std::ranges::copy(c, std::back_inserter(h[k][j]));
    }
  }
  return h[n][0];
}
template <class mint, class ccore, u32 N = 21>
constexpr auto comp_fpssps(u32 n, poly<mint, ccore> const &f, vec<mint> const &g) { return comp_fpssps<mint, ccore, N>(n, f, g, gen_fact((u32)f.size() + 1, mint::mod()), gen_ifact((u32)f.size() + 1, mint::mod())); }

}  // namespace tifa_libs::math

#endif