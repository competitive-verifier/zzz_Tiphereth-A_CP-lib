#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_directed"

#include "../../code/graph/euler_trail.hpp"

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 t;
  std::cin >> t;
  while (t--) {
    u32 n, m;
    std::cin >> n >> m;
    vecpt<u32> e(m);
    for (auto& [u, v] : e) std::cin >> u >> v;
    if (auto res = tifa_libs::graph::euler_trail<true>(n, e); !res.has_value()) {
      std::cout << "No\n";
    } else {
      std::cout << "Yes\n";
      auto et = res.value();
      for (u32 i = 0; i < et.size(); ++i) std::cout << et[i].first << " \n"[i + 1 == et.size()];
      if (et.size() == 1) std::cout << '\n';
      for (u32 i = 1; i < et.size(); ++i) std::cout << et[i].second << " \n"[i + 1 == et.size()];
    }
  }
  return 0;
}