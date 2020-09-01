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


# :heavy_check_mark: graph/topological-sort.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/topological-sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-01 17:20:31+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/topological-sort.test.cpp.html">test/topological-sort.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<int> topologicalSort(const UnWeightedGraph &g) {
    const size_t n = g.size();
    vector<int> ans, seen(n);
    auto dfs = [&g, &seen, &ans](auto &&f, int v) {
        if (seen[v])
            return;
        seen[v] = true;
        for (auto nv : g[v])
            f(f, nv);
        ans.push_back(v);
    };
    for (size_t i = 0; i < n; ++i)
        dfs(dfs, i);
    if (ans.size() != n)
        return vector<int>();
    reverse(ans.begin(), ans.end());
    return ans;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/topological-sort.cpp"
vector<int> topologicalSort(const UnWeightedGraph &g) {
    const size_t n = g.size();
    vector<int> ans, seen(n);
    auto dfs = [&g, &seen, &ans](auto &&f, int v) {
        if (seen[v])
            return;
        seen[v] = true;
        for (auto nv : g[v])
            f(f, nv);
        ans.push_back(v);
    };
    for (size_t i = 0; i < n; ++i)
        dfs(dfs, i);
    if (ans.size() != n)
        return vector<int>();
    reverse(ans.begin(), ans.end());
    return ans;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

