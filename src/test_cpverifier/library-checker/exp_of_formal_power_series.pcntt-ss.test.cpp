#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../code/io/fastio.hpp"
#include "../../code/math/mint_ss.hpp"
#include "../../code/poly/poly_exp.hpp"
#include "../../code/poly/polycntt.hpp"

using mint = tifa_libs::math::mint_ss<998244353>;
using poly = tifa_libs::math::polycntt<mint>;

int main() {
  u32 n;
  tifa_libs::fin >> n;
  poly p(n);
  tifa_libs::fin >> p.data();
  tifa_libs::fout << tifa_libs::math::poly_exp(p).data();
  return 0;
}
