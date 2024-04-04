#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "../../code/math/mint_s63.hpp"
#include "../../code/poly/mpe_fps.hpp"
#include "../../code/poly/polyntt.hpp"

using mint = tifa_libs::math::mint_s63<998244353>;
using poly = tifa_libs::math::polyntt<mint>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, m;
  std::cin >> n >> m;
  poly a(n), p(m);
  std::cin >> a >> p;
  std::cout << tifa_libs::math::mpe_fps(a, p) << '\n';
  return 0;
}
