#ifndef TIFA_LIBS_GEO2D_EXTAN_CC
#define TIFA_LIBS_GEO2D_EXTAN_CC

#include "circle.hpp"
#include "line_class.hpp"
#include "tan_cp.hpp"

namespace tifa_libs::geo2d {

// external tagante lines of 2 circles
// maybe duplicate
template <class FP>
std::optional<ptt<line<FP>>> extan_CC(circle<FP> const &c1, circle<FP> const &c2) {
  if (is_eq(c1.o.x, c2.o.x) && is_eq(c1.o.y, c2.o.y)) return {};
  if (is_eq(c1.r, c2.r)) {
    point dr = (c2.o - c1.o).do_unit().do_rot90() * c1.r;
    return {{c1.o + dr, c2.o + dr}, {c1.o - dr, c2.o - dr}};
  }
  point p = (c2.o * c1.r - c1.o * c2.r) / (c1.r - c2.r);
  auto ps = tan_CP(c1, p), qs = tan_CP(c2, p);
  if (!ps.has_value() || !qs.has_value()) return {};
  // c1 counter-clock wise
  return {{ps[0], qs[0]}, {ps[1], qs[1]}};
}

}  // namespace tifa_libs::geo2d

#endif