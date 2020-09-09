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


# :x: test/geometry.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/geometry.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 00:52:04+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B">https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B</a>


## Depends on

* :x: <a href="../../library/others/geometry.cpp.html">others/geometry.cpp</a>
* :question: <a href="../../library/template/template.cpp.html">template/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"
// clang-format off
#include "../template/template.cpp"
#include "../others/geometry.cpp"
// clang-format on

void Main() {
    int xp1 = in(), yp1 = in();
    int xp2 = in(), yp2 = in();
    int q = in();

    Point p1(xp1, yp1), p2(xp2, yp2);
    Line l(p1, p2);

    rep(i, q) {
        int x = in(), y = in();
        Point p(x, y);
        Point r = reflection(p, l);
        cout << r.x << " " << r.y << endl;
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/geometry.test.cpp"
#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"
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
#line 1 "others/geometry.cpp"
using ld = long double;

// epsilon：浮動小数点誤差
constexpr ld EPS = 1e-10;

/*
    x > 0 ならば +1
    x == 0 ならば 0
    x < 0 ならば -1
    を返す。基本的にEPS込みの評価はこれで行う。
    不等式は、加減算に直してこれに適用する
*/
constexpr int sgn(const ld x) { return (x < -EPS ? -1 : (x > EPS ? +1 : 0)); }

struct Point {
    // 2次元ベクトル
    ld x = 0, y = 0;
    Point() = default;
    constexpr Point(const ld _x, const ld _y) : x(_x), y(_y) {}
    constexpr Point operator+() const { return *this; }
    constexpr Point operator-() const { return {-x, -y}; }
    constexpr Point &operator+=(const Point &b) {
        x += b.x, y += b.y;
        return *this;
    }
    constexpr Point &operator-=(const Point &b) {
        *this += (-b);
        return *this;
    }
    constexpr Point &operator*=(const ld b) {
        x *= b, y *= b;
        return *this;
    }
    constexpr Point &operator/=(const ld b) {
        x /= b, y /= b;
        return *this;
    }
    constexpr Point operator+(const Point &b) const {
        Point ret(*this);
        ret += b;
        return ret;
    }
    constexpr Point operator-(const Point &b) const {
        Point ret(*this);
        ret -= b;
        return ret;
    }
    constexpr Point operator*(const ld b) const {
        Point ret(*this);
        ret *= b;
        return ret;
    }
    constexpr Point operator/(const ld b) const {
        Point ret(*this);
        ret /= b;
        return ret;
    }

    constexpr bool operator==(const Point &b) const {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    constexpr bool operator!=(const Point &b) const { return !(*this == b); }
    constexpr ld lengthSquare() const { return x * x + y * y; }
    ld length() const { return std::sqrt(lengthSquare()); }
    constexpr ld dot(const Point &b) const { return x * b.x + y * b.y; }
    constexpr ld cross(const Point &b) const { return x * b.y - y * b.x; }
    constexpr ld distanceSquare(const Point &b) const {
        return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
    }
    ld distanceFrom(const Point &b) const {
        return std::sqrt(distanceSquare(b));
    }
    Point normalized() const { return {x / length(), y / length()}; }
    constexpr bool isZero() const { return sgn(x) == 0 && sgn(y) == 0; }
    // 単位法線ベクトル
    Point normalUnitVector() const { return {-normalized().y, normalized().x}; }
    // (0, 0) を中心に arg （弧度法）回転した座標
    constexpr Point rotate(const ld arg) const {
        ld cs = cos(arg), sn = sin(arg);
        return {x * cs - y * sn, x * sn + y * cs};
    }
    // (0, 0) 中心の円上に乗っているとしたときの、偏角 [-PI, PI]
    constexpr ld angle() const { return atan2(y, x); }
};

inline constexpr Point operator*(ld a, const Point &b) { return b * a; }
template <class Char>
inline std::basic_ostream<Char> &operator<<(std::basic_ostream<Char> &os,
                                            const Point &v) {
    return os << Char('(') << v.x << Char(',') << v.y << Char(')');
}

template <class Char>
inline std::basic_istream<Char> &operator>>(std::basic_istream<Char> &is,
                                            Point &v) {
    return is >> v.x >> v.y;
}

// ソート用
inline constexpr bool operator<(const Point &a, const Point &b) {
    if (sgn(a.x - b.x) != 0)
        return sgn(a.x - b.x) < 0;
    else
        return sgn(a.y - b.y) < 0;
}
/*
    3点 A, B, Cの位置関係を返す (a != b が前提)
    - ABから見てBCは左に曲がるのなら +1
    - ABから見てBCは右に曲がるのなら -1
    - ABC(CBA)の順番で一直線上に並ぶなら +2
    - ACB(BCA)の順番で一直線上に並ぶなら 0
    - BAC(CAB)の順番で一直線上に並ぶなら -2
*/
int iSP(const Point &a, const Point &b, const Point &c) {
    int flg = sgn((b - a).cross(c - a));
    if (flg == 1) {
        return +1;
    } else if (flg == -1) {
        return -1;
    } else {
        // ABC(CBA)
        if (sgn((b - a).dot(c - b)) > 0)
            return +2;
        // BAC(CAB)
        else if (sgn((a - b).dot(c - a)) > 0)
            return -2;
        // ACB(BCA)　C が A or B と一致する場合も含む
        else
            return 0;
    }
}

// 角 ABC が 鋭角：0 / 直角：1 / 鈍角：2
int angletype(const Point &a, const Point &b, const Point &c) {
    auto v = (a - b).dot(c - b);
    if (sgn(v) > 0)
        return 0;
    else if (sgn(v) == 0)
        return 1;
    else
        return 2;
}

struct Line {
    // 直線が通る 2 点
    Point begin = {}, end = {};
    Line() = default;
    constexpr Line(const Point &b, const Point &e) : begin(b), end(e) {}
    // ax + by + c = 0
    Line(const ld a, const ld b, const ld c) {
        if (sgn(a) == 0 && sgn(b) == 0)
            assert(false);
        if (sgn(b) == 0) {
            // ax + c = 0
            begin = {-c / a, 0};
            end = {-c / a, 1};
        } else {
            // y = -(ax + c) / b = -(a / b)x - (c / b)
            begin = {0, -c / b};
            end = {1, -(a + c) / b};
        }
    }
    constexpr Point vec() const { return end - begin; }
    constexpr Point countervec() const { return begin - end; }
};
using Ray = Line;     // 半直線
using Segment = Line; // 線分

template <class T> class Result {
  public:
    Result() = default;
    Result(const T &val) : value(val), isEnable(false) {}
    constexpr bool ok() const { return isEnable; }
    constexpr bool ng() const { return !ok(); }
    T val() const {
        if (ng())
            assert(false);
        return value;
    }

  private:
    T value;
    const bool isEnable = false;
};

// 直線の交点を返す
// 交わらない場合、Result は ng
Result<Point> lineIntersection(const Line &l1, const Line &l2) {
    if (sgn(l1.vec().cross(l2.vec())) == 0)
        return {};

    Point val = l1.begin + l1.vec() * abs((l2.end - l1.begin).cross(l2.vec()) /
                                          l1.vec().cross(l2.vec()));

    return {val};
}

// (線分が共通部分を持つかどうか, 線分の交点) を返す
// 共通部分がない、もしくは交点が一意ではないなら、Result は ng
std::pair<bool, Result<Point>> segmentIntersection(const Segment &s1,
                                                   const Segment &s2) {

    if (iSP(s1.begin, s1.end, s2.begin) * iSP(s1.begin, s1.end, s2.end) <= 0 &&
        iSP(s2.begin, s2.end, s1.begin) * iSP(s2.begin, s2.end, s1.end) <= 0) {
        // 平行ならば、交点は定まらない (完全に重なってるので)
        if (s1.vec().cross(s2.vec()) == 0)
            return std::make_pair(true, Result<Point>());
        else // 交点を lineIntersection() で求める
            return std::make_pair(true, lineIntersection(s1, s2));
    }
    return std::make_pair(false, Result<Point>());
}

// 点 と直線の距離。引数は、点、直線上の2点
ld distanceBetweenPointAndLine(const Point &p, const Line &l) {
    return abs(l.vec().cross(p - l.begin) / l.vec().length());
}

// 点と半直線の距離。引数は、点、半直線(始点から終点方向に延びる)
ld distanceBetweenPointAndRay(const Point &p, const Ray &r) {
    // 始点との距離のパターン
    if (sgn((p - r.begin).dot(r.vec())) < 0)
        return r.begin.distanceFrom(p);
    return abs(r.vec().cross(p - r.begin) / r.vec().length());
}

// 点と線分の距離。引数は、点、線分の両端
ld distanceBetweenPointAndSegment(const Point &p, const Segment &s) {
    if (sgn(s.vec().dot(p - s.begin)) < 0 ||
        sgn(s.countervec().dot(p - s.end)) < 0) {
        // 下ろした垂線は線分の上にはない
        return std::min(p.distanceFrom(s.begin), p.distanceFrom(s.end));
    }
    return distanceBetweenPointAndLine(p, s);
}

// 二線分間の距離
ld distanceBetweenSegmentAndSegment(const Segment &s1, const Segment &s2) {
    if (segmentIntersection(s1, s2).first)
        return 0; //交点を持つ

    return std::min({distanceBetweenPointAndSegment(s1.begin, s2),
                     distanceBetweenPointAndSegment(s1.end, s2),
                     distanceBetweenPointAndSegment(s2.begin, s1),
                     distanceBetweenPointAndSegment(s2.end, s1)});
}

// 点 a の直線 l 上の正射影（点 a から直線 l に下ろした垂線の足）
Point projection(const Point &a, const Line &l) {
    return l.begin +
           l.vec().normalized() * (a - l.begin).dot(l.vec()) / l.vec().length();
}

// 鏡映変換。直線 l について、点 a と線対称な点を求める
Point reflection(const Point &a, const Line &l) {
    return a + 2 * (projection(a, l) - a);
}
#line 6 "test/geometry.test.cpp"
// clang-format on

void Main() {
    int xp1 = in(), yp1 = in();
    int xp2 = in(), yp2 = in();
    int q = in();

    Point p1(xp1, yp1), p2(xp2, yp2);
    Line l(p1, p2);

    rep(i, q) {
        int x = in(), y = in();
        Point p(x, y);
        Point r = reflection(p, l);
        cout << r.x << " " << r.y << endl;
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

