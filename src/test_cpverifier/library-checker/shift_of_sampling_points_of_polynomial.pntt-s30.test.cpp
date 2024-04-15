#define AUTO_GENERATED
#define PROBLEM "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"

#include "../../code/io/fastio.hpp"
#include "../../code/poly/ctsh_fps.hpp"

constexpr u32 MOD = 998244353;

#include "../../code/math/mint_s30.hpp"
#include "../../code/poly/polyntt.hpp"

using mint = tifa_libs::math::mint_s30<MOD>;
using poly = tifa_libs::math::polyntt<mint>;

int main() {
  u32 n, m, c;
  tifa_libs::fin >> n >> m >> c;
  poly a(n);
  tifa_libs::fin >> a;
  tifa_libs::fout << tifa_libs::math::ctsh_fps(a, mint(c), m).data() << '\n';
  return 0;
}
