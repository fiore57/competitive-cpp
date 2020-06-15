#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"
#include "../_template/_template.cpp"
#include "../graph/_graph-template.cpp"
#include "../graph/bellman-ford.cpp"

void Main() {
    int V = in(), E = in(), r = in();

    Edges<int> edges;
    rep(i, E) {
        int s = in(), t = in(), d = in();
        edges.emplace_back(s, t, d);
    }
    auto v = bellman_ford(edges, V, r);
    if (v.empty()) {
        out("NEGATIVE CYCLE");
        return;
    }

    for (const auto e : v) {
        if (e == numeric_limits<int>::max())
            out("INF");
        else
            out(e);
    }
}