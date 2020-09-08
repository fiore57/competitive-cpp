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


# :heavy_check_mark: graph/lca-doubling.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/lca-doubling.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 14:39:41+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/lca-doubling.test.cpp.html">test/lca-doubling.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename G>
class DoublingLowestCommonAncestor {
    const G &g;
    vector<int> depth;
    const int LOG;
    vector<vector<int>> table;

public:
    explicit DoublingLowestCommonAncestor(const G &g)
        : g(g), depth(g.size()), LOG(32 - __builtin_clz(g.size())) {
        table.assign(LOG, vector<int>(g.size(), -1));
        build();
    }

    int query(int u, int v) const {
        if (depth[u] > depth[v])
            swap(u, v);

        for (int i = LOG - 1; i >= 0; --i) {
            if (((depth[v] - depth[u]) >> i) & 1)
                v = table[i][v];
        }
        if (u == v)
            return u;
        for (int i = LOG - 1; i >= 0; --i) {
            if (table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }

    int get_dist(const int u, const int v) const {
        return depth[u] + depth[v] - 2 * depth[query(u, v)];
    }

    bool is_on_path(const int u, const int v, const int a) const {
        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);
    }

private:
    void build() {
        dfs(0, -1, 0);
        for (int k = 0; k + 1 < LOG; k++) {
            const int sz = table[k].size();
            for (int i = 0; i < sz; ++i) {
                if (table[k][i] == -1)
                    table[k + 1][i] = -1;
                else
                    table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    void dfs(const int idx, const int par, const int d) {
        table[0][idx] = par;
        depth[idx] = d;
        for (const auto &to : g[idx]) {
            if (to != par)
                dfs(to, idx, d + 1);
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/lca-doubling.cpp"
template <typename G>
class DoublingLowestCommonAncestor {
    const G &g;
    vector<int> depth;
    const int LOG;
    vector<vector<int>> table;

public:
    explicit DoublingLowestCommonAncestor(const G &g)
        : g(g), depth(g.size()), LOG(32 - __builtin_clz(g.size())) {
        table.assign(LOG, vector<int>(g.size(), -1));
        build();
    }

    int query(int u, int v) const {
        if (depth[u] > depth[v])
            swap(u, v);

        for (int i = LOG - 1; i >= 0; --i) {
            if (((depth[v] - depth[u]) >> i) & 1)
                v = table[i][v];
        }
        if (u == v)
            return u;
        for (int i = LOG - 1; i >= 0; --i) {
            if (table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }

    int get_dist(const int u, const int v) const {
        return depth[u] + depth[v] - 2 * depth[query(u, v)];
    }

    bool is_on_path(const int u, const int v, const int a) const {
        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);
    }

private:
    void build() {
        dfs(0, -1, 0);
        for (int k = 0; k + 1 < LOG; k++) {
            const int sz = table[k].size();
            for (int i = 0; i < sz; ++i) {
                if (table[k][i] == -1)
                    table[k + 1][i] = -1;
                else
                    table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    void dfs(const int idx, const int par, const int d) {
        table[0][idx] = par;
        depth[idx] = d;
        for (const auto &to : g[idx]) {
            if (to != par)
                dfs(to, idx, d + 1);
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

