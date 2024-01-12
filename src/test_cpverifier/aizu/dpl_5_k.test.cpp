#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_K"

#include "../../code/comb/ball_box_iim.hpp"
#include "../../code/math/mint.hpp"
#include "../../code/math/mintdata_s30.hpp"

constexpr u32 MOD = 1000000000 + 7;
using mintdata = tifa_libs::math::mintdata_s30<MOD>;
using mint = tifa_libs::math::mint<mintdata>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, k;
  std::cin >> n >> k;
  std::cout << tifa_libs::math::ball_box_iim<mint>(n, k) << '\n';
  return 0;
}
