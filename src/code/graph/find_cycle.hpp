#ifndef TIFALIBS_GRAPH_FIND_CYCLE
#define TIFALIBS_GRAPH_FIND_CYCLE

#include "alist.hpp"

namespace tifa_libs::graph {

template <bool directed, bool with_deg>
constexpr vecpt<u32> find_cycle(alist<with_deg> const& fg) {
  auto&& g = fg.g;

  for (u32 i = 0; i < g.size(); ++i)
    for (u32 j : g[i])
      if (i == j) return vecpt<u32>{{i, i}};

  vecu pidx(g.size(), -1_u32), vis(g.size(), 0);

  vecpt<u32> cycle;
  bool fin = false;
  auto dfs = [&](auto&& dfs, u32 now, u32 pval, u32 fa) -> u32 {
    pidx[now] = pval;
    vis[now] = 1;
    for (u32 to : g[now]) {
      if (fin) return -1_u32;
      if constexpr (!directed)
        if (to == fa) continue;
      if (pidx[to] == pidx[now]) {
        cycle.emplace_back(now, to);
        return to;
      }
      if (vis[to]) continue;
      if (u32 nxt = dfs(dfs, to, pval, now); ~nxt) {
        cycle.emplace_back(now, to);
        if (now == nxt) return (fin = true), -1_u32;
        return nxt;
      }
    }
    return pidx[now] = -1_u32;
  };

  for (u32 i = 0; i < g.size(); ++i) {
    if (vis[i]) continue;
    dfs(dfs, i, i, -1_u32);
    if (fin) {
      std::reverse(cycle.begin(), cycle.end());
      return cycle;
    }
  }
  return vecpt<u32>{};
}

}  // namespace tifa_libs::graph

#endif