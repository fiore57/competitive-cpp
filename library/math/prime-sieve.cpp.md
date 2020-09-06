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


# :x: math/prime-sieve.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime-sieve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 21:41:02+09:00




## Verified with

* :x: <a href="../../verify/test/prime-sieve.test.cpp.html">test/prime-sieve.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T>
vector<pair<T, ll>> rle(const vector<T> &v) {
    vector<pair<T, ll>> ret;
    ret.reserve(v.size() / 2);
    for (const auto x : v) {
        if (ret.empty() || ret.back().first != x) {
            ret.emplace_back(x, 1);
        } else {
            ++ret.back().second;
        }
    }
    return ret;
}
struct primeSieve {
    ll n;
    vector<ll> primeFactor;
    vector<ll> primes;

    primeSieve(const ll n = 1) : n(n), primeFactor(n + 1, 0) {
        primeFactor[0] = primeFactor[1] = -1;
        for (ll i = 2; i <= n; ++i) {
            if (primeFactor[i])
                continue;
            primes.push_back(i);
            primeFactor[i] = i;
            for (ll j = i * i; j <= n; j += i) {
                if (!primeFactor[j])
                    primeFactor[j] = i;
            }
        }
    }
    bool isPrime(const ll x) const { return primeFactor[x] == x; }
    vector<ll> factorList(ll x) const {
        vector<ll> res;
        while (x != 1) {
            res.push_back(primeFactor[x]);
            x /= primeFactor[x];
        }
        return res;
    }
    vector<pair<ll, ll>> factor(const ll x) const { return rle(factorList(x)); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/prime-sieve.cpp"
template <typename T>
vector<pair<T, ll>> rle(const vector<T> &v) {
    vector<pair<T, ll>> ret;
    ret.reserve(v.size() / 2);
    for (const auto x : v) {
        if (ret.empty() || ret.back().first != x) {
            ret.emplace_back(x, 1);
        } else {
            ++ret.back().second;
        }
    }
    return ret;
}
struct primeSieve {
    ll n;
    vector<ll> primeFactor;
    vector<ll> primes;

    primeSieve(const ll n = 1) : n(n), primeFactor(n + 1, 0) {
        primeFactor[0] = primeFactor[1] = -1;
        for (ll i = 2; i <= n; ++i) {
            if (primeFactor[i])
                continue;
            primes.push_back(i);
            primeFactor[i] = i;
            for (ll j = i * i; j <= n; j += i) {
                if (!primeFactor[j])
                    primeFactor[j] = i;
            }
        }
    }
    bool isPrime(const ll x) const { return primeFactor[x] == x; }
    vector<ll> factorList(ll x) const {
        vector<ll> res;
        while (x != 1) {
            res.push_back(primeFactor[x]);
            x /= primeFactor[x];
        }
        return res;
    }
    vector<pair<ll, ll>> factor(const ll x) const { return rle(factorList(x)); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

