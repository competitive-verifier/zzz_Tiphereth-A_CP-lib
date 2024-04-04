#ifndef TIFALIBS_COMB_GEN_BALL_BOX_II
#define TIFALIBS_COMB_GEN_BALL_BOX_II

#include "../poly/exp_fps.hpp"
#include "gen_inv.hpp"

namespace tifa_libs::math {

// f = \\prod_{i=1}^m 1/(1-x^i), deg(f) = n
template <class poly>
constexpr poly gen_ball_box_ii(u32 m, u32 n, vecu64 const& inv) {
  poly f(n + 1);
  for (u32 i = 1; i <= m; ++i)
    for (u32 k = 1; k <= n / i; ++k) f[i * k] += inv[k];
  return exp_fps(f);
}

// f = \\prod_{i=1}^m 1/(1-x^i), deg(f) = n
template <class poly>
constexpr poly gen_ball_box_ii(u32 m, u32 n) { return gen_ball_box_ii<poly>(m, n, gen_inv(n + 1, poly::value_type::mod())); }

}  // namespace tifa_libs::math

#endif