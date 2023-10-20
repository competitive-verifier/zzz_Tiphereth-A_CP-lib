#ifndef TIFA_LIBS_MATH_PRIME_SEQ
#define TIFA_LIBS_MATH_PRIME_SEQ

#include "isqrt.hpp"

namespace tifa_libs::math {

inline vec<u32> prime_seq(u32 n) {
  vec<bool> sieve(n / 3 + 1, 1);
  for (u32 p = 5, d = 4, i = 1, sqn = isqrt(n); p <= sqn; p += d = 6 - d, ++i) {
    if (!sieve[i]) continue;
    for (u64 q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p, qe = sieve.size(); q < qe; q += r = s - r) sieve[q] = 0;
  }
  vec<u32> ret{2, 3};
  for (u32 p = 5, d = 4, i = 1; p <= n; p += d = 6 - d, ++i)
    if (sieve[i]) ret.push_back(p);
  while (!ret.empty() && ret.back() > n) ret.pop_back();
  return ret;
}

}  // namespace tifa_libs::math

#endif