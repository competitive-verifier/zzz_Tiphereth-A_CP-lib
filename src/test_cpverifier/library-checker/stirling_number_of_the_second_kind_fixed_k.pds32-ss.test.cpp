#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k"

#include "../../code/comb/gen_stirling2_col.hpp"
#include "../../code/math/mint.hpp"
#include "../../code/math/mintdata_ss.hpp"
#include "../../code/poly/polydata_s32.hpp"
#include "../../code/io/fastio.hpp"

using mintdata = tifa_libs::math::mintdata_ss<998244353>;
using mint = tifa_libs::math::mint<mintdata>;
using polyd = tifa_libs::math::polydata_s32<mint>;

int main() {
  u32 n, k;
  tifa_libs::fin >> n >> k;
  auto ans = tifa_libs::math::gen_stirling2_col<polyd>(n, k);
  for (usz i = k; i <= n; ++i) tifa_libs::fout << ans[i] << " \n"[i == n];
  return 0;
}
