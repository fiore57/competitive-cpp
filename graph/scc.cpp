using UnWeightedGraph = vector<vector<int>>;
template <typename G>
class StronglyConnectedComponents {
    const G &g;
    UnWeightedGraph gg, rg;
    vector<int> comp, order, used;

public:
    StronglyConnectedComponents(G &g)
        : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1),
          used(g.size(), false) {
        rep(i, g.size()) {
            for (const auto e : g[i]) {
                gg[i].push_back(e);
                rg[e].push_back(i);
            }
        }
    }

    int operator[](const int k) const { return comp[k]; }

    void dfs(const int idx) {
        if (used[idx])
            return;
        used[idx] = true;
        for (const auto to : gg[idx])
            dfs(to);
        order.push_back(idx);
    }

    void rdfs(const int idx, const int cnt) {
        if (comp[idx] != -1)
            return;
        comp[idx] = cnt;
        for (const auto to : rg[idx])
            rdfs(to, cnt);
    }

    void build(UnWeightedGraph &t) {
        rep(i, gg.size()) dfs(i);
        reverse(ALL(order));
        int ptr = 0;
        for (const auto i : order) {
            if (comp[i] == -1) {
                rdfs(i, ptr);
                ++ptr;
            }
        }

        t.resize(ptr);
        rep(i, g.size()) {
            for (const auto to : g[i]) {
                int x = comp[i], y = comp[to];
                if (x == y)
                    continue;
                t[x].push_back(y);
            }
        }
    }
};