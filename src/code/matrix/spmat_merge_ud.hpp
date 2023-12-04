#ifndef TIFALIBS_MATRIX_SPMAT_MERGE_UD
#define TIFALIBS_MATRIX_SPMAT_MERGE_UD

#include "spmat.hpp"

namespace tifa_libs::math {

// [u] [d] -> [u; d]
template <class T>
spmat<T> spmat_merge_ud(const spmat<T> &u, const spmat<T> &d) {
  u32 ur_ = u.row(), dr_ = d.row(), c_ = u.col();
  assert(c_ == d.col());
  spmat<T> ret(ur_ + dr_, c_);
  for (u32 i = 0; i < ur_; ++i)
    if (!u.data()[i].empty()) ret.data()[i] = u.data()[i];
  for (u32 i = 0; i < dr_; ++i)
    if (!d.data()[i].empty()) ret.data()[i + ur_] = d.data()[i];
  return ret;
}

}  // namespace tifa_libs::math

#endif