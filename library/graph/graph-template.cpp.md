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


# :question: graph/graph-template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph-template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 14:40:07+09:00




## Verified with

* :x: <a href="../../verify/test/bellman-ford.test.cpp.html">test/bellman-ford.test.cpp</a>
* :x: <a href="../../verify/test/dijkstra.test.cpp.html">test/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/find-directed-graph-cycle.test.cpp.html">test/find-directed-graph-cycle.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/topological-sort.test.cpp.html">test/topological-sort.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T = int>
struct Edge {
    int from, to;
    T cost;
    int idx;
    Edge() = default;
    Edge(const int from, const int to, const T cost = 1, const int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
};
template <typename T = int>
using Edges = vector<Edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;

template <typename T = int>
struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(const int n) : g(n), es(0){};

    size_t size() const { return g.size(); }

    void add_directed_edge(const int from, const int to, const T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }
    void add_edge(const int from, const int to, const T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/graph-template.cpp"
template <typename T = int>
struct Edge {
    int from, to;
    T cost;
    int idx;
    Edge() = default;
    Edge(const int from, const int to, const T cost = 1, const int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
};
template <typename T = int>
using Edges = vector<Edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;

template <typename T = int>
struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(const int n) : g(n), es(0){};

    size_t size() const { return g.size(); }

    void add_directed_edge(const int from, const int to, const T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }
    void add_edge(const int from, const int to, const T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

