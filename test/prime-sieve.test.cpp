#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"
// clang-format off
#include "../_template/_template.cpp"
#include "../math/prime-sieve.cpp"
// clang-format on

void Main() {
    int n = in();
    primeSieve ps(n);
    cout << n << ": ";
    out(ps.factorList(n));
}