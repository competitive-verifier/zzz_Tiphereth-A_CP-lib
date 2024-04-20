#define PROBLEM "https://www.luogu.com.cn/problem/P3377"

#include "../../code/ds/leftist_tree.hpp"

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, m;
  std::cin >> n >> m;
  vec<i32> a(n);
  for (auto& x : a) std::cin >> x;
  tifa_libs::ds::leftist_tree<i32> tr(a);
  u32 opt, x, y;
  for (u32 i = 0; i < m; ++i) {
    std::cin >> opt >> x, --x;
    if (opt == 1) {
      std::cin >> y, --y;
      tr.merge(x, y);
    } else {
      auto ret = tr.pop(x);
      if (!ret.has_value()) std::cout << "-1\n";
      else std::cout << ret.value() << '\n';
    }
  }
  return 0;
}

/*
如题, 一开始有 $n$ 个小根堆, 每个堆包含且仅包含一个数. 接下来需要支持两种操作:

1. `1 x y`: 将第 $x$ 个数和第 $y$ 个数所在的小根堆合并 (若第 $x$ 或第 $y$ 个数已经被删除或第 $x$ 和第 $y$ 个数在用一个堆内, 则无视此操作)

2. `2 x`: 输出第 $x$ 个数所在的堆最小数, 并将这个最小数删除 (若有多个最小数, 优先删除先输入的; 若第 $x$ 个数已经被删除, 则输出 $-1$ 并无视删除操作)

## 输入格式

第一行包含两个正整数 $n, m$, 分别表示一开始小根堆的个数和接下来操作的个数

第二行包含 $n$ 个正整数, 其中第 $i$ 个正整数表示第 $i$ 个小根堆初始时包含且仅包含的数

接下来 $m$ 行每行 $2$ 个或 $3$ 个正整数, 表示一条操作, 格式如下:

操作 $1$: `1 x y`

操作 $2$: `2 x`

## 输出格式

输出包含若干行整数, 分别依次对应每一个操作 $2$ 所得的结果

## 提示

**[数据规模]**

对于 $30\%$ 的数据: $n\le 10$, $m\le 10$
对于 $70\%$ 的数据: $n\le 10^3$, $m\le 10^3$
对于 $100\%$ 的数据: $n\le 10^5$, $m\le 10^5$, 初始时小根堆中的所有数都在 `int` 范围内

**[样例解释]**

初始状态下, 五个小根堆分别为: $\{1\}$, $\{5\}$, $\{4\}$, $\{2\}$, $\{3\}$

第一次操作, 将第 $1$ 个数所在的小根堆与第 $5$ 个数所在的小根堆合并, 故变为四个小根堆: $\{1,3\}$, $\{5\}$, $\{4\}$, $\{2\}$

第二次操作, 将第 $2$ 个数所在的小根堆与第 $5$ 个数所在的小根堆合并, 故变为三个小根堆: $\{1,3,5\}$, $\{4\}$, $\{2\}$

第三次操作, 将第 $2$ 个数所在的小根堆的最小值输出并删除, 故输出 $1$, 第一个数被删除, 三个小根堆为: $\{3,5\}$, $\{4\}$, $\{2\}$

第四次操作, 将第 $4$ 个数所在的小根堆与第 $2$ 个数所在的小根堆合并, 故变为两个小根堆: $\{2,3,5\}$, $\{4\}$

第五次操作, 将第 $2$ 个数所在的小根堆的最小值输出并删除, 故输出 $2$, 第四个数被删除, 两个小根堆为: $\{3,5\}$, $\{4\}$

故输出依次为 $1$, $2$
*/

/*
5 5
1 5 4 2 3
1 1 5
1 2 5
2 2
1 4 2
2 2
===========
1
2
*/