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


# :warning: math/combination.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/combination.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 22:27:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// require modint
struct combination {
    vector<mint> fact, ifact;
    combination(const int n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i)
            ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(const int n, const int k) {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
} comb(100005);

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/combination.cpp"
// require modint
struct combination {
    vector<mint> fact, ifact;
    combination(const int n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i)
            ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(const int n, const int k) {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
} comb(100005);

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

