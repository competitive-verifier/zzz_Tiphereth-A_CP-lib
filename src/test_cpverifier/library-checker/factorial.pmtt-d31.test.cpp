#define AUTO_GENERATED
#define PROBLEM "https://judge.yosupo.jp/problem/factorial"

#include "../../code/math/fact_mint.hpp"

constexpr u32 MOD = 998244353;

#include "../../code/math/mint_d31.hpp"
#include "../../code/poly/polymtt.hpp"

using mint = tifa_libs::math::mint_d31<-1>;
using poly = tifa_libs::math::polymtt<mint>;

int main() {
  mint::set_mod(MOD);
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
