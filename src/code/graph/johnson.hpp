#ifndef TIFALIBS_GRAPH_JOHNSON
#define TIFALIBS_GRAPH_JOHNSON

#include "bm.hpp"
#include "dijkstra.hpp"

namespace tifa_libs::graph {
namespace johnson_impl_ {
}  // namespace johnson_impl_

//! edge: w u v
// @return dis, with dis[u][v] = minimum distance between u and v
template <class T>
constexpr std::optional<vvec<T>> johnson(u32 n, vec<std::tuple<T, u32, u32>> const &arcs, T const INF = std::numeric_limits<T>::max() / 2 - 1) {
  vvec<T> dis(n);
  alistw<T, false> fg(n);
  for (auto [w, u, v] : arcs) fg.add_arc(u, v, w);
  if constexpr (!is_sint_v<T>) {
    for (u32 i = 0; i < n; ++i) dis[i] = dijkstra(fg, i, fn_0, INF);
  } else {
    fg.g.push_back({});
    for (u32 i = 0; i < n; ++i) fg.add_arc(n, i, 0);
    auto h = bellman_ford(fg, n, fn_0, INF);
    if (!h) return {};
    using U = to_uint_t<T>;
    alistw<U, false> fg2(n);
    for (auto [w, u, v] : arcs) fg2.add_arc(u, v, U(w - h.value()[v] + h.value()[u]));
    for (u32 i = 0; i < n; ++i) {
      auto dis2 = dijkstra(fg2, i, fn_0, (U)INF);
      dis[i].resize(n);
      for (u32 j = 0; j < n; ++j) dis[i][j] = dis2[j] == (U)INF ? INF : (T)dis2[j] + h.value()[j] - h.value()[i];
    }
  }
  return dis;
}

}  // namespace tifa_libs::graph

#endif