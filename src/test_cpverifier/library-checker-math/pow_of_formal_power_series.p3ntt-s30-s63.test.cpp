#define AUTO_GENERATED
#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "../../code/io/fastio.hpp"
#include "../../code/poly/pow_fps.hpp"

constexpr u32 MOD = 998244353;

#include "../../code/math/mint_s30.hpp"
#include "../../code/math/mint_s63.hpp"
#include "../../code/poly/poly3ntt.hpp"

using mint = tifa_libs::math::mint_s63<MOD>;
using mint1 = tifa_libs::math::mint_s30<167772161>;
using mint2 = tifa_libs::math::mint_s30<469762049>;
using mint3 = tifa_libs::math::mint_s30<754974721>;
using poly = tifa_libs::math::poly3ntt<mint, mint1, mint2, mint3>;

int main() {
  u32 n;
  u64 m;
  tifa_libs::fin >> n >> m;
  poly a(n);
  tifa_libs::fin >> a.data();
  tifa_libs::fout << tifa_libs::math::pow_fps(a, m).data() << '\n';
  return 0;
}