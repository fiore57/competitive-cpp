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