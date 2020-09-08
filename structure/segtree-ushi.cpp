template <typename T>
class SegmentTree {
    using F = function<T(T, T)>;
    int n;
    const F f;
    const T ti;
    vector<T> dat;

public:
    SegmentTree(const int n_, const F f, const T ti,
                const vector<T> &v = vector<T>())
        : f(f), ti(ti) {
        if (n_ == (int)v.size())
            build(n_, v);
        else
            init(n_);
    }

    // update k_th element to x
    void set_val(int k, const T x) {
        dat[k += n] = x;
        while (k >>= 1)
            dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
    }

    // execute a query against [a, b)
    T query(const int a, const int b) {
        if (a >= b)
            return ti;
        T vl = ti, vr = ti;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                vl = f(vl, dat[l++]);
            if (r & 1)
                vr = f(dat[--r], vr);
        }
        return f(vl, vr);
    }

    // get k_th element
    T operator[](const int k) const { return dat[k + n]; }

private:
    void init(const int n_) {
        n = 1;
        while (n < n_)
            n <<= 1;
        dat.assign(n << 1, ti);
    }

    void build(const int n_, const vector<T> &v) {
        init(n_);
        for (int i = 0; i < n_; i++)
            dat[n + i] = v[i];
        for (int i = n - 1; i; i--)
            dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }
};