#include "../../code/util/ndvec.hpp"

#include "../../code/util/traits.hpp"

using std::cout, std::endl;

template <tifa_libs::container_c T>
std::ostream &operator<<(std::ostream &os, T const &x) {
  if (x.begin() == x.end()) return os << "[]";
  os << '[';
  for (auto it = x.begin(); it != x.end() - 1; ++it) os << *it << ", ";
  return os << x.back() << ']';
}

#define OUTPUT_(x) cout << #x << ": " << x << endl

int main() {
  tifa_libs::ndvec<5, int> v(5, 4, 3, 2, 1);
  OUTPUT_(v.dim());
  OUTPUT_(v[0].dim());
  OUTPUT_(v[0][0].dim());
  OUTPUT_(v);
  v.fill(114514);
  OUTPUT_(v);

  cout << "==========" << endl;

  tifa_libs::ndvec<5, int> v2(5, 4, 0, 2, 1);
  OUTPUT_(v2.dim());
  OUTPUT_(v2);
  return 0;
}

// clang-format off
/* outout:
v.dim(): 5
v[0].dim(): 4
v[0][0].dim(): 3
v: [[[[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]]], [[[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]]], [[[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]]], [[[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]]], [[[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]], [[[0], [0]], [[0], [0]], [[0], [0]]]]]
v: [[[[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]]], [[[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]]], [[[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]]], [[[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]]], [[[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]], [[[114514], [114514]], [[114514], [114514]], [[114514], [114514]]]]]
==========
v2.dim(): 5
v2: [[[], [], [], []], [[], [], [], []], [[], [], [], []], [[], [], [], []], [[], [], [], []]]
*/