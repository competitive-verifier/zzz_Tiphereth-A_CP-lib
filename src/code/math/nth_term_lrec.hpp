#ifndef TIFALIBS_MATH_NTH_TERM_LREC
#define TIFALIBS_MATH_NTH_TERM_LREC

#include "../poly/bostan_mori.hpp"
#include "berlekamp_massey.hpp"

namespace tifa_libs::math {

template <class poly, std::same_as<typename poly::value_type> mint>
constexpr mint nth_term_lrec(u64 n, vec<mint> const& a, vec<mint> const& bm) {
  if (n < a.size()) return a[n];
  assert(!bm.empty() && bm[0] == 1);
  poly q(bm);
  q.strip();
  return bostan_mori(n, (poly(a) * q).pre(q.size() - 1), q);
}
template <class poly, std::same_as<typename poly::value_type> mint>
constexpr mint nth_term_lrec(u64 n, vec<mint> const& a) {
  if (n < a.size()) return a[n];
  auto bm = berlekamp_massey(a);
  return nth_term_lrec<poly, mint>(n, a, bm);
}

}  // namespace tifa_libs::math

#endif