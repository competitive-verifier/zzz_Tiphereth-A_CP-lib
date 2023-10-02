#ifndef TIFALIBS_POLY_FFT
#define TIFALIBS_POLY_FFT

#include "../util/util.hpp"

#include "fft_info.hpp"

namespace tifa_libs::math {

template <class FP>
struct FFT {
  static_assert(std::is_floating_point_v<FP>);

  using C = std::complex<FP>;

  constexpr FFT() {}
  template <bool inv = false>
  constexpr void run(vec<C> &g) {
    size_t n = g.size();
    info.set(n);
    w.resize(n);
    w[0] = 1;
    for (size_t i = 1; i < n; ++i) {
      w[i].real(std::cos(TAU * (FP)i / (FP)n));
      if constexpr (inv) w[i].imag(-std::sin(TAU * (FP)i / (FP)n));
      else w[i].imag(std::sin(TAU * (FP)i / (FP)n));
    }
    for (size_t i = 0; i < n; ++i)
      if (i < info.root[i]) std::swap(g[i], g[info.root[i]]);
    for (size_t i = 2; i <= n; i *= 2) {
      for (size_t j = 1; j < i / 2; ++j) {
        w[j].real(std::cos(TAU / (FP)i * (FP)j));
        if constexpr (inv) w[j].imag(-std::sin(TAU / (FP)i * (FP)j));
        else w[j].imag(std::sin(TAU / (FP)i * (FP)j));
      }
      for (size_t j = 0; j < n; j += i) {
        auto f = g.begin() + j, h = g.begin() + j + i / 2;
        for (size_t k = 0; k < i / 2; ++k) {
          C p = f[k], q = h[k] * w[k];
          f[k] = p + q;
          h[k] = p - q;
        }
      }
    }
  }

private:
  const FP TAU = std::acos((FP)1.) * 2;

  FFT_INFO info;
  vec<C> w;
};

}  // namespace tifa_libs::math

#endif