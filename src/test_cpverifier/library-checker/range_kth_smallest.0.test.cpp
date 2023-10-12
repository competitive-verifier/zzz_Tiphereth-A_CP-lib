#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../../code/ds/persistent_segtree.hpp"
#include "../../code/util/discretization.hpp"

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t n, q;
  std::cin >> n >> q;
  tifa_libs::vec<tifa_libs::i32> _(n);
  for(auto &x: _) std::cin >> x;
  auto [b, a] = tifa_libs::util::gen_id(_);
  tifa_libs::ds::persistent_segtree seg(a, b.size() + 1);
  for(size_t i = 0, l, r, k; i < q; ++ i) {
    std::cin >> l >> r >> k;
    std::cout << b[seg.kth_min(l, r - 1, k + 1)] <<'\n';
  }
  return 0;
}