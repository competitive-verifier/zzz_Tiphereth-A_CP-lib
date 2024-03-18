#define PROBLEM "https://judge.yosupo.jp/problem/conversion_from_monomial_basis_to_newton_basis"

#include "../../code/math/mint.hpp"
#include "../../code/math/mintdata_s30.hpp"
#include "../../code/poly/poly.hpp"
#include "../../code/poly/poly_cbm2n.hpp"
#include "../../code/poly/polydata_scntt.hpp"
#include "../../code/io/fastio.hpp"

using mintdata = tifa_libs::math::mintdata_s30<998244353>;
using mint = tifa_libs::math::mint<mintdata>;
using poly_t = tifa_libs::math::poly<tifa_libs::math::polydata_scntt<mint>>;

int main() {
  u32 n;
  tifa_libs::fin >> n;
  poly_t f(n);
  vec<mint> p(n);
  tifa_libs::fin >> f.data() >> p;
  tifa_libs::fout << tifa_libs::math::poly_cbm2n(f, p).data() << '\n';
  return 0;
}
