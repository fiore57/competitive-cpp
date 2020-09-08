template <typename flow_t>
class FordFulkerson {
    struct edge {
        edge(const int to, const flow_t cap, const int rev, const bool is_rev,
             const int idx)
            : to(to), cap(cap), rev(rev), is_rev(is_rev), idx(idx) {}
        int to;
        flow_t cap;
        int rev;
        bool is_rev;
        int idx;
    };

public:
    vector<vector<edge>> graph;

private:
    vector<int> used;
    const flow_t INF;
    int timestamp;

public:
    explicit FordFulkerson(const int n)
        : graph(n), used(n, -1), INF(numeric_limits<flow_t>::max()),
          timestamp(0) {}

    void add_edge(const int from, const int to, const flow_t cap,
                  const int idx = -1) {
        graph[from].emplace_back(to, cap, (int)graph[to].size(), false, idx);
        graph[to].emplace_back(from, 0, (int)graph[from].size() - 1, true, idx);
    }

    flow_t dfs(const int idx, const int t, const flow_t flow) {
        if (idx == t)
            return flow;
        used[idx] = timestamp;
        for (auto &&e : graph[idx]) {
            if (e.cap > 0 && used[e.to] != timestamp) {
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(const int s, const int t) {
        flow_t flow = 0;
        for (flow_t f; (f = dfs(s, t, INF)) > 0; timestamp++) {
            flow += f;
        }
        return flow;
    }
};
template <typename T>
ostream &operator<<(ostream &os, const FordFulkerson<T> &f) {
    os << "\n=== vvv ===\n";
    for (size_t i = 0; i < f.graph.size(); ++i) {
        for (const auto &e : f.graph[i]) {
            if (e.is_rev)
                continue;
            auto &&rev_e = f.graph[e.to][e.rev];
            os << i << "->" << e.to << " (flow: " << rev_e.cap << "/"
               << e.cap + rev_e.cap << ")" << '\n';
        }
    }
    os << "=== ^^^ ===";
    return os;
}