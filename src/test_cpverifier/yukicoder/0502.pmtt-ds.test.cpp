#define AUTO_GENERATED
#define PROBLEM "https://yukicoder.me/problems/no/502"

#include "../../code/math/fact_mint.hpp"

constexpr u64 MOD = 1000000007;

#include "../../code/math/mint_ds.hpp"
#include "../../code/poly/polymtt.hpp"

using mint = tifa_libs::math::mint_ds<-1>;
using poly = tifa_libs::math::polymtt<mint>;

int main() {
  mint::set_mod(MOD);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u64 n;
  std::cin >> n;
  std::cout << tifa_libs::math::fact_mint<poly>(n) << '\n';
  return 0;
}