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


# :heavy_check_mark: structure/union-find.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/union-find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-15 15:20:08+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/union-find.test.cpp.html">test/union-find.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class UnionFind {
public:
    UnionFind(const int n) : par(n), rank(n, 0), sz(n, 1) {
        rep(i, n) par[i] = i;
    }

    int find(const int x) {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (rank[x] < rank[y]) {
            par[x] = y;
            sz[y] += sz[x];
        } else {
            par[y] = x;
            sz[x] += sz[y];
            if (rank[x] == rank[y]) {
                ++rank[x];
            }
        }
    }

    bool same(const int x, const int y) { return find(x) == find(y); }

    int size(const int x) { return sz[find(x)]; }

private:
    vector<int> par, rank, sz;
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/union-find.cpp"
class UnionFind {
public:
    UnionFind(const int n) : par(n), rank(n, 0), sz(n, 1) {
        rep(i, n) par[i] = i;
    }

    int find(const int x) {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (rank[x] < rank[y]) {
            par[x] = y;
            sz[y] += sz[x];
        } else {
            par[y] = x;
            sz[x] += sz[y];
            if (rank[x] == rank[y]) {
                ++rank[x];
            }
        }
    }

    bool same(const int x, const int y) { return find(x) == find(y); }

    int size(const int x) { return sz[find(x)]; }

private:
    vector<int> par, rank, sz;
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

