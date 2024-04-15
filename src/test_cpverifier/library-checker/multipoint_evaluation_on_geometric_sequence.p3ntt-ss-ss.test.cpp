#define AUTO_GENERATED
#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence"

#include "../../code/io/fastio.hpp"
#include "../../code/poly/czt_fps.hpp"

constexpr u32 MOD = 998244353;

#include "../../code/math/mint_ss.hpp"
#include "../../code/poly/poly3ntt.hpp"

using mint = tifa_libs::math::mint_ss<MOD>;
using mint1 = tifa_libs::math::mint_ss<167772161>;
using mint2 = tifa_libs::math::mint_ss<469762049>;
using mint3 = tifa_libs::math::mint_ss<754974721>;
using poly = tifa_libs::math::poly3ntt<mint, mint1, mint2, mint3>;

int main() {
  u32 n, m;
  mint a, r;
  tifa_libs::fin >> n >> m >> a >> r;
  poly f(n);
  tifa_libs::fin >> f.data();
  tifa_libs::fout << tifa_libs::math::czt_fps(f, r, m, a).data() << '\n';
  return 0;
}
