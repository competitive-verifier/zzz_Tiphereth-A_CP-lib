#define PROBLEM "https://judge.yosupo.jp/problem/conversion_from_monomial_basis_to_newton_basis"

#include "../../code/io/fastio.hpp"
#include "../../code/poly/cbm2n_fps.hpp"

constexpr u32 MOD = 998244353;

#define GENTCs_pntt
#define GENTCs_pcntts

int main() {
  u32 n;
  tifa_libs::fin >> n;
  poly f(n);
  vec<mint> p(n);
  tifa_libs::fin >> f.data() >> p;
  tifa_libs::fout << tifa_libs::math::cbm2n_fps(f, p).data() << '\n';
  return 0;
}