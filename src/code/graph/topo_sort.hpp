#ifndef TIFALIBS_GRAPH_TOPO_SORT
#define TIFALIBS_GRAPH_TOPO_SORT

#include "../util/traits.hpp"

namespace tifa_libs::graph {

//! return empty vector if @g is not DAG
template <class G>
requires(adjlist_c<G> && !adjlistw_c<G>)
CEXP vecu topo_sort(G CR g) {
  const u32 n = g.size();
  vecb vis(n), _(n);
  vecu ans;
  auto dfs = [&](auto&& dfs, u32 i) -> bool {
    if (_[i]) return false;
    if (!vis[i]) {
      for (_[i] = true; auto to : g[i])
        if (!dfs(dfs, (u32)to)) return false;
      vis[i] = true, ans.push_back(i), _[i] = false;
    }
    return true;
  };
  flt_ (u32, i, 0, n)
    if (!vis[i] && !dfs(dfs, i)) return {};
  return std::ranges::reverse(ans), ans;
}

}  // namespace tifa_libs::graph

#endif