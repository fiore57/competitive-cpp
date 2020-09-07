#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C"
// clang-format off
#include "../template/template.cpp"
#include "../math/gcdlcm.cpp"
// clang-format on

void Main() {
    int n = in();
    vector<int> a = in(n);
    ll l = a.front();
    for (const auto e : a) {
        l = lcm(l, e);
    }
    out(l);
}