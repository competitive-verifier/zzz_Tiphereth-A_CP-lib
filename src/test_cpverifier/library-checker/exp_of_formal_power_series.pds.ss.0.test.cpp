#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../code/math/mint_ss.hpp"
#include "../../code/poly/poly.hpp"
#include "../../code/poly/poly_exp.hpp"
#include "../../code/poly/polydata_s.hpp"
#include "../../code/util/fastio.hpp"

using mint = tifa_libs::math::mint_ss<998244353>;
using poly_t = tifa_libs::math::poly<tifa_libs::math::polydata_s<mint>>;

int main() {
  u32 n;
  tifa_libs::fin >> n;
  poly_t p(n);
  tifa_libs::fin >> p;
  tifa_libs::fout << tifa_libs::math::poly_exp(p).data();
  return 0;
}
