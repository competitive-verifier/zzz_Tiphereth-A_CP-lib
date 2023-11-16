// #pragma comment(linker, "/STACK:102400000,102400000")
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;

template <class Tp>
using vec = std::vector<Tp>;
template <class Tp>
using vvec = std::vector<std::vector<Tp>>;
template <class Tp>
using pq = std::priority_queue<Tp>;
template <class Tp>
using pqg = std::priority_queue<Tp, std::vector<Tp>, std::greater<Tp>>;

#define for_(i, l, r, v...) for (i64 i = (l), i##e = (r), ##v; i <= i##e; ++i)
#define fors_(i, l, r, s, v...) for (i64 i = (l), i##e = (r), ##v; i <= i##e; i += s)
#define rfor_(i, r, l, v...) for (i64 i = (r), i##e = (l), ##v; i >= i##e; --i)
#define rfors_(i, r, l, s, v...) for (i64 i = (r), i##e = (l), ##v; i >= i##e; i -= s)
#define Rep for_
#define rep rfor_
template <class... Ts>
void dec(Ts &...x) { ((--x), ...); }
template <class... Ts>
void inc(Ts &...x) { ((++x), ...); }

template <class T>
void debug(T x) {
#ifdef LOCAL_
  std::cerr << x << std::endl;
#endif
}
template <class T, class... Ts>
void debug(T x, Ts... args) {
#ifdef LOCAL_
  std::cerr << x << ' ';
  debug(args...);
#endif
}
#define debug_line_ (std::cerr << __LINE__ << ' ' << __FUNCTION__ << std::endl)
#define debug_withname_(var) debug(#var, var)

using namespace std;

// #define MULTI_CASES
void solve(int t_ = 0) {
}

signed main() {
#ifdef LOCAL_
  auto CLOCK_ST_ = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr << fixed << setprecision(6);
  int i_ = 0;
#ifdef MULTI_CASES
  int t_ = 0;
  cin >> t_;
  for (i_ = 0; i_ < t_; ++i_)
#endif
    debug("Case", i_), solve(i_);
#ifdef LOCAL_
  auto CLOCK_ED_ = chrono::high_resolution_clock::now();
  clog << "\n---\n" << chrono::duration_cast<chrono::nanoseconds>(CLOCK_ED_ - CLOCK_ST_).count() * 1e-6l << " ms" << endl;
#endif
  return 0;
}