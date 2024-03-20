#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include "../../code/io/fastio.hpp"
#include "../../code/math/mint_ss.hpp"
#include "../../code/poly/poly_sqrt.hpp"
#include "../../code/poly/polyntt.hpp"

using mint = tifa_libs::math::mint_ss<998244353>;
using poly = tifa_libs::math::polyntt<mint>;

int main() {
  u32 n;
  tifa_libs::fin >> n;
  poly p(n);
  tifa_libs::fin >> p.data();
  auto res = tifa_libs::math::poly_sqrt(p);
  if (!res.has_value()) tifa_libs::fout << "-1\n";
  else tifa_libs::fout << res.value().data() << '\n';
  return 0;
}