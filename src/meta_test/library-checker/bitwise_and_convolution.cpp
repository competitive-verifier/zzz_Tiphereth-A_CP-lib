#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "../../code/conv/conv_and.hpp"
#include "../../code/io/fastio.hpp"

constexpr u32 MOD = 998244353;

#define GENTCs_mints
#define GENTCs_mintd0

int main() {
#define GENTCs_mintd1
  u32 n;
  tifa_libs::fin >> n;
  vec<mint> a(1 << n), b(1 << n);
  for (auto &i : a) tifa_libs::fin >> i;
  for (auto &i : b) tifa_libs::fin >> i;
  tifa_libs::fout << tifa_libs::math::conv_and(a, b) << '\n';
  return 0;
}
