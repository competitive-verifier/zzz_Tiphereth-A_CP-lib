#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"

#include "../../code/conv/conv_minplus_ca.hpp"
#include "../../code/io/ios_container.hpp"

int main() {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  u32 n, m;
  std::cin >> n >> m;
  vecu a(n), b(m);
  std::cin >> a >> b;
  std::cout << tifa_libs::math::conv_minplus_ca(a, b) << '\n';
  return 0;
}
