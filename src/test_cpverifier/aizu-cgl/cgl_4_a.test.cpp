#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A"

#include "../../code/geo2d/cvh.hpp"

using cvh = tifa_libs::geo::cvh<double>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout << std::fixed << std::setprecision(0);
  u32 n;
  std::cin >> n;
  cvh p(n);
  std::cin >> p;
  p.init_nonstrict();
  std::cout << p.vs.size() << '\n';
  u32 now = 0;
  for (u32 i = 1; i < p.vs.size(); ++i)
    if (tifa_libs::is_lt(p[i].y, p[now].y) || (tifa_libs::is_eq(p[i].y, p[now].y) && tifa_libs::is_lt(p[i].x, p[now].x))) now = i;
  for (u32 i = now; i < p.vs.size(); ++i) std::cout << p[i] << '\n';
  if (now)
    flt_ (u32, i, 0, now) std::cout << p[i] << '\n';
  return 0;
}
