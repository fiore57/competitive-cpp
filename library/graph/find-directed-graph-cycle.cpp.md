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


# :heavy_check_mark: graph/find-directed-graph-cycle.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/find-directed-graph-cycle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-27 19:09:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/find-directed-graph-cycle.test.cpp.html">test/find-directed-graph-cycle.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<int> findDirectedGraphCycle(const UnWeightedGraph &g) {
    const int n = g.size();
    vector<int> seen(n, 0), depth(n, -1);
    int cycle_s = -1, cycle_t = -1;
    auto dfs = [&g, &seen, &depth, &cycle_s, &cycle_t](auto &&self,
                                                       const int v) {
        seen[v] = 1;
        int max_depth_nv = -1;
        for (const auto nv : g[v]) {
            if (seen[nv] == 1) { // 後退辺が存在
                if (max_depth_nv == -1 || depth[max_depth_nv] < depth[nv]) {
                    max_depth_nv = nv;
                }
            }
        }
        if (max_depth_nv != -1) {
            cycle_s = max_depth_nv;
            cycle_t = v;
            return true;
        }
        for (const auto nv : g[v]) {
            if (seen[nv] != 0)
                continue;
            depth[nv] = depth[v] + 1;
            if (self(self, nv))
                return true;
        }
        seen[v] = 2;
        return false;
    };
    rep(s, n) {
        if (seen[s] != 0)
            continue;
        depth[s] = 0;
        if (dfs(dfs, s)) {
            return getShortestPath(g, cycle_s, cycle_t);
        }
    }
    return vint();
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/find-directed-graph-cycle.cpp"
vector<int> findDirectedGraphCycle(const UnWeightedGraph &g) {
    const int n = g.size();
    vector<int> seen(n, 0), depth(n, -1);
    int cycle_s = -1, cycle_t = -1;
    auto dfs = [&g, &seen, &depth, &cycle_s, &cycle_t](auto &&self,
                                                       const int v) {
        seen[v] = 1;
        int max_depth_nv = -1;
        for (const auto nv : g[v]) {
            if (seen[nv] == 1) { // 後退辺が存在
                if (max_depth_nv == -1 || depth[max_depth_nv] < depth[nv]) {
                    max_depth_nv = nv;
                }
            }
        }
        if (max_depth_nv != -1) {
            cycle_s = max_depth_nv;
            cycle_t = v;
            return true;
        }
        for (const auto nv : g[v]) {
            if (seen[nv] != 0)
                continue;
            depth[nv] = depth[v] + 1;
            if (self(self, nv))
                return true;
        }
        seen[v] = 2;
        return false;
    };
    rep(s, n) {
        if (seen[s] != 0)
            continue;
        depth[s] = 0;
        if (dfs(dfs, s)) {
            return getShortestPath(g, cycle_s, cycle_t);
        }
    }
    return vint();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

