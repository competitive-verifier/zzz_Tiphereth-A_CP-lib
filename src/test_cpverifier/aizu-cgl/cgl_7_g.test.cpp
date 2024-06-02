#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_G"
#define ERROR 0.00001

#include "../../code/edh/discretization.hpp"
#include "../../code/geo2d/circle.hpp"
#include "../../code/geo2d/extan_cc.hpp"
#include "../../code/geo2d/intan_cc.hpp"
#include "../../code/geo2d/point.hpp"

using point = tifa_libs::geo::point<double>;
using circ = tifa_libs::geo::circle<double>;

int main() {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  circ c1, c2;
  std::cin >> c1 >> c2;
  auto exl = extan_CC(c1, c2), inl = intan_CC(c1, c2);
  vec<point> ans;
  if (exl.has_value()) {
    ans.push_back(exl.value().first.l);
    ans.push_back(exl.value().second.l);
  }
  if (inl.has_value()) {
    ans.push_back(inl.value().first.l);
    ans.push_back(inl.value().second.l);
  }
  ans = tifa_libs::uniq(ans);
  for (auto &i : ans) std::cout << i << '\n';
  return 0;
}
