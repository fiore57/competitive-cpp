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


# :warning: structure/swag.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/swag.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 23:03:34+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T, typename S>
class SWAG {
    using F1 = function<S(S, T)>;
    using F2 = function<S(T, S)>;
    const F1 f1;
    const F2 f2;
    S id;
    vector<T> lt, rt;
    vector<S> ls, rs;

public:
    SWAG(const F1 f1, const F2 f2, const S id)
        : f1(f1), f2(f2), id(id), ls(1, id), rs(1, id) {}
    // S, T identical / commutative is not required
    // clang-format off
    SWAG(const F1 f1, const S id)
        : SWAG(f1, [&f1](const T y, const S x) { return f1(y, x); }, id) {}
    // clang-format on

    void push(const T x) {
        rt.emplace_back(x);
        rs.emplace_back(f1(rs.back(), x));
    }

    void pop() {
        if (lt.empty()) {
            reverse(rt.begin(), rt.end());
            for (auto x : rt) {
                lt.emplace_back(x);
                ls.emplace_back(f2(x, ls.back()));
            }
            rt.resize(0);
            rs.resize(1);
        }
        lt.pop_back();
        ls.pop_back();
    }

    template <typename Q>
    void fold(const Q q) const {
        q(ls.back(), rs.back());
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/swag.cpp"
template <typename T, typename S>
class SWAG {
    using F1 = function<S(S, T)>;
    using F2 = function<S(T, S)>;
    const F1 f1;
    const F2 f2;
    S id;
    vector<T> lt, rt;
    vector<S> ls, rs;

public:
    SWAG(const F1 f1, const F2 f2, const S id)
        : f1(f1), f2(f2), id(id), ls(1, id), rs(1, id) {}
    // S, T identical / commutative is not required
    // clang-format off
    SWAG(const F1 f1, const S id)
        : SWAG(f1, [&f1](const T y, const S x) { return f1(y, x); }, id) {}
    // clang-format on

    void push(const T x) {
        rt.emplace_back(x);
        rs.emplace_back(f1(rs.back(), x));
    }

    void pop() {
        if (lt.empty()) {
            reverse(rt.begin(), rt.end());
            for (auto x : rt) {
                lt.emplace_back(x);
                ls.emplace_back(f2(x, ls.back()));
            }
            rt.resize(0);
            rs.resize(1);
        }
        lt.pop_back();
        ls.pop_back();
    }

    template <typename Q>
    void fold(const Q q) const {
        q(ls.back(), rs.back());
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

