#define AUTO_GENERATED
#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n"

#include "../../code/comb/stirling1_smallp.hpp"

#include "../../code/math/mint_d31.hpp"

using mint = tifa_libs::math::mint_d31<-1>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 t, MOD;
  std::cin >> t >> MOD;
  mint::set_mod(MOD);
  tifa_libs::math::Stirling1<mint> s;
  while (t--) {
    u64 n, k;
    std::cin >> n >> k;
    std::cout << s(n, k) << '\n';
  }
  return 0;
}
