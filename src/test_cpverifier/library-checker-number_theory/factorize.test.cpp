#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../../code/io/ios_container.hpp"
#include "../../code/nt/pfactors.hpp"

int main() {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  i64 q;
  std::cin >> q;
  while (q--) {
    u64 a;
    std::cin >> a;
    auto ans = tifa_libs::math::pfactors<false>(a);
    std::cout << ans.size();
    if (!ans.empty()) std::cout << ' ' << ans;
    std::cout << '\n';
  }
  return 0;
}