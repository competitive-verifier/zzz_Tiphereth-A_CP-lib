#define PROBLEM "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"

#include "../../code/math/mint_s30.hpp"
#include "../../code/poly/poly_ctsh.hpp"
#include "../../code/poly/polyntt.hpp"

using mint = tifa_libs::math::mint_s30<998244353>;
using poly = tifa_libs::math::polyntt<mint>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, m, c;
  std::cin >> n >> m >> c;
  poly a(n);
  std::cin >> a;
  std::cout << tifa_libs::math::poly_ctsh<poly, mint>(a, c, m) << '\n';
  return 0;
}
