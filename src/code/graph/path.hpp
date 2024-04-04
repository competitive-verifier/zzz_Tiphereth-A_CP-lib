#ifndef TIFALIBS_GRAPH_PATH
#define TIFALIBS_GRAPH_PATH

#include "alist.hpp"

namespace tifa_libs::graph {

template <class G>
constexpr std::optional<vecu> path(G const &g, u32 from, u32 to) {
  vecu ret;
  bool failed = true;
  auto dfs = [&](auto &&dfs, u32 now, u32 fa) -> void {
    ret.push_back(now);
    if (now == to) {
      failed = false;
      return;
    }
    for (auto v : g.g[now]) {
      u32 to = 0;
      if constexpr (is_alist<G>) to = v;
      else to = v.first;
      if (to == fa) continue;
      dfs(dfs, to, now);
      if (!failed) return;
    }
    if (!failed) return;
    ret.pop_back();
  };

  dfs(dfs, from, -1_u32);
  if (failed) return {};
  return ret;
}

}  // namespace tifa_libs::graph

#endif