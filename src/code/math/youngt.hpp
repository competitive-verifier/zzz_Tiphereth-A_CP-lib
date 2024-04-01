#ifndef TIFALIBS_MATH_YOUNGT
#define TIFALIBS_MATH_YOUNGT

#include "../util/util.hpp"

namespace tifa_libs::math {

class Youngt {
  vvec<u32> d;
  u32 n;

 public:
  constexpr explicit Youngt(vec<u32> const& l) {
    for (auto i : l) insert(i);
  }
  constexpr Youngt(std::initializer_list<u32> l = {}) {
    for (auto i : l) insert(i);
  }
  constexpr Youngt(std::initializer_list<std::initializer_list<u32>> l) {
    for (auto&& i : l) d.emplace_back(i);
  }

  // height() == len(longest non-decresing seq.)
  constexpr u32 height() const { return (u32)d.size(); }
  // width() == len(longest incresing seq.)
  constexpr u32 width() const { return (u32)d[0].size(); }
  constexpr u32 const& size() const { return n; }
  constexpr vvec<u32>& data() { return d; }
  constexpr vvec<u32> const& data() const { return d; }
  constexpr u32& operator()(u32 h, u32 w) { return d[h][w]; }
  constexpr u32 const& operator()(u32 h, u32 w) const { return d[h][w]; }

  constexpr u32 hook(u32 h, u32 w) const {
    assert(h < height() && w < d[h].size());
    return u32(d[h].size() - w + h);
  }

  constexpr void insert(u32 val) {
    ++n;
    for (auto& i : d) {
      auto it = std::lower_bound(i.begin(), i.end(), val);
      if (it == i.end()) {
        i.push_back(val);
        return;
      }
      std::swap(val, *it);
    }
    d.push_back({val});
  }

  friend std::ostream& operator<<(std::ostream& os, Youngt const& yt) {
    for (u32 i = 0; i < yt.height() - 1; ++i)
      for (u32 j = 0; j < yt.d[i].size(); ++j) os << yt.d[i][j] << " \n"[j == yt.d[i].size() - 1];
    os << yt.d.back()[0];
    for (u32 j = 1; j < yt.d.back().size(); ++j) os << ' ' << yt.d.back()[j];
    return os;
  }
};

}  // namespace tifa_libs::math

#endif