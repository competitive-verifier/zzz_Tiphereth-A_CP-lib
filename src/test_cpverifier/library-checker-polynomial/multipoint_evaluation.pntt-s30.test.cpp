#define AUTO_GENERATED
#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "../../code/io/fastio.hpp"
#include "../../code/poly/mpe_fps.hpp"

CEXP u32 MOD = 998244353;

#include "../../code/math/mint.hpp"
#include "../../code/math/mint_s30.hpp"
#include "../../code/poly/polyntt.hpp"

using mint = tifa_libs::math::mint<tifa_libs::math::mint_s30, MOD>;
using poly = tifa_libs::math::polyntt<mint>;

int main() {
  u32 n, m;
  tifa_libs::fin >> n >> m;
  poly a(n), p(m);
  tifa_libs::fin >> a >> p;
  tifa_libs::fout << tifa_libs::math::mpe_fps(a, p) << '\n';
  return 0;
}
