#ifndef TIFALIBS_GEO2D_AUNION_CS
#define TIFALIBS_GEO2D_AUNION_CS

#include "ins_cc.hpp"
#include "rel_cc.hpp"

namespace tifa_libs::geo {

// @return ans, which ans[i] means area covered at least i+1 times
template <std::floating_point FP>
CEXP vec<FP> aunion_Cs(vec<circle<FP>> CR cs) {
  using arc_t = std::tuple<point<FP>, FP, FP, FP>;
  u32 n = (u32)cs.size();
  vvec<arc_t> arcs(n);
  auto cut = [&](circle<FP> CR ci, u32 i) {
    vecp<FP, int> evt;
    evt.emplace_back(-pi_v<FP>, 0), evt.emplace_back(pi_v<FP>, 0);
    int init = 0;
    flt_ (u32, j, 0, n) {
      if (i == j) continue;
      circle<FP> CR cj = cs[j];
      if (auto _ = relation_CC(ci, cj); is_lt(ci.r, cj.r) && (_ == lyingin_cc || _ == touchin_cc)) ++init;
      auto inters = ins_CC(ci, cj);
      if (!inters.has_value()) continue;
      if (inters.value().first == inters.value().second) evt.emplace_back((inters.value().first - ci.o).arg(), 0);
      else {
        point<FP> dl = inters.value().first - ci.o, dr = inters.value().second - ci.o;
        FP argl = dl.arg(), argr = dr.arg();
        if (is_eq(argl, -pi_v<FP>)) argl = pi_v<FP>;
        if (is_eq(argr, -pi_v<FP>)) argr = pi_v<FP>;
        if (is_gt(argl, argr)) {
          evt.emplace_back(argl, 1), evt.emplace_back(pi_v<FP>, -1);
          evt.emplace_back(-pi_v<FP>, 1), evt.emplace_back(argr, -1);
        } else evt.emplace_back(argl, 1), evt.emplace_back(argr, -1);
      }
    }
    std::ranges::sort(evt);
    int sum = init;
    flt_ (u32, i, 0, (u32)evt.size()) {
      sum += evt[i].second;
      if (!is_eq(evt[i].first, evt[i + 1].first)) arcs[(u32)sum].emplace_back(ci.o, ci.r, evt[i].first, evt[i + 1].first);
      if (is_eq(evt[i + 1].first, pi_v<FP>)) break;
    }
  };
  auto oint = [](arc_t CR arc) {
    if (auto [cc, cr, l, r] = arc; is_eq(r - l, pi_v<FP> * 2)) return 2 * pi_v<FP> * cr * cr;
    else return cr * (cr * (r - l) + cc.x * (std::sin(r) - std::sin(l)) - cc.y * (std::cos(r) - std::cos(l)));
  };
  flt_ (u32, i, 0, n) cut(cs[i], i);
  auto eq = [](arc_t CR u, arc_t CR v) {
    auto [u1, u2, u3, u4] = u;
    auto [v1, v2, v3, v4] = v;
    return u1 == v1 && is_eq(u2, v2) && is_eq(u3, v3) && is_eq(u4, v4);
  };
  vec<FP> ans(n);
  flt_ (u32, i, 0, n) {
    FP sum = 0;
    std::ranges::sort(arcs[i]);
    u32 cnt = 0;
    flt_ (u32, j, 0, (u32)arcs[i].size())
      if (j > 0 && eq(arcs[i][j], arcs[i][j - 1])) arcs[i + (++cnt)].push_back(arcs[i][j]);
      else cnt = 0, sum += oint(arcs[i][j]);
    ans[i] = sum / 2;
  }
  return ans;
}

}  // namespace tifa_libs::geo

#endif