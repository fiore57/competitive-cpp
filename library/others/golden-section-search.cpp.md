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


# :warning: others/golden-section-search.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e2bab0ecb94c4ea40777733195abe1b">others</a>
* <a href="{{ site.github.repository_url }}/blob/master/others/golden-section-search.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 14:22:16+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
constexpr double GRAITO = 1.6180339887498948482045868343656;
// 黄金分割探索
// f(x)が区間[lb, ub]で下に凸ならば、その極値を取るxを返す
// 反復時に値が使い回せるので、fの計算が1回で済む
// f: 凸関数
// lb: 下限
// ub: 上限
// k: 反復回数
double goldenSectionSearch(function<double(double)> f, double lb, double ub,
                           int k) {
    double x1 = (ub - lb) / (GRAITO + 1) + lb; // 内分点(1:GRAITO)
    double x2 = (ub - lb) / GRAITO + lb;       // 内分点(GRAITO:1)
    double f1 = f(x1), f2 = f(x2);

    rep(i, k) {
        if (f1 < f2) {
            // 右側の区間を除外する
            ub = x2;
            x2 = x1; // 内分点（左）を次の内分点（右）に採用する
            f2 = f1;
            x1 = (ub - lb) / (GRAITO + 1) + lb; // 次の内分点（左）を計算する
            f1 = f(x1);
        } else {
            // 左側の区間を除外する
            lb = x1;
            x1 = x2; // 内分点（右）を次の内分点（左）に採用する
            f1 = f2;
            x2 = (ub - lb) / GRAITO + lb; // 次の内分点（右）を計算する
            f2 = f(x2);
        }
    }
    return (lb + ub) / 2;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "others/golden-section-search.cpp"
constexpr double GRAITO = 1.6180339887498948482045868343656;
// 黄金分割探索
// f(x)が区間[lb, ub]で下に凸ならば、その極値を取るxを返す
// 反復時に値が使い回せるので、fの計算が1回で済む
// f: 凸関数
// lb: 下限
// ub: 上限
// k: 反復回数
double goldenSectionSearch(function<double(double)> f, double lb, double ub,
                           int k) {
    double x1 = (ub - lb) / (GRAITO + 1) + lb; // 内分点(1:GRAITO)
    double x2 = (ub - lb) / GRAITO + lb;       // 内分点(GRAITO:1)
    double f1 = f(x1), f2 = f(x2);

    rep(i, k) {
        if (f1 < f2) {
            // 右側の区間を除外する
            ub = x2;
            x2 = x1; // 内分点（左）を次の内分点（右）に採用する
            f2 = f1;
            x1 = (ub - lb) / (GRAITO + 1) + lb; // 次の内分点（左）を計算する
            f1 = f(x1);
        } else {
            // 左側の区間を除外する
            lb = x1;
            x1 = x2; // 内分点（右）を次の内分点（左）に採用する
            f1 = f2;
            x2 = (ub - lb) / GRAITO + lb; // 次の内分点（右）を計算する
            f2 = f(x2);
        }
    }
    return (lb + ub) / 2;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

