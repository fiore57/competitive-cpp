/**
 * @brief UnionFind
 */
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