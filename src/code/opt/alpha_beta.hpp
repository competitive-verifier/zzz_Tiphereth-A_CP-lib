#ifndef TIFALIBS_OPT_ALPHA_BETA
#define TIFALIBS_OPT_ALPHA_BETA

#include "../tree/tree.hpp"
#include "../util/traits.hpp"

namespace tifa_libs::opt {

template <arithm_c T>
constexpr T alpha_beta(graph::tree const &tr, vec<T> const &v_weight) {
  auto dfs = [&](auto &&dfs, u32 u, T a, T b, bool is_max = 1) -> T {
    if (tr.g[u].empty()) return v_weight[u];
    if (is_max) {
      for (auto d : tr.g)
        if ((a = std::max(a, dfs(dfs, d, a, b, !is_max))) >= b) break;
      return a;
    } else {
      for (auto d : tr.g)
        if ((b = std::min(b, dfs(dfs, d, a, b, !is_max))) <= a) break;
      return b;
    }
  };
  return dfs(dfs, tr.root, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
}

}  // namespace tifa_libs::opt

#endif