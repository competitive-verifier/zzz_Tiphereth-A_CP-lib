#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_G"

#include "../../code/comb/ball_box_dia.hpp"
#include "../../code/comb/gen_bell.hpp"

constexpr u32 MOD = 1000000000 + 7;

#define GENTCs_pmttd0
#define GENTCs_p3nttd0

int main() {
#define GENTCs_pmttd1
#define GENTCs_p3nttd1
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, k;
  std::cin >> n >> k;
  if (k >= n) std::cout << tifa_libs::math::gen_bell<poly>(n)[n] << '\n';  // unnecessary, just for test
  else std::cout << tifa_libs::math::ball_box_dia<poly>(n, k) << '\n';
  return 0;
}
