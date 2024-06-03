#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../code/ds/rus4_st.hpp"

i32 f(i32 x, i32 y) { return tifa_libs::min(x, y); }
i32 e() { return std::numeric_limits<i32>::max(); }

int main() {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  u32 n, q;
  std::cin >> n >> q;
  vec<i32> a(n);
  flt_ (u32, i, 0, n) std::cin >> a[i];
  if (n < 16) {
    tifa_libs::ds::st_array<i32, f, e> st(a);
    for (u32 i = 1, u, v; i <= q; ++i) {
      std::cin >> u >> v;
      std::cout << st.query(u, v) << '\n';
    }
  } else {
    tifa_libs::ds::rus4_st<i32, f, e> st(a, (u32)std::bit_width(n));
    for (u32 i = 1, u, v; i <= q; ++i) {
      std::cin >> u >> v;
      std::cout << st.query(u, v) << '\n';
    }
  }
  return 0;
}
