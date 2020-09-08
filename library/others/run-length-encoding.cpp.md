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


# :warning: others/run-length-encoding.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e2bab0ecb94c4ea40777733195abe1b">others</a>
* <a href="{{ site.github.repository_url }}/blob/master/others/run-length-encoding.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 14:50:50+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T>
vector<pair<T, ll>> rle(const vector<T> &v) {
    vector<pair<T, ll>> ret;
    ret.reserve(v.size() / 2);
    for (const auto &x : v) {
        if (ret.empty() || ret.back().first != x) {
            ret.emplace_back(x, 1);
        } else {
            ++ret.back().second;
        }
    }
    return ret;
}
vector<pair<char, ll>> rle(const string &s) {
    vector<pair<char, ll>> ret;
    ret.reserve(s.size() / 2);
    for (const auto &c : s) {
        if (ret.empty() || ret.back().first != c) {
            ret.emplace_back(c, 1);
        } else {
            ++ret.back().second;
        }
    }
    return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "others/run-length-encoding.cpp"
template <typename T>
vector<pair<T, ll>> rle(const vector<T> &v) {
    vector<pair<T, ll>> ret;
    ret.reserve(v.size() / 2);
    for (const auto &x : v) {
        if (ret.empty() || ret.back().first != x) {
            ret.emplace_back(x, 1);
        } else {
            ++ret.back().second;
        }
    }
    return ret;
}
vector<pair<char, ll>> rle(const string &s) {
    vector<pair<char, ll>> ret;
    ret.reserve(s.size() / 2);
    for (const auto &c : s) {
        if (ret.empty() || ret.back().first != c) {
            ret.emplace_back(c, 1);
        } else {
            ++ret.back().second;
        }
    }
    return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

