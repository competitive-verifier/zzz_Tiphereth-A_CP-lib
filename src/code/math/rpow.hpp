#ifndef TIFA_LIBS_MATH_RPOW
#define TIFA_LIBS_MATH_RPOW

#include "../util/util.hpp"

#include "mul_mod_u.hpp"

namespace tifa_libs::math {

class rpow {
  u64 b_;
  u64 m_;
  std::vector<u64> b0, b1;

public:
  explicit rpow() = default;
  rpow(u64 base_, u32 mod_):
    b_(base_ % mod_), m_(mod_), b0(65536), b1(65536) {
    b0[0] = b1[0] = 1;
    for (size_t i = 1; i < 65536; i++) b0[i] = mul_mod_u(b0[i - 1], b_, m_);
    u64 _(mul_mod_u(b0.back(), b_, m_));
    for (size_t i = 1; i < 65536; i++) b1[i] = mul_mod_u(b1[i - 1], _, m_);
  }

  constexpr u64 base() const { return b_; }
  constexpr u64 mod() const { return m_; }

  u64 operator()(u64 x) const { return mul_mod_u(b0[x & 0xff], b1[x >> 16], m_); }
};

}  // namespace tifa_libs::math

#endif