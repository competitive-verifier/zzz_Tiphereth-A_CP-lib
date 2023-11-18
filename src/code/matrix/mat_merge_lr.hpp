#ifndef TIFA_LIBS_MATH_MAT_MERGE_LR
#define TIFA_LIBS_MATH_MAT_MERGE_LR

#include "mat.hpp"

namespace tifa_libs::math {

// [l] [r] -> [l r]
template <class T>
matrix<T> mat_merge_lr(matrix<T> const &l, matrix<T> const &r) {
  u32 r_ = l.row();
  assert(r_ == r.row());
  u32 lc_ = l.col(), rc_ = r.col(), c_ = lc_ + rc_;
  matrix<T> ret(r_, c_);
  ret.apply_range(0, r_, 0, lc_, [&l](u32 i, u32 j, T &val) { val = l(i, j); });
  ret.apply_range(0, r_, lc_, c_, [lc_, &r](u32 i, u32 j, T &val) { val = r(i, j - lc_); });
  return ret;
}

}  // namespace tifa_libs::math

#endif