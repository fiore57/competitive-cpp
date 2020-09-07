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


# :x: graph/bellman-ford.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/bellman-ford.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-15 15:40:57+09:00




## Verified with

* :x: <a href="../../verify/test/bellman-ford.test.cpp.html">test/bellman-ford.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T>
vector<T> bellman_ford(const Edges<T> &edges, int n, int s) {
    constexpr auto INF = numeric_limits<T>::max();
    vector<T> dist(n, INF);
    dist[s] = 0;
    rep(i, n - 1) {
        for (const auto &e : edges) {
            if (dist[e.from] == INF)
                continue;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
        }
    }

    for (const auto &e : edges) {
        if (dist[e.from] == INF)
            continue;
        if (dist[e.from] + e.cost < dist[e.to])
            return vector<T>();
    }
    return dist;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/bellman-ford.cpp"
template <typename T>
vector<T> bellman_ford(const Edges<T> &edges, int n, int s) {
    constexpr auto INF = numeric_limits<T>::max();
    vector<T> dist(n, INF);
    dist[s] = 0;
    rep(i, n - 1) {
        for (const auto &e : edges) {
            if (dist[e.from] == INF)
                continue;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
        }
    }

    for (const auto &e : edges) {
        if (dist[e.from] == INF)
            continue;
        if (dist[e.from] + e.cost < dist[e.to])
            return vector<T>();
    }
    return dist;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

