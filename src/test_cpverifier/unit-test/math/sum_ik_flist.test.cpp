#define UNITTEST
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../code/math/sum_ik_flist.hpp"

#include "../../../code/math/mpi.hpp"
#include "../../../code/math/qpow.hpp"
#include "../base.hpp"


using tifa_libs::math::mpi;

void test_sum_ik_flist(u64 n) {
  auto sumik_mpi = [](u64 k, u64 n) {
    mpi ret = 0;
    fle_(u64, i, 1, n) ret += qpow(mpi(i), k);
    return ret;
  };

  u64 k = 0;
  for (auto f : tifa_libs::math::sum_ik<mpi>) {
    check(f(n), sumik_mpi(k, n), check_param(k), check_param(n));
    ++k;
  }
}

int main() {
  auto tcase = tifa_libs::unittest::pre_test();

  switch (tcase) {
    case tifa_libs::unittest::ts_example_00:
      flt_(u64, i, 0, 10) test_sum_ik_flist(i);
      break;
    case tifa_libs::unittest::ts_example_01: test_sum_ik_flist(42); break;
    case tifa_libs::unittest::ts_random_00: test_sum_ik_flist(114514); break;
    case tifa_libs::unittest::ts_random_01: break;
    case tifa_libs::unittest::ts_random_02: break;
    case tifa_libs::unittest::ts_random_03: break;
    case tifa_libs::unittest::ts_random_04: break;
    case tifa_libs::unittest::ts_random_05: break;
    case tifa_libs::unittest::ts_random_06: break;
    case tifa_libs::unittest::ts_random_07: break;
    case tifa_libs::unittest::ts_random_08: break;
    case tifa_libs::unittest::ts_random_09: break;
    default: break;
  }

  tifa_libs::unittest::post_test();
}