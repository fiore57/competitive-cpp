template <typename T>
vector<T> bellman_ford(const Edges<T> &edges, int n, int s) {
    constexpr auto INF = numeric_limits<T>::max();
    vector<T> dist(n, INF);
    dist[s] = 0;
    rep(i, n - 1) {
        for (const auto &e : edges) {
            if (dist[e.from] == INF)
                continue;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
        }
    }

    for (const auto &e : edges) {
        if (dist[e.from] == INF)
            continue;
        if (dist[e.from] + e.cost < dist[e.to])
            return vector<T>();
    }
    return dist;
}