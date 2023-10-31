#ifndef TIFA_LIBS_MATH_GEN_IFACT
#define TIFA_LIBS_MATH_GEN_IFACT

#include "gen_inv.hpp"

namespace tifa_libs::math {

// (i!)^{-1} from i=0..n-1
inline vec<u64> gen_ifact(u32 n, u64 mod, vec<u64> inv) {
  for (u32 i = 2; i < n; ++i) inv[i] = mul_mod_u(inv[i], inv[i - 1], mod);
  return inv;
}
// (i!)^{-1} from i=0..n-1
inline vec<u64> gen_ifact(u32 n, u64 mod) { return gen_ifact(n, mod, gen_inv(n, mod)); }

}  // namespace tifa_libs::math

#endif