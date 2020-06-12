#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"
#include "../graph/scc.cpp"
#include "../template/template.cpp"

void Main() {
    int V = in(), E = in();

    UnWeightedGraph g(V);
    rep(i, E) {
        int s = in(), t = in();
        g[s].push_back(t);
    }

    StronglyConnectedComponents<UnWeightedGraph> scc(g);
    UnWeightedGraph t;
    scc.build(t);

    int Q = in();
    while (Q--) {
        int u = in(), v = in();
        out(scc[u] == scc[v]);
    }
}