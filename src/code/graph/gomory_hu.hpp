#ifndef TIFALIBS_GRAPH_GOMORY_HU
#define TIFALIBS_GRAPH_GOMORY_HU

#include "dinic.hpp"

namespace tifa_libs::graph {

#define FOR(i, a, b) for (u32 i = (a); i < (b); ++i)

// @return {w, u, v} edges in Gomory--Hu tree
template <class EW>
constexpr vec<std::tuple<EW, u32, u32>> gomory_hu(u32 n, vec<std::tuple<EW, u32, u32>> const& ed) {
  vec<u32> par(n);
  dinic<EW> D(n);
  vecpt<u32> ed_locs;
  for (auto [w, u, v] : ed) ed_locs.push_back(D.add(u, v, w, w));
  vec<std::tuple<EW, u32, u32>> ans;
  for (u32 i = 1; i < n; ++i) {
    for (auto [ed, loc] : ed_locs) {  // reset capacities
      auto &e = D.e[ed][loc], &e_rev = D.e[e.to][e.inv];
      e.w = e_rev.w = (e.w + e_rev.w) / 2;
    }
    ans.emplace_back(D(i, par[i]), i, par[i]);
    for (u32 j = i + 1; j < n; ++j)
      if (par[j] == par[i] && D.dep[j]) par[j] = i;
  }
  return ans;
}

}  // namespace tifa_libs::graph

#endif