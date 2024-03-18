#define PROBLEM "https://judge.yosupo.jp/problem/factorial"

#include "../../code/math/fact_mint.hpp"
#include "../../code/math/mint_s30.hpp"
#include "../../code/poly/polyntt32.hpp"

constexpr u64 MOD = 998244353;

using mint = tifa_libs::math::mint_s30<MOD>;
using poly = tifa_libs::math::polyntt32<mint>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 t;
  std::cin >> t;
  while (t--) {
    u64 n;
    std::cin >> n;
    std::cout << tifa_libs::math::fact_mint<poly>(n) << '\n';
  }
  return 0;
}
