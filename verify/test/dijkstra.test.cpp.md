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


# :heavy_check_mark: test/dijkstra.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/dijkstra.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 14:48:03+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_B">https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/dijkstra.cpp.html">graph/dijkstra.cpp</a>
* :heavy_check_mark: <a href="../../library/graph/graph-template.cpp.html">graph/graph-template.cpp</a>
* :question: <a href="../../library/template/template.cpp.html">template/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_B"
// clang-format off
#include "../template/template.cpp"
#include "../graph/graph-template.cpp"
#include "../graph/dijkstra.cpp"
// clang-format on

void Main() {
    int N = in();

    Graph<int> graph(N);
    rep(i, N) {
        int u = in(), k = in();
        rep(j, k) {
            int v = in(), c = in();
            graph.add_directed_edge(u, v, c);
        }
    }

    auto v = dijkstra(graph, 0).dist;
    rep(i, N) cout << i << " " << v[i] << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/dijkstra.test.cpp"
#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_B"
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
#line 1 "graph/dijkstra.cpp"
template <typename T> struct ShortestPath {
    vector<T> dist;
    vector<int> from, id;
};

template <typename T> ShortestPath<T> dijkstra(const Graph<T> &g, const int s) {
    constexpr auto INF = numeric_limits<T>::max();
    using Pi = pair<T, int>;

    vector<int> from(g.size(), -1), id(g.size(), -1);
    vector<T> dist(g.size(), INF);
    priority_queue<Pi, vector<Pi>, greater<>> que;

    dist[s] = 0;
    que.emplace(dist[s], s);

    while (!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();

        if (dist[idx] < cost)
            continue;

        for (const auto &e : g.g[idx]) {
            auto next_cost = cost + e.cost;
            if (dist[e.to] <= next_cost)
                continue;
            dist[e.to] = next_cost;
            from[e.to] = idx;
            id[e.to] = e.idx;
            que.emplace(dist[e.to], e.to);
        }
    }

    return {dist, from, id};
}
#line 7 "test/dijkstra.test.cpp"
// clang-format on

void Main() {
    int N = in();

    Graph<int> graph(N);
    rep(i, N) {
        int u = in(), k = in();
        rep(j, k) {
            int v = in(), c = in();
            graph.add_directed_edge(u, v, c);
        }
    }

    auto v = dijkstra(graph, 0).dist;
    rep(i, N) cout << i << " " << v[i] << endl;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
