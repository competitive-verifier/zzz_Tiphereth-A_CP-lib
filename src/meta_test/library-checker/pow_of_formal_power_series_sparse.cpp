#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"

#include "../../code/io/fastio.hpp"
#include "../../code/poly/pow_fpssp.hpp"

constexpr u32 MOD = 998244353;

#define GENTCs_p3ntts
#define GENTCs_p3nttd0
#define GENTCs_pcntts
#define GENTCs_pmtts
#define GENTCs_pmttd0
#define GENTCs_pntt

int main() {
#define GENTCs_p3nttd1
#define GENTCs_pmttd1
  u32 n, k;
  u64 m;
  tifa_libs::fin >> n >> k >> m;
  poly p(n);
  for (u32 i = 0, x; i < k; ++i) tifa_libs::fin >> x >> p[x];
  tifa_libs::fout << tifa_libs::math::pow_fpssp(p, m).data();
  return 0;
}
