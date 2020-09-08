---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: structure/segtree-lazy.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/segtree-lazy.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 14:59:26+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/segtree-lazy.test.cpp.html">test/segtree-lazy.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T, typename E>
class SegmentTree {
    using F = function<T(T, T)>;
    using G = function<T(T, E)>;
    using H = function<E(E, E)>;
    int n, height;
    const F f;
    const G g;
    const H h;
    const T ti;
    const E ei;
    vector<T> dat;
    vector<E> laz;

public:
    SegmentTree(const int n_, const F f, const G g, const H h, const T ti,
                const E ei, const vector<T> &v = vector<T>())
        : f(f), g(g), h(h), ti(ti), ei(ei) {
        init(n_);
        if (n_ == (int)v.size())
            build(n_, v);
    }

private:
    void init(const int n_) {
        n = 1;
        height = 0;
        while (n < n_)
            n <<= 1, height++;
        dat.assign(2 * n, ti);
        laz.assign(2 * n, ei);
    }

    void build(const int n_, const vector<T> &v) {
        for (int i = 0; i < n_; i++)
            dat[n + i] = v[i];
        for (int i = n - 1; i; i--)
            dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }

    inline T reflect(const int k) {
        return laz[k] == ei ? dat[k] : g(dat[k], laz[k]);
    }

    inline void propagate(const int k) {
        if (laz[k] == ei)
            return;
        laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
        laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
        dat[k] = reflect(k);
        laz[k] = ei;
    }

    inline void thrust(const int k) {
        for (int i = height; i; i--)
            propagate(k >> i);
    }

    inline void recalc(int k) {
        while (k >>= 1)
            dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
    }

    template <typename C>
    int find(const int st, const C &check, T &acc, const int k, const int l,
             const int r) {
        if (l + 1 == r) {
            acc = f(acc, reflect(k));
            return check(acc) ? k - n : -1;
        }
        propagate(k);
        int m = (l + r) >> 1;
        if (m <= st)
            return find(st, check, acc, (k << 1) | 1, m, r);
        if (st <= l && !check(f(acc, dat[k]))) {
            acc = f(acc, dat[k]);
            return -1;
        }
        int vl = find(st, check, acc, (k << 1) | 0, l, m);
        if (~vl)
            return vl;
        return find(st, check, acc, (k << 1) | 1, m, r);
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
        recalc(a);
        recalc(b);
    }

    void set_val(int a, const T x) {
        thrust(a += n);
        dat[a] = x;
        laz[a] = ei;
        recalc(a);
    }

    T query(int a, int b) {
        if (a >= b)
            return ti;
        thrust(a += n);
        thrust(b += n - 1);
        T vl = ti, vr = ti;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                vl = f(vl, reflect(l++));
            if (r & 1)
                vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }

    template <typename C>
    int find(const int st, const C &check) {
        T acc = ti;
        return find(st, check, acc, 1, 0, n);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/segtree-lazy.cpp"
template <typename T, typename E>
class SegmentTree {
    using F = function<T(T, T)>;
    using G = function<T(T, E)>;
    using H = function<E(E, E)>;
    int n, height;
    const F f;
    const G g;
    const H h;
    const T ti;
    const E ei;
    vector<T> dat;
    vector<E> laz;

public:
    SegmentTree(const int n_, const F f, const G g, const H h, const T ti,
                const E ei, const vector<T> &v = vector<T>())
        : f(f), g(g), h(h), ti(ti), ei(ei) {
        init(n_);
        if (n_ == (int)v.size())
            build(n_, v);
    }

private:
    void init(const int n_) {
        n = 1;
        height = 0;
        while (n < n_)
            n <<= 1, height++;
        dat.assign(2 * n, ti);
        laz.assign(2 * n, ei);
    }

    void build(const int n_, const vector<T> &v) {
        for (int i = 0; i < n_; i++)
            dat[n + i] = v[i];
        for (int i = n - 1; i; i--)
            dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }

    inline T reflect(const int k) {
        return laz[k] == ei ? dat[k] : g(dat[k], laz[k]);
    }

    inline void propagate(const int k) {
        if (laz[k] == ei)
            return;
        laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
        laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
        dat[k] = reflect(k);
        laz[k] = ei;
    }

    inline void thrust(const int k) {
        for (int i = height; i; i--)
            propagate(k >> i);
    }

    inline void recalc(int k) {
        while (k >>= 1)
            dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
    }

    template <typename C>
    int find(const int st, const C &check, T &acc, const int k, const int l,
             const int r) {
        if (l + 1 == r) {
            acc = f(acc, reflect(k));
            return check(acc) ? k - n : -1;
        }
        propagate(k);
        int m = (l + r) >> 1;
        if (m <= st)
            return find(st, check, acc, (k << 1) | 1, m, r);
        if (st <= l && !check(f(acc, dat[k]))) {
            acc = f(acc, dat[k]);
            return -1;
        }
        int vl = find(st, check, acc, (k << 1) | 0, l, m);
        if (~vl)
            return vl;
        return find(st, check, acc, (k << 1) | 1, m, r);
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
        recalc(a);
        recalc(b);
    }

    void set_val(int a, const T x) {
        thrust(a += n);
        dat[a] = x;
        laz[a] = ei;
        recalc(a);
    }

    T query(int a, int b) {
        if (a >= b)
            return ti;
        thrust(a += n);
        thrust(b += n - 1);
        T vl = ti, vr = ti;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                vl = f(vl, reflect(l++));
            if (r & 1)
                vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }

    template <typename C>
    int find(const int st, const C &check) {
        T acc = ti;
        return find(st, check, acc, 1, 0, n);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

