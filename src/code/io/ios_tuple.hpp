#ifndef TIFALIBS_IO_IOS_TUPLE
#define TIFALIBS_IO_IOS_TUPLE

#include "../util/util.hpp"

template <class... Ts>
std::istream &operator>>(std::istream &is, std::tuple<Ts...> &p) {
  std::apply([&](Ts &...targs) { ((is >> targs), ...); }, p);
  return is;
}
template <class... Ts>
std::ostream &operator<<(std::ostream &os, std::tuple<Ts...> const &p) {
  std::apply(
      [&](Ts const &...targs) {
        usz n = 0;
        ((os << targs << (++n != sizeof...(Ts) ? " " : "")), ...);
      },
      p);
  return os;
}

#endif