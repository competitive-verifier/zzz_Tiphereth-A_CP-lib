#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_C"

#include "../../code/math/rgcd.hpp"
#include "../../code/util/fastio.hpp"

constexpr u32 LIMIT = 1e7;

int main() {
  u64 n;
  tifa_libs::fin >> n;
  u32 ans;
  tifa_libs::fin >> ans;
  tifa_libs::math::RGCD rgcd(LIMIT);
  for (u32 i = 0, x; i < n; ++i) {
    tifa_libs::fin >> x;
    if (ans < LIMIT) (ans /= rgcd(ans, x)) *= x;
    else ans = std::lcm(ans, x);
  }
  tifa_libs::fout << ans << '\n';
  return 0;
}
