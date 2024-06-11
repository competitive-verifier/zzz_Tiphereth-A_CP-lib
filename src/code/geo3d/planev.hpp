#ifndef TIFALIBS_GEO3D_PLANEV
#define TIFALIBS_GEO3D_PLANEV

#include "../geo2d/cross.hpp"
#include "point3d.hpp"

namespace tifa_libs::geo {

template <class FP>
struct planev {
  point3d<FP> const *u, *v, *w;
  CEXP planev(point3d<FP> CR a, point3d<FP> CR b, point3d<FP> CR c) : u(&a), v(&b), w(&c) {}

  friend std::ostream &operator<<(std::ostream &os, planev CR pl) { return os << *pl.u << ' ' << *pl.v << ' ' << *pl.w; }
  CEXP point3d<FP> normal() const { return cross(*u, *v, *w); }
  CEXP FP area2() const { return normal().norm(); }
  CEXP FP area() const { return area2() * (FP).5; }
  CEXP point3d<FP> CR get(u32 i) const {
    assert(i < 3);
    return **(&(this->u) + i);
  }
};

}  // namespace tifa_libs::geo

#endif