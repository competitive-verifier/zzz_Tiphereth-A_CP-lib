#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include "../../code/comb/gen_bernoulli.hpp"
#include "../../code/math/mint.hpp"
#include "../../code/math/mintdata_s63.hpp"
#include "../../code/poly/polydata_s.hpp"

using mintdata = tifa_libs::math::mintdata_s63<998244353>;
using mint = tifa_libs::math::mint<mintdata>;
using polyd = tifa_libs::math::polydata_s<mint>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n;
  std::cin >> n;
  std::cout << tifa_libs::math::gen_bernoulli<polyd>(n);
  return 0;
}
