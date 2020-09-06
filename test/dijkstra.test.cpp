#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_B"
#include "../_template/_template.cpp"
#include "../graph/_graph-template.cpp"
#include "../graph/dijkstra.cpp"

void Main() {
    int N = in();

    Graph<int> graph(N);
    rep(i, N) {
        int u = in(), k = in();
        rep(j, k) {
            int v = in(), c = in();
            graph.add_edge(u, v, c);
        }
    }

    auto v = dijkstra(graph, 0).dist;
    rep(i, N) {
        cout << i << " " << v[i] << endl;
    }
}
