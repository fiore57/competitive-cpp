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


# :warning: others/compress.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e2bab0ecb94c4ea40777733195abe1b">others</a>
* <a href="{{ site.github.repository_url }}/blob/master/others/compress.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 14:10:34+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T>
class Compress {
    vector<T> xs;

public:
    Compress() = default;
    explicit Compress(const vector<T> &vs) { add(vs); }
    explicit Compress(const initializer_list<vector<T>> &vs) {
        for (const auto &p : vs)
            add(p);
    }

    void add(const vector<T> &vs) {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x) { xs.emplace_back(x); }

    void build() {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector<int> get(const vector<T> &vs) const {
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
            return lower_bound(begin(xs), end(xs), x) - begin(xs);
        });
        return ret;
    }

    int get(const T &x) const {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    const T &operator[](const int k) const { return xs[k]; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "others/compress.cpp"
template <typename T>
class Compress {
    vector<T> xs;

public:
    Compress() = default;
    explicit Compress(const vector<T> &vs) { add(vs); }
    explicit Compress(const initializer_list<vector<T>> &vs) {
        for (const auto &p : vs)
            add(p);
    }

    void add(const vector<T> &vs) {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x) { xs.emplace_back(x); }

    void build() {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector<int> get(const vector<T> &vs) const {
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
            return lower_bound(begin(xs), end(xs), x) - begin(xs);
        });
        return ret;
    }

    int get(const T &x) const {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    const T &operator[](const int k) const { return xs[k]; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

