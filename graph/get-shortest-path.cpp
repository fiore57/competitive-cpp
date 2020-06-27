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