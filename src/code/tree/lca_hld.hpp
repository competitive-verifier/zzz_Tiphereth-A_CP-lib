#ifndef TIFALIBS_TREE_LCA_HLD
#define TIFALIBS_TREE_LCA_HLD

#include "dfs_info.hpp"
#include "tree_top.hpp"

namespace tifa_libs::graph {

struct lca_hld {
  tree_dfs_info info;
  vec<u32> top;

  constexpr lca_hld(tree& tr) {
    info.reset_dfs_info<td_dep | td_fa>(tr);
    top = tree_top(tr, info);
  }

  constexpr u32 operator()(u32 u, u32 v) const {
    while (top[u] != top[v]) info.dep[top[u]] < info.dep[top[v]] ? v = info.fa[top[v]] : u = info.fa[top[u]];
    return info.dep[u] > info.dep[v] ? v : u;
  }
  constexpr ptt<vec<ptt<u32>>> getchain(u32 u, u32 v) {
    u32 lca = (*this)(u, v);
    vec<ptt<u32>> retu, retv;
    while (top[u] != top[lca]) {
      retu.emplace_back(u, top[u]), u = info.fa[top[u]];
    }
    retu.emplace_back(u, lca);
    while (top[v] != top[lca]) {
      retv.emplace_back(top[v], v), v = info.fa[top[v]];
    }
    if (v != lca) retv.emplace_back(info.maxson[lca], v);
    std::reverse(retv.begin(), retv.end());
    return {retu, retv};
  }
};

}  // namespace tifa_libs::graph

#endif