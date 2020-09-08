template <typename G>
class DoublingLowestCommonAncestor {
    const G &g;
    vector<int> depth;
    const int LOG;
    vector<vector<int>> table;

public:
    DoublingLowestCommonAncestor(const G &g)
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