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


# :heavy_check_mark: graph/dijkstra.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 22:07:58+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/dijkstra.test.cpp.html">test/dijkstra.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T> struct ShortestPath {
    vector<T> dist;
    vector<int> from, id;
};

template <typename T> ShortestPath<T> dijkstra(const Graph<T> &g, const int s) {
    constexpr auto INF = numeric_limits<T>::max();
    using Pi = pair<T, int>;

    vector<int> from(g.size(), -1), id(g.size(), -1);
    vector<T> dist(g.size(), INF);
    priority_queue<Pi, vector<Pi>, greater<>> que;

    dist[s] = 0;
    que.emplace(dist[s], s);

    while (!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();

        if (dist[idx] < cost)
            continue;

        for (const auto &e : g.g[idx]) {
            auto next_cost = cost + e.cost;
            if (dist[e.to] <= next_cost)
                continue;
            dist[e.to] = next_cost;
            from[e.to] = idx;
            id[e.to] = e.idx;
            que.emplace(dist[e.to], e.to);
        }
    }

    return {dist, from, id};
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/dijkstra.cpp"
template <typename T> struct ShortestPath {
    vector<T> dist;
    vector<int> from, id;
};

template <typename T> ShortestPath<T> dijkstra(const Graph<T> &g, const int s) {
    constexpr auto INF = numeric_limits<T>::max();
    using Pi = pair<T, int>;

    vector<int> from(g.size(), -1), id(g.size(), -1);
    vector<T> dist(g.size(), INF);
    priority_queue<Pi, vector<Pi>, greater<>> que;

    dist[s] = 0;
    que.emplace(dist[s], s);

    while (!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();

        if (dist[idx] < cost)
            continue;

        for (const auto &e : g.g[idx]) {
            auto next_cost = cost + e.cost;
            if (dist[e.to] <= next_cost)
                continue;
            dist[e.to] = next_cost;
            from[e.to] = idx;
            id[e.to] = e.idx;
            que.emplace(dist[e.to], e.to);
        }
    }

    return {dist, from, id};
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

