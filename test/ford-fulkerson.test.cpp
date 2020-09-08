#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"
// clang-format off
#include "../template/template.cpp"
#include "../graph/ford-fulkerson.cpp"
// clang-format on

void Main() {
    int V = in(), E = in();
    FordFulkerson<int> g(V);
    rep(i, E) {
        int u = in(), v = in(), c = in();
        g.add_edge(u, v, c);
    }
    out(g.max_flow(0, V - 1));
}