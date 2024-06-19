#define PROBLEM "https://judge.yosupo.jp/problem/directedmst/"

#include "../../code/graph/cle.hpp"
#include "../../code/io/ios_container.hpp"

int main() {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  u32 n, m, s;
  std::cin >> n >> m >> s;
  vec<edge_t<u64>> arcs(m);
  for (auto& [w, u, v] : arcs) std::cin >> u >> v >> w;
  auto res = tifa_libs::graph::cle(n, s, arcs);

  u64 cost = 0;
  vecu ans(n, -1_u32);
  ans[s] = s;
  for (auto [w, u, v] : res) cost += w, ans[v] = u;
  std::cout << cost << '\n'
            << ans << '\n';
  return 0;
}