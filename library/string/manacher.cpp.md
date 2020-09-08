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


# :warning: string/manacher.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/manacher.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 14:42:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
string addDummy(const string &s) {
    string ret(s.size() * 2 + 1, '-');
    rep(i, s.size()) ret[i * 2 + 1] = s[i];
    return ret;
}
vint manacher(const string &s) {
    int n = s.size();
    vint ret(n);
    int i = 0, j = 0;
    while (i < n) {
        while (i - j >= 0 && i + j < n && s[i - j] == s[i + j])
            ++j;
        ret[i] = j;
        int k = 1;
        while (i - k >= 0 && i + k < n && k + ret[i - k] < j)
            ret[i + k] = ret[i - k], ++k;
        i += k;
        j -= k;
    }
    return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/manacher.cpp"
string addDummy(const string &s) {
    string ret(s.size() * 2 + 1, '-');
    rep(i, s.size()) ret[i * 2 + 1] = s[i];
    return ret;
}
vint manacher(const string &s) {
    int n = s.size();
    vint ret(n);
    int i = 0, j = 0;
    while (i < n) {
        while (i - j >= 0 && i + j < n && s[i - j] == s[i + j])
            ++j;
        ret[i] = j;
        int k = 1;
        while (i - k >= 0 && i + k < n && k + ret[i - k] < j)
            ret[i + k] = ret[i - k], ++k;
        i += k;
        j -= k;
    }
    return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

