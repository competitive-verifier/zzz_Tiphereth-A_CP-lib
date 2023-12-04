#ifndef TIFALIBS_MATH_GCD128
#define TIFALIBS_MATH_GCD128

#include "../bit/cntr0.hpp"
#include "../util/abs_constexpr.hpp"
#include "../util/traits.hpp"

namespace tifa_libs::math {

template <class T, std::enable_if_t<is_uint<T>::value>* = nullptr>
constexpr T gcd_u128(T a, T b) {
  if (!a) return b;
  if (!b) return a;
  const int i = bit::cntr0(a), j = bit::cntr0(b), k = std::min(i, j);
  a >>= i, b >>= j;
  while (1) {
    if (a > b) std::swap(a, b);
    if (!(b -= a)) return a << k;
    b >>= bit::cntr0(b);
  }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
template <class T, std::enable_if_t<is_int<T>::value>* = nullptr>
constexpr T gcd_128(T a, T b) { return gcd_u128<to_uint_t<T>>(abs(a), abs(b)); }
#pragma GCC diagnostic pop

}  // namespace tifa_libs::math

#endif