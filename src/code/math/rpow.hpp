#ifndef TIFALIBS_MATH_RPOW
#define TIFALIBS_MATH_RPOW

#include "mul_mod.hpp"

namespace tifa_libs::math {

class rpow {
  vecu64 b0, b1;
  u64 b_, m_;

 public:
  explicit CEXP rpow() : b0(65536), b1(65536), b_(), m_() {}
  CEXP rpow(u64 base_, u32 mod_) : rpow() { reset(base_, mod_); }

  CEXP void reset(u64 base, u32 mod) {
    if (b_ == base % mod && m_ == mod) return;
    b_ = base % mod;
    m_ = mod;
    b0[0] = b1[0] = 1;
    flt_ (u32, i, 1, 65536) b0[i] = mul_mod_u(b0[i - 1], b_, m_);
    u64 _(mul_mod_u(b0.back(), b_, m_));
    flt_ (u32, i, 1, 65536) b1[i] = mul_mod_u(b1[i - 1], _, m_);
  }

  CEXP void swap(rpow& r) {
    b0.swap(r.b0), b1.swap(r.b1);
    ::tifa_libs::swap(b_, r.b_), ::tifa_libs::swap(m_, r.m_);
  }

  CEXP u64 base() const { return b_; }
  CEXP u64 mod() const { return m_; }

  CEXP u64 operator()(u32 x) const { return mul_mod_u(b0[x & 65535], b1[x >> 16], m_); }
};

}  // namespace tifa_libs::math

#endif