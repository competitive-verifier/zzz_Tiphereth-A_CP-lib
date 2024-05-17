#ifndef TIFALIBS_GRAPH_DINIC
#define TIFALIBS_GRAPH_DINIC

#include "bm.hpp"
#include "dijkstra.hpp"

namespace tifa_libs::graph {

template <class W = u32, class C = i32>
class ssp {
  struct TIFA {
    u32 to, inv;
    W w;
    C c;
  };
  const u32 N, S, T;
  vec<W> flow;
  vecpt<u32> pre;

  template <class EW>
  bool sssp(EW inflow) {
    using SW = std::make_signed_t<EW>;
    vec<SW> dis(N, std::numeric_limits<SW>::max() / 2 - 1);
    vecb inq(N);
    std::queue<u32> q({S});
    dis[S] = 0, flow[S] = W(inflow), flow[T] = 0, inq[S] = 1;
    while (!q.empty()) {
      u32 u = q.front();
      q.pop(), inq[u] = 0;
      for (u32 i = 0; i < e[u].size(); ++i) {
        auto v = e[u][i];
        if (dis[u] + v.c < dis[v.to] && v.w) {
          dis[v.to] = dis[u] + v.c;
          if (!inq[v.to]) q.push(v.to), inq[v.to] = 1;
          flow[v.to] = min(flow[u], v.w);
          pre[v.to] = {u, i};
        }
      }
    }
    return flow[T];
  }
  template <class EW, class EC>
  CEXP void update(EW& retflow, EC& retcost) {
    retflow += flow[T];
    for (u32 u = T; u != S; u = pre[u].first) {
      e[pre[u].first][pre[u].second].w -= flow[T];
      e[u][e[pre[u].first][pre[u].second].inv].w += flow[T];
      retcost += EC(flow[T]) * e[pre[u].first][pre[u].second].c;
    }
  }

 public:
  vvec<TIFA> e;

  CEXP ssp(u32 n, u32 s, u32 t) : N(n), S(s), T(t), flow(n), pre(n), e(n) {}

  CEXP void add(u32 u, u32 v, cT_(W) w, cT_(C) c) {
    u32 temu = u32(e[u].size()), temv = u32(e[v].size());
    e[u].push_back({v, temv, w, c}), e[v].push_back({u, temu, 0, -c});
  }
  template <class EW = u64, class EC = i64>
  CEXP std::pair<EW, EC> get(EW inflow = std::numeric_limits<EW>::max()) {
    EW retflow = 0;
    EC retcost = 0;
    bool flag = inflow == std::numeric_limits<W>::max();
    while (sssp(flag ? inflow : inflow - retflow)) update(retflow, retcost);
    return {retflow, retcost};
  }
};

}  // namespace tifa_libs::graph

#endif