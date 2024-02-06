#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex"

#include "../../code/conv/conv_minplus_cc.hpp"
#include "../../code/util/ios_container.hpp"

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, m;
  std::cin >> n >> m;
  vec<u32> a(n), b(m);
  std::cin >> a >> b;
  std::cout << tifa_libs::math::conv_minplus_cc(a, b) << '\n';
  return 0;
}
