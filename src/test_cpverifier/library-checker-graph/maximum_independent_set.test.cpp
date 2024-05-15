#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set/"

#include "../../code/graph/cliques.hpp"

constexpr u32 N = 128;
using B = std::bitset<N>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, m;
  std::cin >> n >> m;
  arr<B, N> adj;
  for (u32 i = 0, u, v; i < m; ++i) {
    std::cin >> u >> v;
    adj[u][v] = adj[v][u] = 1;
  }
  for (u32 i = 0; i < n; ++i) {
    for (u32 j = 0; j < n; ++j)
      if (i != j) adj[i].flip(j);
  }
  B ans{};
  tifa_libs::graph::cliques(n, adj, [&](B R) {
    if (ans.count() < R.count()) ans = R;
  });
  auto ans_cnt = ans.count();
  std::cout << ans_cnt << '\n';
  for (u32 i = 0, cnt = 0; i < n; ++i)
    if (ans[i]) std::cout << i << " \n"[++cnt == (u32)ans_cnt];
  return 0;
}