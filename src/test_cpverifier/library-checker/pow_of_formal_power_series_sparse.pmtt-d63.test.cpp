#define AUTO_GENERATED
#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"

#include "../../code/poly/polysp_pow.hpp"

constexpr u32 MOD = 998244353;

#include "../../code/math/mint_d63.hpp"
#include "../../code/poly/polymtt.hpp"

using mint = tifa_libs::math::mint_d63<-1>;
using poly = tifa_libs::math::polymtt<mint>;

int main() {
  mint::set_mod(MOD);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, k;
  u64 m;
  std::cin >> n >> k >> m;
  poly p(n);
  for (u32 i = 0, x; i < k; ++i) std::cin >> x >> p[x];
  std::cout << tifa_libs::math::polysp_pow(p, m);
  return 0;
}
