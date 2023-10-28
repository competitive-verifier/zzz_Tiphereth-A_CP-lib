#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_A"

#include "../../code/comb/ball_box_dda.hpp"
#include "../../code/math/mint_s30.hpp"

constexpr u32 MOD = 1000000000 + 7;
using mint = tifa_libs::math::mint_s30<MOD>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u64 n, k;
  std::cin >> n >> k;
  std::cout << tifa_libs::math::ball_box_dda<mint>(n, k) << '\n';
  return 0;
}
