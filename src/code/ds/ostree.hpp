#ifndef TIFALIBS_DS_OSTREE
#define TIFALIBS_DS_OSTREE

#include "../util/util.hpp"

namespace tifa_libs::ds {

struct ostree_tag_base {
  template <class pointer>
  static CEXP u32 size(pointer p) { return p ? p->sz : 0; }
  template <class pointer>
  static CEXP u32 count(pointer p) { return p ? p->sz - size(p->ch[0]) - size(p->ch[1]) : 0; }
  // [size(begin), size(begin->fa), ..., size(end)) += v
  template <class pointer>
  static CEXP void modify_size(pointer begin, i32 v, pointer end = nullptr) {
    while (begin != end) begin->sz += (u32)v, begin = begin->fa;
  }

  template <class pointer, class F>
  requires requires(pointer p, F &&f) { f(p); }
  static CEXP void pre_order(pointer p, F &&f) {
    if (p) f(p), pre_order(p->ch[0], std::forward<F>(f)), pre_order(p->ch[1], std::forward<F>(f));
  }
  template <class pointer, class F>
  requires requires(pointer p, F f) { f(p); }
  static CEXP void in_order(pointer p, F &&f) {
    if (p) in_order(p->ch[0], std::forward<F>(f)), f(p), in_order(p->ch[1], std::forward<F>(f));
  }
  template <class pointer, class F>
  requires requires(pointer p, F f) { f(p); }
  static CEXP void post_order(pointer p, F &&f) {
    if (p) post_order(p->ch[0], std::forward<F>(f)), post_order(p->ch[1], std::forward<F>(f)), f(p);
  }

  template <class pointer>
  static CEXP pointer most(pointer p, bool dir) {
    if (!p) return nullptr;
    while (p->ch[dir]) p = p->ch[dir];
    return p;
  }
  template <class pointer>
  static CEXP pointer neighbour(pointer p, bool dir) {
    if (!p) return nullptr;
    if (p->ch[dir]) return most(p->ch[dir], !dir);
    while (p && p->fa && p->child_dir() == dir) p = p->fa;
    return p ? p->fa : nullptr;
  }
  template <class pointer>
  static CEXP auto leftmost(pointer p) { return most(p, 0); }
  template <class pointer>
  static CEXP auto rightmost(pointer p) { return most(p, 1); }
  template <class pointer>
  static CEXP auto prev(pointer p) { return neighbour(p, 0); }
  template <class pointer>
  static CEXP auto next(pointer p) { return neighbour(p, 1); }

  template <class pointer>
  static CEXP pointer rotate(pointer &root, pointer p, bool dir) {
    auto g = p->fa, s = p->ch[!dir];
    u32 psz = p->sz, ssz = s->sz;
    s->sz = psz, p->sz += size(s->ch[dir]) - ssz;
    auto c = s->ch[dir];
    if (c) c->fa = p;
    p->ch[!dir] = c, s->ch[dir] = p, p->fa = s, s->fa = g;
    return (g ? g->ch[p == g->ch[1]] : root) = s;
  }
};
struct bst_tag : ostree_tag_base {
  template <class pointer, class K, class Alloc, class Comp>
  CEXP pointer insert(pointer &root, const K &data, Alloc &alloc, Comp compare) {
    pointer now = root, p = nullptr;
    bool dir = 0;
    while (now)
      if (dir = compare((p = now)->data, data), now = now->ch[dir]; !dir && !compare(data, p->data)) return ostree_tag_base::modify_size(p, 1), p;
    pointer n = alloc.allocate(1);
    n->fa = n->ch[0] = n->ch[1] = nullptr, n->data = data, n->sz = 1;
    return ostree_tag_base::modify_size(p, 1), insert_leaf(root, p, n, dir), n;
  }
  template <class pointer, class Alloc, bool erase_node = true>
  CEXP pointer erase(pointer &root, pointer p, Alloc &alloc) {
    if (!p) return nullptr;
    if CEXP (erase_node || ostree_tag_base::count(p) == 1) {
      pointer result;
      if (p->ch[0] && p->ch[1]) {
        auto s = ostree_tag_base::leftmost(p->ch[1]);
        std::swap(s->data, p->data), ostree_tag_base::modify_size(s, (i32)ostree_tag_base::count(p) - (i32)ostree_tag_base::count(s), p), result = p, p = s;
      } else result = ostree_tag_base::next(p);
      return ostree_tag_base::modify_size(p, -(i32)ostree_tag_base::count(p)), erase_branch_leaf(root, p), alloc.deallocate(p, 1), result;
    } else return ostree_tag_base::modify_size(p, -1), p;
  }

