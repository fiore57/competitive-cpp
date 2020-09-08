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


# :heavy_check_mark: structure/segtree-dual.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/segtree-dual.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 14:59:26+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/segtree-dual.test.cpp.html">test/segtree-dual.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/segtree-dual.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

