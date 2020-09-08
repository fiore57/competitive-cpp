#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"
// clang-format off
#include "../template/template.cpp"
#include "../structure/segtree-lazy.cpp"
// clang-format on

void Main() {
    int n = in(), q = in();
    int ti = (1ll << 31) - 1;
    int ei = ti;
    auto f = [](int a, int b) { return min(a, b); };
    auto g = [ei](int a, int b) { return b == ei ? a : b; };
    auto h = [ei](int a, int b) { return b == ei ? a : b; };
    SegmentTree<int, int> seg(n, f, g, h, ti, ei);
    while (q--) {
        int com = in(), s = in(), t = in();
        if (com == 0) {
            int x = in();
            seg.update(s, t + 1, x);
        } else
            cout << seg.query(s, t + 1) << '\n';
    }
}