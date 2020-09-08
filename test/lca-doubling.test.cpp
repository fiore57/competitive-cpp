#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"
// clang-format off
#include "../template/template.cpp"
#include "../graph/lca-doubling.cpp"
// clang-format on

void Main() {
    int n = in();
    vvint g(n);
    rep(i, n) {
        int k = in();
        rep(j, k) {
            int c = in();
            g[i].pb(c);
            g[c].pb(i);
        }
    }

    DoublingLowestCommonAncestor<vvint> lca(g);

    int q = in();
    while (q--) {
        int u = in(), v = in();
        out(lca.query(u, v));
    }
}