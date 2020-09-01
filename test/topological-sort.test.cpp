#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"
// clang-format off
#include "../_template/_template.cpp"
#include "../graph/_graph-template.cpp"
#include "../graph/topological-sort.cpp"
// clang-format on

void Main() {
    int V = in(), E = in();

    UnWeightedGraph G(V);

    rep(i, E) {
        int s = in(), t = in();
        G[s].push_back(t);
    }

    for (auto v : topologicalSort(G))
        out(v);
}