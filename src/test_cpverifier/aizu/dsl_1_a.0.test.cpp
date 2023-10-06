#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"

#include "../../code/ds/dsu_basic.hpp"

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t n, q;
  std::cin >> n >> q;
  tifa_libs::ds::dsu_basic dsu(n);
  for (size_t i = 0, op, u, v; i < q; ++i) {
    std::cin >> op >> u >> v;
    if (op)
      std::cout << dsu.in_same_group(u, v) << '\n';
    else
      dsu.merge(u, v);
  }
  return 0;
}