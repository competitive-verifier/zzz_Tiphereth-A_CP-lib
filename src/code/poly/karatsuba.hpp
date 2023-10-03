#ifndef TIFALIBS_POLY_KARATSUBA
#define TIFALIBS_POLY_KARATSUBA

#include "conv_naive.hpp"

namespace tifa_libs::math {

namespace karatsuba_detail_ {
template <typename T>
void add(vec<T> &a, vec<T> const &b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (size_t i = 0; i < b.size(); ++i) a[i] += b[i];
}
template <typename T>
void sub(vec<T> &a, vec<T> const &b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (size_t i = 0; i < b.size(); ++i) a[i] -= b[i];
}
}  // namespace karatsuba_detail_

inline vec<u64> karatsuba(vec<u64> const &a, vec<u64> const &b) {
  if (a.empty() && b.empty()) return {};
  if (a.size() < b.size()) return karatsuba(b, a);
  if (a.size() < 32) return conv_naive(a, b);
  size_t d = a.size() / 2;
  vec<u64> al(a.begin(), a.begin() + d), au(a.begin() + d, a.end());
  if (b.size() < d + 10) {
    auto cl = karatsuba(al, b);
    auto cu = karatsuba(au, b);
    vec<u64> c(a.size() + b.size() - 1);
    for (size_t i = 0; i < cl.size(); ++i) c[i] = cl[i];
    for (size_t i = 0; i < cu.size(); ++i) c[i + d] += cu[i];
    return c;
  }
  vec<u64> bl(b.begin(), b.begin() + d), bu(b.begin() + d, b.end());
  vec<u64> alu{al}, blu{bl};
  karatsuba_detail_::add(alu, au);
  karatsuba_detail_::add(blu, bu);
  vec<u64> cll = karatsuba(al, bl), cuu = karatsuba(au, bu), clu = karatsuba(alu, blu);
  karatsuba_detail_::sub(clu, cll);
  karatsuba_detail_::sub(clu, cuu);
  vec<u64> c(d);
  std::copy(clu.begin(), clu.end(), std::back_inserter(c));
  c.resize(a.size() + b.size() - 1);
  karatsuba_detail_::add(c, cll);
  for (size_t i = 0; i < cuu.size(); ++i) c[i + 2 * d] += cuu[i];
  c.resize(a.size() + b.size() - 1);
  return c;
}

}  // namespace tifa_libs::math

#endif