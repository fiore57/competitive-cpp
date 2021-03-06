#define PROBLEM                                                                \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"
#define ERROR "1e-8"
// clang-format off
#include "../template/template.cpp"
#include "../others/geometry.cpp"
// clang-format on

void Main() {
    int xp1 = in(), yp1 = in();
    int xp2 = in(), yp2 = in();
    int q = in();

    Point p1(xp1, yp1), p2(xp2, yp2);
    Line l(p1, p2);

    while (q--) {
        int x = in(), y = in();
        Point p(x, y);
        Point r = reflection(p, l);
        out(r.x, r.y);
    }
}
