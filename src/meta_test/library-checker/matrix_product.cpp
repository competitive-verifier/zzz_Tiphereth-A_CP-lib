#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../../code/lalg/mat.hpp"

constexpr u32 MOD = 998244353;

#define GENTCs_mints
#define GENTCs_mintd0
using mat = tifa_libs::math::matrix<mint>;

int main() {
#define GENTCs_mintd1
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, m, k;
  std::cin >> n >> m >> k;
  mat a(n, m), b(m, k);
  std::cin >> a >> b;
  std::cout << a * b << '\n';
  return 0;
}
