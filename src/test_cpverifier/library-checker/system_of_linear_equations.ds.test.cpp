#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include "../../code/lalg/leqs_solver.hpp"
#include "../../code/lalg/mat_ge_basic.hpp"
#include "../../code/lalg/mat_trans.hpp"
#include "../../code/math/mint.hpp"
#include "../../code/math/mintdata_ds.hpp"

using mintdata = tifa_libs::math::mintdata_ds<-1>;
using mint = tifa_libs::math::mint<mintdata>;

using mat = tifa_libs::math::matrix<mint>;

int main() {
  mintdata::set_mod(998244353);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, m;
  std::cin >> n >> m;
  mat a(n, m), b(n, 1);
  std::cin >> a >> b;

  auto is_0 = [](mint const &x) { return x.val() == 0; };
  auto ge = [&is_0](mat &m, bool f) { return tifa_libs::math::ge_basic(m, is_0, f); };

  auto res_ = tifa_libs::math::leqs_solver(a, b, is_0, ge);
  if (!res_)
    std::cout << "-1\n";
  else {
    mat &res = res_.value();
    std::cout << res.col() - 1 << '\n';
    std::cout << tifa_libs::math::transpose(res) << '\n';
  }
  return 0;
}
