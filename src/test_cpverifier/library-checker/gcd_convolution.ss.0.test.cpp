#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "../../code/conv/conv_gcd.hpp"
#include "../../code/math/mint_ss.hpp"

using mint = tifa_libs::math::mint_ss<998244353>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n;
  std::cin >> n;
  vec<mint> a(n + 1), b(n + 1);
  for (size_t i = 1; i <= n; ++i) std::cin >> a[i];
  for (size_t i = 1; i <= n; ++i) std::cin >> b[i];
  auto c = tifa_libs::math::conv_gcd(a, b);
  for (size_t i = 1; i < c.size(); ++i) std::cout << c[i] << " \n"[i + 1 == c.size()];
  return 0;
}
