#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse"

#include "../../code/math/mint.hpp"
#include "../../code/math/mintdata_s30.hpp"
#include "../../code/poly/polydata_s.hpp"
#include "../../code/poly/polysp_inv.hpp"

using mintdata = tifa_libs::math::mintdata_s30<998244353>;
using mint = tifa_libs::math::mint<mintdata>;
using pldt_t = tifa_libs::math::polydata_s<mint>;
using poly_t = tifa_libs::math::poly<pldt_t>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, k;
  std::cin >> n >> k;
  poly_t p(n);
  for (u32 i = 0, x; i < k; ++i) std::cin >> x >> p[x];
  std::cout << tifa_libs::math::polysp_inv(p);
  return 0;
}
