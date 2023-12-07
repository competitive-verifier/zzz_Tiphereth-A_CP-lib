#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "../../code/math/mint_d31.hpp"
#include "../../code/lalg/mat.hpp"
#include "../../code/lalg/mat_pow.hpp"

using mint = tifa_libs::math::mint_d31<-1>;
using mat = tifa_libs::math::matrix<mint>;

int main() {
  mint::set_mod(998244353);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u64 n, k;
  std::cin >> n >> k;
  mat a(n, n);
  std::cin >> a;
  std::cout << tifa_libs::math::pow(a, k);
  return 0;
}
