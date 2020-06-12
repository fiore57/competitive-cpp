#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
#include "../library/_template.cpp"
#include "../library/union-find.cpp"

void Main()
{
    int n = in(), q = in();
    UnionFind uf(n);
    rep(i, q)
    {
        int com = in(), x = in(), y = in();
        if (com == 0)
            uf.unite(x, y);
        else
            cout << uf.same(x, y) << endl;
    }
}