#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "../../code/util/util.hpp"
//
#define GENTCs_hashstrs
#define GENTCs_hashstrd0

int main() {
#define GENTCs_hashstrd1
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  strn s;
  std::cin >> s;
  {
    strn x;
    x.reserve(s.size() * 2 + 1);
    x.push_back('$');
    for (char c : s) x.push_back(c), x.push_back('$');
    s.swap(x);
  }
  strn t = s;
  std::ranges::reverse(t);
  hashstr hs, ht;
  hs.set(s), ht.set(t);
  u32 n = (u32)s.size();
  vecu ans(n);
  for (u32 i = 0; i < n; ++i) {
    u32 l = 0, r = std::min(i, n - 1 - i) + 1;
    while (l + 1 < r) {
      u32 m = (l + r) / 2, l_ = i - m, r_ = i + m;
      (hs.get(l_, r_ + 1 - l_) == ht.get(n - 1 - r_, r_ + 1 - l_) ? l : r) = m;
    }
    ans[i] = l;
  }
  for (u32 i = 1; i < n - 1; ++i) std::cout << ans[i] << " \n"[i + 2 == n];
  return 0;
}