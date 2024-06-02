#define AUTO_GENERATED
#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "../../code/conv/conv_gcd.hpp"

CEXP u32 MOD = 998244353;

#include "../../code/math/mint_s63.hpp"

using mint = tifa_libs::math::mint_s63<MOD>;

int main() {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  u32 n;
  std::cin >> n;
  vec<mint> a(n + 1), b(n + 1);
  fle_ (u32, i, 1, n) std::cin >> a[i];
  fle_ (u32, i, 1, n) std::cin >> b[i];
  auto c = tifa_libs::math::conv_gcd(a, b);
  flt_ (u32, i, 1, (u32)c.size()) std::cout << c[i] << " \n"[i + 1 == c.size()];
  return 0;
}
