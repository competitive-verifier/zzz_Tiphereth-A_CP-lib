#ifndef TIFALIBS_GEO2D_DISTSP_PP
#define TIFALIBS_GEO2D_DISTSP_PP

#include "point.hpp"

namespace tifa_libs::geo {

// distance of two points on sphere with radius %r (Euclidian)
template <class FP>
constexpr FP distsp_PP(FP r, point<FP> const &p1, point<FP> const &p2) { return r * std::acos(std::sin(p1.y) * std::sin(p2.y) + std::cos(p1.y) * std::cos(p2.y) * std::cos(p1.x - p2.x)); }

}  // namespace tifa_libs::geo

#endif