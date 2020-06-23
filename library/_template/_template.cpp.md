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


# :heavy_check_mark: _template/_template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#dd743839bbbccf6b9f92c191458344b7">_template</a>
* <a href="{{ site.github.repository_url }}/blob/master/_template/_template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-23 14:50:58+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/bellman-ford.test.cpp.html">test/bellman-ford.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/scc.test.cpp.html">test/scc.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/union-find.test.cpp.html">test/union-find.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
ostream &operator<<(ostream &os, vector<T> &v) {
    os << "{";
    rep(i, v.size()) os << v[i] << (i == (int)v.size() - 1 ? "" : ", ");
    os << "}";
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p) {
    return (os << "(" << p.first << ", " << p.second << ")");
}
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &m) {
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
ostream &operator<<(ostream &os, set<T> &s) {
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

namespace fiore::impl {
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
} // namespace fiore::impl
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "_template/_template.cpp"
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
ostream &operator<<(ostream &os, vector<T> &v) {
    os << "{";
    rep(i, v.size()) os << v[i] << (i == (int)v.size() - 1 ? "" : ", ");
    os << "}";
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p) {
    return (os << "(" << p.first << ", " << p.second << ")");
}
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &m) {
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
ostream &operator<<(ostream &os, set<T> &s) {
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

namespace fiore::impl {
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
} // namespace fiore::impl
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

