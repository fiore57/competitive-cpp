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