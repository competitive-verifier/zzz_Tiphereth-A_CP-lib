#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "../../code/conv/conv_gcd.hpp"
#include "../../code/math/mint_ss.hpp"
#include "../../code/util/ios_container.hpp"

using mint = tifa_libs::math::mint_ss<998244353>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n;
  std::cin >> n;
  vec<mint> a(n + 1), b(n + 1);
  for (usz i = 1; i <= n; ++i) std::cin >> a[i];
  for (usz i = 1; i <= n; ++i) std::cin >> b[i];
  std::cout << tifa_libs::math::conv_gcd(a, b) << '\n';
  return 0;
}
