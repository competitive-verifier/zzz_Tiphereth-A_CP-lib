#define AUTO_GENERATED
#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../code/io/fastio.hpp"
#include "../../code/poly/exp_fps.hpp"

CEXP u32 MOD = 998244353;

#include "../../code/math/mint_d63.hpp"
#include "../../code/poly/polymtt.hpp"

using mint = tifa_libs::math::mint_d63<-1>;
using poly = tifa_libs::math::polymtt<mint>;

int main() {
  mint::set_mod(MOD);
  u32 n;
  tifa_libs::fin >> n;
  poly p(n);
  tifa_libs::fin >> p.data();
  tifa_libs::fout << tifa_libs::math::exp_fps(p).data();
  return 0;
}
