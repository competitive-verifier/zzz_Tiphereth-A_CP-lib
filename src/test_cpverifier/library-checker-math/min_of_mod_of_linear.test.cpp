#define PROBLEM "https://judge.yosupo.jp/problem/min_of_mod_of_linear"

#include "../../code/math/min_mod_linear.hpp"

int main() {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  u32 t;
  std::cin >> t;
  while (t--) {
    u32 n, m, a, b;
    std::cin >> n >> m >> a >> b;
    std::cout << tifa_libs::math::min_mod_linear(n, m, a, b) << '\n';
  }
  return 0;
}
