#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_4_C"

#include "../../code/edh/hash_splitmix64.hpp"

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n;
  std::cin >> n;
  tifa_libs::hset<u64> dict;
  flt_ (u32, i, 0, n) {
    strn s, t;
    std::cin >> s >> t;
    u64 x = 0;
    for (char c : t) switch (c) {
        case 'A': ++x; [[fallthrough]];
        case 'C': ++x; [[fallthrough]];
        case 'G': ++x; [[fallthrough]];
        default: (++x) *= 5;
      }
    if (s[0] == 'i')
      dict.insert(x);
    else
      std::cout << (dict.count(x) ? "yes\n" : "no\n");
  }
  return 0;
}
