---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: test/segtree-lazy.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/segtree-lazy.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 14:59:26+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F</a>


## Depends on

* :heavy_check_mark: <a href="../../library/structure/segtree-lazy.cpp.html">structure/segtree-lazy.cpp</a>
* :question: <a href="../../library/template/template.cpp.html">template/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"
// clang-format off
#include "../template/template.cpp"
#include "../structure/segtree-lazy.cpp"
// clang-format on

void Main() {
    int n = in(), q = in();
    int ti = (1ll << 31) - 1;
    int ei = ti;
    auto f = [](int a, int b) { return min(a, b); };
    auto g = [ei](int a, int b) { return b == ei ? a : b; };
    auto h = [ei](int a, int b) { return b == ei ? a : b; };
    SegmentTree<int, int> seg(n, f, g, h, ti, ei);
    while (q--) {
        int com = in(), s = in(), t = in();
        if (com == 0) {
            int x = in();
            seg.update(s, t + 1, x);
        } else
            cout << seg.query(s, t + 1) << '\n';
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/segtree-lazy.test.cpp"
#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"
// clang-format off
#line 1 "template/template.cpp"
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#ifdef _DEBUG
#define DUMP(x) std::cerr << (#x) << " = " << (x) << "\n"
#else
#define DUMP(x)
#endif
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define EREP(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define RREP(i, a, b) for (int i = (int)(a)-1; i >= (int)(b); --i)
#define rep(i, n) REP(i, 0, n)
#define erep(i, n) EREP(i, 0, n)
#define rrep(i, n) RREP(i, n, 0)
#define ALL(r) (r).begin(), (r).end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    rep(i, v.size()) os << v[i] << (i == (int)v.size() - 1 ? "" : ", ");
    os << "}";
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    return (os << "(" << p.first << ", " << p.second << ")");
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &m) {
    bool first = true;
    os << "{";
    for (const auto &e : m) {
        if (!first)
            os << ", ";
        os << "{" << e.first << ": " << e.second << "}";
        first = false;
    }
    os << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &s) {
    os << "{";
    bool first = true;
    for (const auto &e : s) {
        if (!first)
            os << ", ";
        os << e;
        first = false;
    }
    os << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &s) {
    os << "{";
    bool first = true;
    for (const auto &e : s) {
        if (!first)
            os << ", ";
        os << e;
        first = false;
    }
    os << "}";
    return os;
}
template <typename T>
T dup(T x, T y) {
    return (x + y - 1) / y;
};
template <typename A, size_t N, typename T>
inline void arrayFill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
struct in {
    const size_t n = 0;
    in() = default;
    in(size_t n) : n(n){};
    template <typename T>
    operator T() {
        T ret;
        cin >> ret;
        return ret;
    }
    template <typename T>
    operator vector<T>() {
        assert(n != 0);
        vector<T> ret(n);
        for (T &x : ret) {
            T tmp = in();
            x = tmp;
        }
        return ret;
    }
    template <typename T, typename U>
    operator pair<T, U>() {
        pair<T, U> ret;
        ret.first = in();
        ret.second = in();
        return ret;
    }
};

namespace fiore {
namespace impl {
template <typename T>
inline void out_impl(const T &x, char end_char) {
    std::cout << x << end_char;
}
template <typename T>
inline void out_impl(const vector<T> &x, char end_char) {
    bool first = true;
    for (const auto &e : x) {
        if (!first)
            std::cout << ' ';
        std::cout << e;
        first = false;
    }
    std::cout << end_char;
}
} // namespace impl
} // namespace fiore
template <typename T>
inline void out(const T &x) {
    fiore::impl::out_impl(x, '\n');
};
template <typename T, typename U, typename... Args>
inline void out(const T &x, const U &y, const Args &... args) {
    fiore::impl::out_impl(x, ' ');
    out(y, args...);
}

using ll = int64_t;
using vint = vector<int32_t>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pint = pair<int32_t, int32_t>;
using vpint = vector<pint>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using setint = set<int32_t>;
using qint = queue<int32_t>;
using qpint = queue<pint>;

constexpr std::int32_t INF = 1001001001;
constexpr std::int64_t LINF = 1001001001001001001;

void Main();

signed main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
#line 1 "structure/segtree-lazy.cpp"
template <typename T, typename E>
class SegmentTree {
    using F = function<T(T, T)>;
    using G = function<T(T, E)>;
    using H = function<E(E, E)>;
    int n, height;
    const F f;
    const G g;
    const H h;
    const T ti;
    const E ei;
    vector<T> dat;
    vector<E> laz;

public:
    SegmentTree(const int n_, const F f, const G g, const H h, const T ti,
                const E ei, const vector<T> &v = vector<T>())
        : f(f), g(g), h(h), ti(ti), ei(ei) {
        init(n_);
        if (n_ == (int)v.size())
            build(n_, v);
    }

private:
    void init(const int n_) {
        n = 1;
        height = 0;
        while (n < n_)
            n <<= 1, height++;
        dat.assign(2 * n, ti);
        laz.assign(2 * n, ei);
    }

    void build(const int n_, const vector<T> &v) {
        for (int i = 0; i < n_; i++)
            dat[n + i] = v[i];
        for (int i = n - 1; i; i--)
            dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }

    inline T reflect(const int k) {
        return laz[k] == ei ? dat[k] : g(dat[k], laz[k]);
    }

    inline void propagate(const int k) {
        if (laz[k] == ei)
            return;
        laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
        laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
        dat[k] = reflect(k);
        laz[k] = ei;
    }

    inline void thrust(const int k) {
        for (int i = height; i; i--)
            propagate(k >> i);
    }

    inline void recalc(int k) {
        while (k >>= 1)
            dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
    }

    template <typename C>
    int find(const int st, const C &check, T &acc, const int k, const int l,
             const int r) {
        if (l + 1 == r) {
            acc = f(acc, reflect(k));
            return check(acc) ? k - n : -1;
        }
        propagate(k);
        int m = (l + r) >> 1;
        if (m <= st)
            return find(st, check, acc, (k << 1) | 1, m, r);
        if (st <= l && !check(f(acc, dat[k]))) {
            acc = f(acc, dat[k]);
            return -1;
        }
        int vl = find(st, check, acc, (k << 1) | 0, l, m);
        if (~vl)
            return vl;
        return find(st, check, acc, (k << 1) | 1, m, r);
    }

public:
    void update(int a, int b, const E x) {
        if (a >= b)
            return;
        thrust(a += n);
        thrust(b += n - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                laz[l] = h(laz[l], x), l++;
            if (r & 1)
                --r, laz[r] = h(laz[r], x);
        }
        recalc(a);
        recalc(b);
    }

    void set_val(int a, const T x) {
        thrust(a += n);
        dat[a] = x;
        laz[a] = ei;
        recalc(a);
    }

    T query(int a, int b) {
        if (a >= b)
            return ti;
        thrust(a += n);
        thrust(b += n - 1);
        T vl = ti, vr = ti;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                vl = f(vl, reflect(l++));
            if (r & 1)
                vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }

    template <typename C>
    int find(const int st, const C &check) {
        T acc = ti;
        return find(st, check, acc, 1, 0, n);
    }
};
#line 6 "test/segtree-lazy.test.cpp"
// clang-format on

void Main() {
    int n = in(), q = in();
    int ti = (1ll << 31) - 1;
    int ei = ti;
    auto f = [](int a, int b) { return min(a, b); };
    auto g = [ei](int a, int b) { return b == ei ? a : b; };
    auto h = [ei](int a, int b) { return b == ei ? a : b; };
    SegmentTree<int, int> seg(n, f, g, h, ti, ei);
    while (q--) {
        int com = in(), s = in(), t = in();
        if (com == 0) {
            int x = in();
            seg.update(s, t + 1, x);
        } else
            cout << seg.query(s, t + 1) << '\n';
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
