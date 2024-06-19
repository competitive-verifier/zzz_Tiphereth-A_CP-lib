#ifndef TIFALIBS_GRAPH_CHORDAL
#define TIFALIBS_GRAPH_CHORDAL

#include "alist.hpp"

namespace tifa_libs::graph {

template <bool with_deg = false>
class chordal {
  alist<with_deg> CR g;
  vecu deg;

 public:
  vecu peo, rnk;

  // @param g simple UNDIRECTED graph
  //! g.g[i] MUST be sorted
  CEXPE chordal(alist<with_deg> CR g) : g(g), deg(g.g.size()), peo(g.g.size()), rnk(g.g.size()) {
    for (auto& i : g.g) assert(std::ranges::is_sorted(i));
    const u32 n = (u32)g.g.size();
    vecu l(n * 2 + 1), r, idx(n);
    std::iota(l.begin(), l.end(), 0), r = l;
    auto ins = [&](u32 i, u32 j) { r[l[i] = l[j]] = i, r[l[j] = i] = j; };
    auto del = [&](u32 i) { r[l[i]] = r[i], l[r[i]] = l[i]; };
    flt_ (u32, i, 0, n) ins(i, n);
    u32 li = n;
    flt_ (u32, i, 0, n) {
      ++li;
      while (l[li] == li) --li;
      u32 v = l[li];
      for (idx[v] = -1_u32, del(v); u32 to : g.g[v])
        if (~idx[to]) ++deg[to], del(to), ins(to, n + (++idx[to]));
      peo[i] = v;
    }
    std::ranges::reverse(peo);
    flt_ (u32, i, 0, n) rnk[peo[i]] = i;
  }

  template <bool find_indcycle = false>
  std::conditional_t<find_indcycle, std::optional<vecu>, bool> is_chordal_graph() const {
    for (u32 u : peo) {
      vecu s;
      for (s.reserve(g.g[u].size()); auto v : g.g[u])
        if (rnk[u] < rnk[v])
          if (s.push_back(v); rnk[s.back()] < rnk[s[0]]) swap(s[0], s.back());
      flt_ (u32, j, 1, (u32)s.size())
        if (!std::ranges::binary_search(g.g[s[0]], s[j])) {
          if CEXP (!find_indcycle) return false;
          else {
            u32 x = s[j], y = s[0], z = u;
            vecu pre(peo.size(), -1_u32);
            std::queue<u32> q({x});
            while (!q.empty()) {
              u32 t = q.front();
              if (q.pop(); std::ranges::binary_search(g.g[t], y)) {
                pre[y] = t;
                vecu path = {y};
                while (path.back() != x) path.push_back(pre[path.back()]);
                return path.push_back(z), path;
              }
              for (u32 u : g.g[t])
                if (u != z && !std::ranges::binary_search(g.g[u], z) && !~pre[u]) pre[u] = t, q.push(u);
            }
          }
        }
    }
    if CEXP (find_indcycle) return {};
    else return true;
  }
  // @return {x}, which $\{x\}+N(x)$ be a maximal clique
  CEXP vecu maximal_cliques() const {
    vecu fst(peo.size(), -1_u32), n(peo.size()), res;
    for (u32 u : peo)
      for (auto v : g.g[u])
        if (rnk[u] < rnk[v])
          if (++n[u]; !~fst[u] || rnk[v] < rnk[fst[u]]) fst[u] = v;
    for (vecb vis(peo.size()); u32 u : peo) {
      if (vis[u]) continue;
      res.push_back(u), vis[fst[u]] = n[u] > n[fst[u]];
    }
    return res;
  }
  CEXP u32 chromatic_number() const { return *std::ranges::max_element(deg) + 1; }
  CEXP vecu max_independent_set() const {
    vecu res;
    for (vecb vis(peo.size()); u32 u : peo) {
      if (vis[u]) continue;
      for (res.push_back(u); u32 v : g.g[u]) vis[v] = true;
    }
    return res;
  }
};

}  // namespace tifa_libs::graph

#endif