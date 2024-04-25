#ifndef TIFALIBS_TREE_TREEW
#define TIFALIBS_TREE_TREEW

#include "../graph/alistw.hpp"

namespace tifa_libs::graph {

template <class T>
struct treew : alistw<T, false> {
  u32 root;

  explicit CEXP treew(u32 n, u32 root = 0) : alistw<T>(n), root(root) {}
};

}  // namespace tifa_libs::graph

#endif