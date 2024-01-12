#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"

#include "../../code/lalg/mat_det_rd.hpp"
#include "../../code/lalg/spmat.hpp"
#include "../../code/math/mint.hpp"
#include "../../code/math/mintdata_ds.hpp"
#include "../../code/rand/gen.hpp"

using mintdata = tifa_libs::math::mintdata_ds<-1>;
using mint = tifa_libs::math::mint<mintdata>;

using mat = tifa_libs::math::spmat<mint>;

int main() {
  mintdata::set_mod(998244353);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u64 n, k;
  std::cin >> n >> k;
  mat a(n, n);
  for (u64 i = 0, x, y, z; i < k; ++i) {
    std::cin >> x >> y >> z;
    a(x, y) = z;
  }
  auto is0 = [](mint const &x) { return x.val() == 0; };
  tifa_libs::rand::Gen<std::uniform_int_distribution<u32>> gen(1, mint::mod() - 1);
  std::cout << tifa_libs::math::det_rd(a, gen, is0) << '\n';
  return 0;
}
