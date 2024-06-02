#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"

#include "../../code/nt/is_prime.hpp"

int main() {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  u32 t;
  std::cin >> t;
  u32 cnt = 0;
  while (t--) {
    u32 p;
    std::cin >> p;
    cnt += tifa_libs::math::is_prime(p);
  }
  std::cout << cnt << '\n';
  return 0;
}
