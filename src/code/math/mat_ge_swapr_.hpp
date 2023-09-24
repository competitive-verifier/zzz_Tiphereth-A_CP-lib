#ifndef TIFA_LIBS_MATH_MAT_GE_SWAPR_
#define TIFA_LIBS_MATH_MAT_GE_SWAPR_

#include "../util/util.hpp"

#include "../util/abs_constexpr.hpp"
#include "mat.hpp"

namespace tifa_libs::math::ge_detail__ {

template <class T>
constexpr bool swapr__(matrix<T> &mat, size_t &r_, size_t r_pre_, size_t c_, size_t r_end) {
  r_ = r_pre_;
  for (size_t j = r_ + 1; j < r_end; ++j)
    if (abs(mat(j, c_)) > abs(mat(r_, c_))) r_ = j;
  if (r_ != r_pre_) {
    mat.swap_row(r_, r_pre_);
    return true;
  }
  return false;
}

}  // namespace tifa_libs::math::ge_detail__

#endif