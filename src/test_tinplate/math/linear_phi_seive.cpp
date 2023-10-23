#include "../../code/math/linear_phi_seive.hpp"

void solve() {
  u32 n;
  std::cin >> n;
  auto _ = tifa_libs::math::linear_phi_seive(n);
  for (size_t i = 0; i < n; ++i) std::cout << _[i] << " \n"[i + 1 == n];
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}