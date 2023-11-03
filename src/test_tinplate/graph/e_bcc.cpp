#define PROBLEM "https://www.luogu.com.cn/problem/P8436"

#include "../../code/graph/e_bcc.hpp"


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, m;
  std::cin >> n >> m;
  struct EW {
    u32 inv;
  };
  tifa_libs::graph::adjlist<void, EW> e(n);
  for (u32 i = 0, u, v; i < m; ++i) {
    std::cin >> u >> v;
    if(u == v) continue;
    --u, --v;
    u32 tem1 = e[u].size(), tem2 = e[v].size();
    e.add_arc(u, v, EW{tem2});
    e.add_arc(v, u, EW{tem1});
  }
  tifa_libs::graph::e_bcc<void, EW> bcc(e);
  std::cout << bcc.id << '\n';
  for (u32 i = 0; i < bcc.id; ++i) {
    std::cout << bcc.belongs[i].size() << ' ';
    for (auto x : bcc.belongs[i])
      std::cout << x + 1 << ' ';
    std::cout << '\n';
  }
  return 0;
}
/*
# 【模板】边双连通分量

## 题目描述

对于一个 $n$ 个节点 $m$ 条无向边的图，请输出其边双连通分量的个数，并且输出每个边双连通分量。

## 输入格式

第一行，两个整数 $n$ 和 $m$。

接下来 $m$ 行，每行两个整数 $u, v$，表示一条无向边。

## 输出格式

第一行一个整数 $x$ 表示边双连通分量的个数。

接下来的 $x$ 行，每行第一个数 $a$ 表示该分量结点个数，然后 $a$ 个数，描述一个边双连通分量。

你可以以任意顺序输出边双连通分量与边双连通分量内的结点。

## 样例 #1

### 样例输入 #1

```
5 8
1 3
2 4
4 3
1 2
4 5
5 1
2 4
1 1
```

### 样例输出 #1

```
1
5 1 5 4 2 3
```

## 样例 #2

### 样例输入 #2

```
5 3
1 2
2 3
1 3
```

### 样例输出 #2

```
3
3 1 3 2
1 4
1 5
```

## 样例 #3

### 样例输入 #3

```
6 5
1 3
2 4
1 2
4 6
2 3
```

### 样例输出 #3

```
4
3 1 2 3
1 4
1 5
1 6
```

## 样例 #4

### 样例输入 #4

```
7 8
1 3
2 4
3 5
2 5
6 4
2 5
6 3
2 7
```

### 样例输出 #4

```
3
1 1
5 2 5 3 6 4
1 7
```

## 提示

**样例四解释：**

![](https://cdn.luogu.com.cn/upload/image_hosting/0bzdfzeq.png)

相同颜色的点为同一个连通分量。


------------

**数据范围：**
对于 $100\%$ 的数据，$1 \le n \le 5 \times10 ^5$，$1 \le m \le 2 \times 10^6$。

| subtask | $n$ | $m$ | 分值 |
| :----------: | :----------: | :----------: | :----------: |
| $1$ | $1 \le n \le 100$ | $1 \le m \le 500$ | $25$ |
| $2$ | $1 \le n \le 5000$ | $1 \le m \le 5 \times 10^4$ | $25$ |
| $3$ | $1 \le n \le 2\times 10^5$ | $1 \le m \le 5\times 10^5$ | $25$ |
| $4$ | $1 \le n \le 5 \times10 ^5$ | $1 \le m \le 2 \times 10^6$ | $25$ |

### 数据更新
- $2022/7/14$ 加强数据
- $2022/11/26$  新增 $10$ 组较小的数据（$1\le n, m \le 10$)，方便选手调试。
- $2022/12/31$ 重组 $subtask$，并加入若干组极端数据。
- $2023/1/1$ 发现昨天新加入的数据数据出了问题，已修改。
------------

本题不卡常，时间限制与空间限制均已开大，正确的解法均可通过。


------------

惊喜：AC 后记得把鼠标放到测试点上看反馈信息，有惊喜哦。
*/