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