#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix_mod_2"

#include "../../code/lalg/inv_bmat.hpp"

template <usz N>
using mat = tifa_libs::math::bitmat<N>;

int main() {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  u32 n;
  std::cin >> n;

#define DO(num)                                                                             \
  if (n <= num) {                                                                           \
    mat<num> bm;                                                                            \
    tifa_libs::math::read_bitmat(std::cin, bm, n, n);                                       \
    if (auto res = tifa_libs::math::inv_bmat(bm, n); !res.has_value()) std::cout << "-1\n"; \
    else tifa_libs::math::print_bitmat(std::cout, res.value(), n, n);                       \
    return 0;                                                                               \
  }

  DO(1 << 6)
  DO(1 << 8)
  DO(1 << 12)

  return 0;
}