  //! will NOT change sz
  template <class pointer>
  static CEXP void insert_leaf(pointer &root, pointer p, pointer n, bool dir) {
    if (!p) return void(root = n);
    p->ch[dir] = n, n->fa = p;
  }
  //! will NOT change sz
  template <class pointer>
  static CEXP void erase_branch_leaf(pointer &root, pointer n) {
    auto p = n->fa, s = n->ch[0] ? n->ch[0] : n->ch[1];
    if (s) s->fa = p;
    if (!p) return void(root = s);
    p->ch[n->child_dir()] = s;
  }
};

template <class T, class K>
struct ostree_node_t {};
template <class K>
struct ostree_node_t<bst_tag, K> {
  ostree_node_t *fa, *ch[2];
  K data;
  u32 sz;
  // @return child direction of this non-root point
  CEXP bool child_dir() const { return this == fa->ch[1]; }
};

template <class K, std::derived_from<ostree_tag_base> tag_t, class Comp = std::less<K>, template <class> class Alloc = std::pmr::polymorphic_allocator>
requires requires(ostree_node_t<tag_t, K> *&root, ostree_node_t<tag_t, K> n, tag_t tag, bool dir, K key, Alloc<K> alloc, Comp comp) {
  n.fa->ch[0]->ch[1]->data;
  n.sz;
  { comp(key, key) } -> std::same_as<bool>;
  { n.child_dir() } -> std::same_as<bool>;
  { tag.size(&n) } -> std::same_as<u32>;
  tag.insert(root, key, alloc, comp);
  tag.erase(root, &n, alloc);
}
struct ostree : tag_t {
  using node_t = ostree_node_t<tag_t, K>;
  using pointer = node_t *;
  using const_pointer = const node_t *;
  using pointer_const = node_t *const;

  static constexpr Comp compare{};
  pointer root;

  CEXP ostree() : tag_t(), root{nullptr} {}
  CEXP ~ostree() {
    tag_t::post_order(root, [this](auto it) { alloc.deallocate(it, 1); });
  }
  CEXP u32 size() const { return tag_t::size(root); }

  CEXP pointer lower_bound(const K &key) const {
    const_pointer now = root, ans = nullptr;
    while (now) {
      if (!compare(now->data, key)) ans = now, now = now->ch[0];
      else now = now->ch[1];
    }
    return (pointer)ans;
  }
  CEXP pointer upper_bound(const K &key) const {
    const_pointer now = root, ans = nullptr;
    while (now) {
      if (compare(key, now->data)) ans = now, now = now->ch[0];
      else now = now->ch[1];
    }
    return (pointer)ans;
  }
  CEXP pointer find(const K &key) const {
    auto p = lower_bound(key);
    return (!p || compare(p->data, key) || compare(key, p->data)) ? nullptr : p;
  }
  // Order start from 0
  CEXP u32 order_of_key(const K &key) const {
    u32 ans = 0;
    auto now = root;
    while (now) {
      if (!compare(now->data, key)) now = now->ch[0];
      else ans += tag_t::size(now->ch[0]) + tag_t::count(now), now = now->ch[1];
    }
    return ans;
  }
  // Order start from 0
  CEXP const_pointer find_by_order(u32 order) const {
    const_pointer now = root, ans = nullptr;
    while (now && now->sz >= order)
      if (auto lsz = tag_t::size(now->ch[0]), cnt = tag_t::count(now); order < lsz) now = now->ch[0];
      else {
        if (ans = now; order < lsz + cnt) break;
        now = now->ch[1], order -= lsz + cnt;
      }
    return ans;
  }
  CEXP const_pointer insert(const K &data) { return tag_t::insert(root, data, alloc, compare); }
  //! count -= 1
  CEXP bool erase(const K &key) {
    if (auto p = find(key); !p) return false;
    else return tag_t::template erase<pointer, K, Alloc, false>(root, p, alloc), true;
  }
  CEXP const_pointer erase(pointer p) { return tag_t::erase(root, p, alloc); }

 private:
  Alloc<node_t> alloc;
};

template <class K, class Comp = std::less<K>>
using bstree = ostree<K, bst_tag, Comp>;

}  // namespace tifa_libs::ds

#endif