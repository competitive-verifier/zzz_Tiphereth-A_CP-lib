#ifndef TIFA_LIBS_MATH_STIRLING2_ROW_GEN
#define TIFA_LIBS_MATH_STIRLING2_ROW_GEN

#include "../poly/poly.hpp"
#include "ifact_mod_gen.hpp"
#include "pows_mod_gen.hpp"

namespace tifa_libs::math {

// stirling2[i] = {n \\brace i}, i=0,1,...,m
template <class T>
inline poly<T> stirling2_row_gen(u64 m, u64 n, vec<u64> const& pows, vec<u64> const& ifact) {
  assert(m <= n);
  if (!m) return poly<T>{1};
  u64 mod = T::value_type::mod();
  poly<T> a(m + 1), b(m + 1);
  for (size_t i = 1; i <= m; ++i) a[i] = mul_mod_u(pows[i], ifact[i], mod);
  for (size_t i = 0; i <= m; ++i) b[i] = ((i & 1) ? mod - ifact[i] : ifact[i]);
  a *= b;
  a.resize(m + 1);
  return a;
}
// stirling2[i] = {n \\brace i}, i=0,1,...,m
template <class T>
inline poly<T> stirling2_row_gen(u64 m, u64 n) { return stirling2_row_gen<T>(m, n, pows_mod_gen(m + 1, n, T::value_type::mod()), ifact_mod_gen(m + 1, T::value_type::mod())); }

}  // namespace tifa_libs::math

#endif