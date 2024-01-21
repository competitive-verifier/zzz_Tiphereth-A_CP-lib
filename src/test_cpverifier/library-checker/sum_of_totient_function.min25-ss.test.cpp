#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include "../../code/math/mint.hpp"
#include "../../code/math/mintdata_ss.hpp"
#include "../../code/nt/min25_sieve.hpp"

using mintdata = tifa_libs::math::mintdata_ss<998244353>;
using mint = tifa_libs::math::mint<mintdata>;

mint f(u64 p, u64 c) {
  u64 res = 1;
  while (--c) res = res * p;
  return res * (p - 1);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u64 n;
  std::cin >> n;

  tifa_libs::math::min25_sieve<mint, f> min25(n);
  auto h0 = min25.sum_pk(0), h1 = min25.sum_pk(1);
  for (usz i = 0; i < h1.size(); ++i) h1[i] -= h0[i];
  std::cout << min25.run(h1) << '\n';
  return 0;
}
