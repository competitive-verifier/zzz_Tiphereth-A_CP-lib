#ifndef TIFALIBS_COMB_GEN_STIRLING2_ROW
#define TIFALIBS_COMB_GEN_STIRLING2_ROW

#include "gen_ifact.hpp"
#include "gen_pows.hpp"

namespace tifa_libs::math {

// stirling2[i] = {n \\brace i}, i=0,1,...,n
template <class poly>
constexpr poly gen_stirling2_row(u32 n, vecu64 const& pows, vecu64 const& ifact) {
  using mint = typename poly::value_type;
  if (!n) return poly{1};
  u64 mod = mint::mod();
  poly a(n + 1), b(n + 1);
  for (u32 i = 1; i <= n; ++i) a[i] = mul_mod_u(pows[i], ifact[i], mod);
  for (u32 i = 0; i <= n; ++i) b[i] = ((i & 1) ? mod - ifact[i] : ifact[i]);
  a *= b;
  a.resize(n + 1);
  return a;
}
// stirling2[i] = {n \\brace i}, i=0,1,...,n
template <class poly>
constexpr poly gen_stirling2_row(u32 n) {
  using mint = typename poly::value_type;
  return gen_stirling2_row<poly>(n, gen_pows(n + 1, n, mint::mod()), gen_ifact(n + 1, mint::mod()));
}

}  // namespace tifa_libs::math

#endif