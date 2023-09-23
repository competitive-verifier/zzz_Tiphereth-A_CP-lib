#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_B"

#include "../../code/math/qpow_mod.hpp"

constexpr tifa_libs::i64 MOD = 1'000'000'007;

int main() {
  tifa_libs::u64 m, n;
  std::cin >> m >> n;
  std::cout << tifa_libs::math::qpow_mod(m, n, MOD) << '\n';
  return 0;
}
