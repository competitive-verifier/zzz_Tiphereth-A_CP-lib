#define UNITTEST

#include "../../../code/math/sum_ik_flist.hpp"

#include "../../../code/math/mpi.hpp"
#include "../../../code/math/qpow.hpp"

using tifa_libs::u64;
using tifa_libs::math::mpi;

mpi sumik_mpi(u64 k, u64 n) {
  mpi ret = 0;
  for (u64 i = 1; i <= n; ++i) ret += qpow(mpi(i), k);
  return ret;
}

void test_sum_ik_flist(u64 n) {
  u64 k = 0;
  for (auto f : tifa_libs::math::sum_ik<mpi>) {
    auto got = f(n), want = sumik_mpi(k, n);
    if (got != want) throw std::runtime_error("WA at k = " + std::to_string(k) + ", n = " + std::to_string(n) + ", got " + got.to_str() + ", want " + want.to_str());
    ++k;
  }
}

int main() {
  test_sum_ik_flist(0);
  test_sum_ik_flist(1);
  test_sum_ik_flist(42);
  test_sum_ik_flist(114514);
  return 0;
}