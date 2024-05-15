#ifndef TIFALIBS_GEO2D_COVERAGE_RECT_MIN_AREA
#define TIFALIBS_GEO2D_COVERAGE_RECT_MIN_AREA

#include "cvh.hpp"
#include "dot.hpp"

namespace tifa_libs::geo {

// Coverage rectangle with min area
template <class FP>
CEXP polygon<FP> coverage_rect_min_area(cvh<FP> CR ch) {
  u32 n = ch.size();
  if (n == 0) return ch;
  if (n == 1) return polygon{vec<point<FP>>{ch[0], ch[0], ch[0], ch[0]}};
  if (n == 2) return polygon{vec<point<FP>>{ch[0], ch[0], ch[1], ch[1]}};
  FP ans = std::numeric_limits<FP>::max();
  u32 r = 1, p = 1, q = 1;
  u32 ans_i = 0, ans_r = 0, ans_p = 0, ans_q = 0;
  flt_ (u32, i, 0, n) {
    while (!is_neg(cross(ch.vs[i], ch.vs[ch.next(i)], ch.vs[ch.next(r)]) - cross(ch.vs[i], ch.vs[ch.next(i)], ch.vs[r]))) r = ch.next(r);
    while (!is_neg(dot(ch.vs[i], ch.vs[ch.next(i)], ch.vs[ch.next(p)]) - dot(ch.vs[i], ch.vs[ch.next(i)], ch.vs[p]))) p = ch.next(p);
    if (i == 0) q = p;
    while (!is_pos(dot(ch.vs[i], ch.vs[ch.next(i)], ch.vs[ch.next(q)]) - dot(ch.vs[i], ch.vs[ch.next(i)], ch.vs[q]))) q = ch.next(q);
    if (FP _ = cross(ch.vs[i], ch.vs[ch.next(i)], ch.vs[r]) * (dot(ch.vs[i], ch.vs[ch.next(i)], ch.vs[p]) - dot(ch.vs[i], ch.vs[ch.next(i)], ch.vs[q])) / (ch.vs[i] - ch.vs[ch.next(i)]).norm2(); ans > _) ans = _, ans_i = i, ans_r = r, ans_p = p, ans_q = q;
  }
  point dir = line{ch[ans_i], ch[ch.next(ans_i)]}.direction(), vdir = rot90(dir);
  line li{ch[ans_i], ch[ans_i] + dir}, lp{ch[ans_p], ch[ans_p] + vdir}, lr{ch[ans_r], ch[ans_r] + dir}, lq{ch[ans_q], ch[ans_q] + vdir};
  polygon ret{vec<point<FP>>{ins_LL(li, lp), ins_LL(lp, lr), ins_LL(lr, lq), ins_LL(lq, li)}};
  return ret;
}

}  // namespace tifa_libs::geo

#endif