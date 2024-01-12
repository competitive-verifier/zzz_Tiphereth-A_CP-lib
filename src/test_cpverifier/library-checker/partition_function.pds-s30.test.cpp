#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include "../../code/comb/gen_partition.hpp"
#include "../../code/math/mint.hpp"
#include "../../code/math/mintdata_s30.hpp"
#include "../../code/poly/polydata_s.hpp"

using mintdata = tifa_libs::math::mintdata_s30<998244353>;
using mint = tifa_libs::math::mint<mintdata>;
using polyd = tifa_libs::math::polydata_s<mint>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n;
  std::cin >> n;
  std::cout << tifa_libs::math::gen_partition<polyd>(n);
  return 0;
}
