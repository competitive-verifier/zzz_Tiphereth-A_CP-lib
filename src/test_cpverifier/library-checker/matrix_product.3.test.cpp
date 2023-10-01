#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../../code/math/mint_sd.hpp"
#include "../../code/matrix/mat.hpp"

using mint = tifa_libs::math::mint_sd<-1>;
using mat = tifa_libs::math::matrix<mint>;

int main() {
  mint::set_mod(998244353);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  tifa_libs::u64 n, m, k;
  std::cin >> n >> m >> k;
  mat a(n, m), b(m, k);
  std::cin >> a >> b;
  std::cout << a * b << '\n';
  return 0;
}