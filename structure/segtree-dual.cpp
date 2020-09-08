template <typename E>
class SegmentTree {
    using H = function<E(E, E)>;
    int n, height;
    const H h;
    const E ei;
    vector<E> laz;

public:
    SegmentTree(const int n_, const H h, const E ei) : h(h), ei(ei) {
        init(n_);
    }

private:
    void init(const int n_) {
        n = 1;
        height = 0;
        while (n < n_)
            n <<= 1, height++;
        laz.assign(2 * n, ei);
    }

    inline void propagate(const int k) {
        if (laz[k] == ei)
            return;
        laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
        laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
        laz[k] = ei;
    }

    inline void thrust(const int k) {
        for (int i = height; i; i--)
            propagate(k >> i);
    }

public:
    void update(int a, int b, const E x) {
        if (a >= b)
            return;
        thrust(a += n);
        thrust(b += n - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                laz[l] = h(laz[l], x), l++;
            if (r & 1)
                --r, laz[r] = h(laz[r], x);
        }
    }

    E get_val(int a) {
        thrust(a += n);
        return laz[a];
    }

    void set_val(int a, const E x) {
        thrust(a += n);
        laz[a] = x;
    }
};