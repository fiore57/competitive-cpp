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


# :heavy_check_mark: graph/get-shortest-path.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/get-shortest-path.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-27 19:09:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/find-directed-graph-cycle.test.cpp.html">test/find-directed-graph-cycle.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<int> getShortestPath(const UnWeightedGraph &g, const int s,
                            const int t) {
    vector<int> dist(g.size(), INF), prev(g.size(), -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        const int v = q.front();
        q.pop();
        for (const auto nv : g[v]) {
            if (dist[nv] != INF)
                continue;
            prev[nv] = v;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    if (dist[t] == INF)
        return vector<int>();
    vector<int> shortestPath;
    for (int v = t;; v = prev[v]) {
        shortestPath.push_back(v);
        if (v == s)
            break;
    }
    reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/get-shortest-path.cpp"
vector<int> getShortestPath(const UnWeightedGraph &g, const int s,
                            const int t) {
    vector<int> dist(g.size(), INF), prev(g.size(), -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        const int v = q.front();
        q.pop();
        for (const auto nv : g[v]) {
            if (dist[nv] != INF)
                continue;
            prev[nv] = v;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    if (dist[t] == INF)
        return vector<int>();
    vector<int> shortestPath;
    for (int v = t;; v = prev[v]) {
        shortestPath.push_back(v);
        if (v == s)
            break;
    }
    reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

