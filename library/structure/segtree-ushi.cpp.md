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


# :heavy_check_mark: structure/segtree-ushi.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/segtree-ushi.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 14:59:26+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/segtree-ushi.test.cpp.html">test/segtree-ushi.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/segtree-ushi.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

