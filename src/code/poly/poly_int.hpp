#ifndef TIFALIBS_POLY_INT
#define TIFALIBS_POLY_INT

#include "poly.hpp"

namespace tifa_libs::math {

template <class T>
inline poly<T> poly_int(poly<T> const &p) {
  using mint = typename T::value_type;
  auto _ = p;
  _.data().push_back(0);
  for (size_t i = _.size() - 1; i; --i) _[i] = _[i - 1] * mint(i).inv();
  _[0] = 0;
  _.data().pop_back();
  return _;
}

}  // namespace tifa_libs::math

#endif