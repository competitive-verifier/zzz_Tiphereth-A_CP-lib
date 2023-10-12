#ifndef TIFA_LIBS_MATH_STIRLING2_SMALLP
#define TIFA_LIBS_MATH_STIRLING2_SMALLP

#include "lucas.hpp"

namespace tifa_libs::math {

class Stirling2 {
  Lucas mCn;
  vvec<u32> S;

 public:
  //! @param p MUST be prime
  explicit Stirling2(u32 p) : mCn(p), S(p) {
    assert(p < 32768);
    S[0] = {1};
    for (u32 i = 1; i < p; ++i) {
      S[i].assign(i + 1, 0);
      for (u32 j = 0; j <= i; ++j) {
        if (j) S[i][j] += S[i - 1][j - 1];
        if (j < i) S[i][j] += S[i - 1][j] * j;
        S[i][j] %= p;
      }
    }
  }

  constexpr u32 mod() const { return (u32)mCn.mod(); }
  u32 operator()(i64 m_, i64 n_) const {
    if (n_ < 0 || n_ > m_) return 0;
    if (!m_) return 1;
    u32 p = mod();
    u64 m = (u64)m_, n = (u64)n_, i = n / p;
    if (m < i) return 0;
    u64 a = (m - i) / (p - 1);
    u32 j = n % p, b = (m - i) % (p - 1);
    if (!b) {
      b += p - 1;
      if (a) --a;
      else return 0;
    }
    if (j > b) return 0;
    if (b < p - 1) return (u32)mul_mod_u(mCn((i64)a, (i64)i), S[b][j], p);
    if (!j) return (u32)mCn((i64)a, (i64)i - 1);
    return (u32)mul_mod_u(mCn((i64)a, (i64)i), S[p - 1][j], p);
  }
};

}  // namespace tifa_libs::math

#endif