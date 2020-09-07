#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_B"
#include "../graph/dijkstra.cpp"
#include "../graph/graph-template.cpp"
#include "../template/template.cpp"

void Main() {
    int N = in();

    Graph<int> graph(N);
    rep(i, N) {
        int u = in(), k = in();
        rep(j, k) {
            int v = in(), c = in();
            graph.add_directed_edge(u, v, c);
        }
    }

    auto v = dijkstra(graph, 0).dist;
    rep(i, N) cout << i << " " << v[i] << endl;
}
