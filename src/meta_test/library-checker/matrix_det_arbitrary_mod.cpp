#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_arbitrary_mod"

#include "../../code/lalg/mat.hpp"
#include "../../code/lalg/mat_det.hpp"
#include "../../code/lalg/mat_ge_euclid.hpp"

#ifdef GENTC_d31
#include "../../code/math/mint_d31.hpp"

using mint = tifa_libs::math::mint_d31<-1>;
#endif
#ifdef GENTC_ds
#include "../../code/math/mint_ds.hpp"

using mint = tifa_libs::math::mint_ds<-1>;
#endif
using mat = tifa_libs::math::matrix<mint>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, MOD;
  std::cin >> n >> MOD;
#ifdef GENTC_d31
  mint::set_mod(MOD);
#endif
#ifdef GENTC_ds
  mint::set_mod(MOD);
#endif
  if (!n) {
    std::cout << "1\n";
    return 0;
  }
  mat a(n, n);
  std::cin >> a;
  auto is_0 = [](mint const &x) { return x.val() == 0; };
  auto div = [](mint const &x, mint const &y) { return x.val() / y.val(); };
  auto ge = [&is_0, &div](mat &m, bool f) { return tifa_libs::math::ge_euclid(m, is_0, div, f); };
  std::cout << det(a, ge);
  return 0;
}