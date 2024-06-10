#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_G"

#include "../../code/opt/knapsack_mixed.hpp"

int main() {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  u32 n, w;
  std::cin >> n >> w;
  tifa_libs::opt::knapsack_mixed<i32> kn(w);
  for (u32 i = 0; i < n; ++i) {
    i32 v;
    u32 w, m;
    std::cin >> v >> w >> m;
    kn.add(w, v, m);
  }
  std::cout << *std::ranges::max_element(kn.result()) << '\n';
  return 0;
}
