#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k"

#include "../../code/comb/stirling1_col_gen.hpp"
#include "../../code/math/mint_s30.hpp"
#include "../../code/poly/polydata_s.hpp"
#include "../../code/util/fastio.hpp"

using mint = tifa_libs::math::mint_s30<998244353>;
using polyd = tifa_libs::math::polydata_s<mint>;

int main() {
  u32 n, k;
  tifa_libs::fin >> n >> k;
  auto ans = tifa_libs::math::stirling1_col_gen<polyd>(n, k);
  for (usz i = k; i <= n; ++i) tifa_libs::fout << ans[i] << " \n"[i == n];
  return 0;
}
