#define AUTO_GENERATED
#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include "../../code/poly/poly_interp.hpp"

constexpr u32 MOD = 998244353;

#include "../../code/math/mint_ss.hpp"
#include "../../code/poly/polymtt.hpp"

using mint = tifa_libs::math::mint_ss<MOD>;
using poly = tifa_libs::math::polymtt<mint>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n;
  std::cin >> n;
  poly a(n), b(n);
  std::cin >> a >> b;
  std::cout << tifa_libs::math::poly_interp(a, b) << '\n';
  return 0;
}
