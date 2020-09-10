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


# :warning: others/unique.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e2bab0ecb94c4ea40777733195abe1b">others</a>
* <a href="{{ site.github.repository_url }}/blob/master/others/unique.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 23:02:39+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename Container>
inline void UNIQUE(Container &&c) {
    c.erase(std::unique(begin(c), end(c)), end(c));
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "others/unique.cpp"
template <typename Container>
inline void UNIQUE(Container &&c) {
    c.erase(std::unique(begin(c), end(c)), end(c));
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
