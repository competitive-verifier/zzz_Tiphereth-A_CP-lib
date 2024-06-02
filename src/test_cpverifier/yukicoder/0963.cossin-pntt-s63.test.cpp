#define AUTO_GENERATED
#define AUTO_GENERATED
#define PROBLEM "https://yukicoder.me/problems/no/963"

#include "../../code/poly/cossin_fps.hpp"

CEXP u32 MOD = 1012924417;

#include "../../code/math/mint_s63.hpp"
#include "../../code/poly/polyntt.hpp"

using mint = tifa_libs::math::mint_s63<MOD>;
using poly = tifa_libs::math::polyntt<mint>;

int main() {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  u32 n;
  std::cin >> n;
  mint fact_n = 1;
  fle_(u32, i, 1, n) fact_n *= i;
  auto [fc, fs] = tifa_libs::math::cossin_fps(poly{0, 1}, n + 1);
  std::cout << ((fs + 1) * inv_fps(fc, n + 1))[n] * 2 * fact_n << '\n';
  return 0;
}
