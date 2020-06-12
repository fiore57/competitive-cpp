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


# :x: 強連結成分分解 <small>(graph/scc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/scc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-13 03:18:43+09:00




## Verified with

* :x: <a href="../../verify/test/scc.test.cpp.html">test/scc.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief 強連結成分分解
 */
using UnWeightedGraph = vector<vector<int>>;
template <typename G>
class StronglyConnectedComponents {
    const G &g;
    UnWeightedGraph gg, rg;
    vector<int> comp, order, used;

public:
    StronglyConnectedComponents(G &g)
        : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1),
          used(g.size(), false) {
        rep(i, g.size()) {
            for (const auto e : g[i]) {
                gg[i].push_back(e);
                rg[e].push_back(i);
            }
        }
    }

    int operator[](const int k) const { return comp[k]; }

    void dfs(const int idx) {
        if (used[idx])
            return;
        used[idx] = true;
        for (const auto to : gg[idx])
            dfs(to);
        order.push_back(idx);
    }

    void rdfs(const int idx, const int cnt) {
        if (comp[idx] != -1)
            return;
        comp[idx] = cnt;
        for (const auto to : rg[idx])
            rdfs(to, cnt);
    }

    void build(UnWeightedGraph &t) {
        rep(i, gg.size()) dfs(i);
        reverse(ALL(order));
        int ptr = 0;
        for (const auto i : order) {
            if (comp[i] == -1) {
                rdfs(i, ptr);
                ++ptr;
            }
        }

        t.resize(ptr);
        rep(i, g.size()) {
            for (const auto to : g[i]) {
                int x = comp[i], y = comp[to];
                if (x == y)
                    continue;
                t[x].push_back(y);
            }
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/scc.cpp"
/**
 * @brief 強連結成分分解
 */
using UnWeightedGraph = vector<vector<int>>;
template <typename G>
class StronglyConnectedComponents {
    const G &g;
    UnWeightedGraph gg, rg;
    vector<int> comp, order, used;

public:
    StronglyConnectedComponents(G &g)
        : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1),
          used(g.size(), false) {
        rep(i, g.size()) {
            for (const auto e : g[i]) {
                gg[i].push_back(e);
                rg[e].push_back(i);
            }
        }
    }

    int operator[](const int k) const { return comp[k]; }

    void dfs(const int idx) {
        if (used[idx])
            return;
        used[idx] = true;
        for (const auto to : gg[idx])
            dfs(to);
        order.push_back(idx);
    }

    void rdfs(const int idx, const int cnt) {
        if (comp[idx] != -1)
            return;
        comp[idx] = cnt;
        for (const auto to : rg[idx])
            rdfs(to, cnt);
    }

    void build(UnWeightedGraph &t) {
        rep(i, gg.size()) dfs(i);
        reverse(ALL(order));
        int ptr = 0;
        for (const auto i : order) {
            if (comp[i] == -1) {
                rdfs(i, ptr);
                ++ptr;
            }
        }

        t.resize(ptr);
        rep(i, g.size()) {
            for (const auto to : g[i]) {
                int x = comp[i], y = comp[to];
                if (x == y)
                    continue;
                t[x].push_back(y);
            }
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

