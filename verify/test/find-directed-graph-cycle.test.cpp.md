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


# :heavy_check_mark: test/find-directed-graph-cycle.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/find-directed-graph-cycle.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 14:40:07+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/find-directed-graph-cycle.cpp.html">graph/find-directed-graph-cycle.cpp</a>
* :heavy_check_mark: <a href="../../library/graph/get-shortest-path.cpp.html">graph/get-shortest-path.cpp</a>
* :heavy_check_mark: <a href="../../library/graph/graph-template.cpp.html">graph/graph-template.cpp</a>
* :heavy_check_mark: <a href="../../library/template/template.cpp.html">template/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A"
// clang-format off
#include "../template/template.cpp"
#include "../graph/graph-template.cpp"
#include "../graph/get-shortest-path.cpp"
#include "../graph/find-directed-graph-cycle.cpp"
// clang-format on

void Main() {
    int V = in(), E = in();

    UnWeightedGraph G(V);

    rep(i, E) {
        int s = in(), t = in();
        G[s].push_back(t);
    }

    out(!findDirectedGraphCycle(G).empty());
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/find-directed-graph-cycle.test.cpp"
#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A"
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
#line 1 "graph/graph-template.cpp"
template <typename T = int>
struct Edge {
    int from, to;
    T cost;
    int idx;
    Edge() = default;
    Edge(const int from, const int to, const T cost = 1, const int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
};
template <typename T = int>
using Edges = vector<Edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;

template <typename T = int>
struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(const int n) : g(n), es(0){};

    size_t size() const { return g.size(); }

    void add_directed_edge(const int from, const int to, const T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }
    void add_edge(const int from, const int to, const T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }
};
#line 1 "graph/get-shortest-path.cpp"
vector<int> getShortestPath(const UnWeightedGraph &g, const int s,
                            const int t) {
    vector<int> dist(g.size(), INF), prev(g.size(), -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        const int v = q.front();
        q.pop();
        for (const auto nv : g[v]) {
            if (dist[nv] != INF)
                continue;
            prev[nv] = v;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    if (dist[t] == INF)
        return vector<int>();
    vector<int> shortestPath;
    for (int v = t;; v = prev[v]) {
        shortestPath.push_back(v);
        if (v == s)
            break;
    }
    reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}
#line 1 "graph/find-directed-graph-cycle.cpp"
vector<int> findDirectedGraphCycle(const UnWeightedGraph &g) {
    const int n = g.size();
    vector<int> seen(n, 0), depth(n, -1);
    int cycle_s = -1, cycle_t = -1;
    auto dfs = [&g, &seen, &depth, &cycle_s, &cycle_t](auto &&self,
                                                       const int v) {
        seen[v] = 1;
        int max_depth_nv = -1;
        for (const auto nv : g[v]) {
            if (seen[nv] == 1) { // 後退辺が存在
                if (max_depth_nv == -1 || depth[max_depth_nv] < depth[nv]) {
                    max_depth_nv = nv;
                }
            }
        }
        if (max_depth_nv != -1) {
            cycle_s = max_depth_nv;
            cycle_t = v;
            return true;
        }
        for (const auto nv : g[v]) {
            if (seen[nv] != 0)
                continue;
            depth[nv] = depth[v] + 1;
            if (self(self, nv))
                return true;
        }
        seen[v] = 2;
        return false;
    };
    rep(s, n) {
        if (seen[s] != 0)
            continue;
        depth[s] = 0;
        if (dfs(dfs, s)) {
            return getShortestPath(g, cycle_s, cycle_t);
        }
    }
    return vint();
}
#line 8 "test/find-directed-graph-cycle.test.cpp"
// clang-format on

void Main() {
    int V = in(), E = in();

    UnWeightedGraph G(V);

    rep(i, E) {
        int s = in(), t = in();
        G[s].push_back(t);
    }

    out(!findDirectedGraphCycle(G).empty());
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

