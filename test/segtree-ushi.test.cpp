#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"
// clang-format off
#include "../template/template.cpp"
#include "../structure/segtree-ushi.cpp"
// clang-format on

void Main() {
    int n = in(), q = in();
    auto f = [](int a, int b) { return min(a, b); };
    int ti = (1ll << 31) - 1;
    SegmentTree<int> seg(n, f, ti);
    while (q--) {
        int com = in(), x = in(), y = in();
        if (com == 0)
            seg.set_val(x, y);
        else
            cout << seg.query(x, y + 1) << '\n';
    }
}