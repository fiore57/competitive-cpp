#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"
// clang-format off
#include "../template/template.cpp"
#include "../structure/segtree-dual.cpp"
// clang-format on

void Main() {
    int n = in(), q = in();
    int ei = (1ll << 31) - 1;
    auto h = [ei](int a, int b) { return b == ei ? a : b; };
    SegmentTree<int> seg(n, h, ei);
    while (q--) {
        int com = in();
        if (com == 0) {
            int s = in(), t = in(), x = in();
            seg.update(s, t + 1, x);
        } else {
            int i = in();
            cout << seg.get_val(i) << '\n';
        }
    }
}