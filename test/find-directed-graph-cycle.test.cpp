#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A"
// clang-format off
#include "../template/template.cpp"
#include "../graph/graph-template.cpp"
#include "../graph/get-shortest-path.cpp"
#include "../graph/find-directed-graph-cycle.cpp"
// clang-format on

void Main() {
    int V = in(), E = in();

    UnWeightedGraph G(V);

    rep(i, E) {
        int s = in(), t = in();
        G[s].push_back(t);
    }

    out(!findDirectedGraphCycle(G).empty());
}