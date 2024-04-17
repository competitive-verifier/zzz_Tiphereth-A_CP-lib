#define PROBLEM "https://www.luogu.com.cn/problem/P5180"

#include "../../code/graph/domtree.hpp"

#include "../../code/io/ios_container.hpp"
#include "../../code/tree/dfs_info.hpp"
#include "../../code/tree/tree.hpp"


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u32 n, m;
  std::cin >> n >> m;
  tifa_libs::graph::alist<> g(n);
  for (u32 i = 0, u, v; i < m; ++i) {
    std::cin >> u >> v;
    g.add_arc(u - 1, v - 1);
  }
  auto fa = tifa_libs::graph::domtree(g).get_domtree(0);
  tifa_libs::graph::tree tr(n);
  for (u32 i = 1; i < n; ++i)
    if (~fa[i]) tr.add_arc(fa[i], i);
  tifa_libs::graph::tree_dfs_info<tifa_libs::graph::tree> dfs;
  dfs.reset_dfs_info<tifa_libs::graph::td_sz>(tr);
  std::cout << dfs.sz << '\n';
  return 0;
}

/*
给定一张有向图, 求从 1 号点出发, 每个点能支配的点的个数 (包括自己)

## 输入格式

第一行两个正整数 $n,m$, 表示点数和边数

接下来 $m$ 行, 每行输入两个整数 $u,v$, 表示有一条 $u$ 到 $v$ 的有向边

## 输出格式

一行输出 $n$ 个整数, 表示每个点能支配的点的个数

## 提示

$n\le2*10^5,m\le3*10^5$
*/

/*
10 15
1 2
2 3
3 4
3 5
3 6
4 7
7 8
7 9
7 10
5 6
6 8
7 8
4 1
3 6
5 3
========================
10 9 8 4 1 1 3 1 1 1
*/