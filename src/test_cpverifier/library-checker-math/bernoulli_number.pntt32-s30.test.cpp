#define AUTO_GENERATED
#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include "../../code/comb/gen_bernoulli.hpp"
#include "../../code/io/fastio.hpp"

constexpr u32 MOD = 998244353;

#include "../../code/math/mint_s30.hpp"
#include "../../code/poly/polyntt32.hpp"

using mint = tifa_libs::math::mint_s30<MOD>;
using poly = tifa_libs::math::polyntt32<mint>;

int main() {
  u32 n;
  tifa_libs::fin >> n;
  tifa_libs::fout << tifa_libs::math::gen_bernoulli<poly>(n).data();
  return 0;
}