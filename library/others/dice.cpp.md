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


# :warning: others/dice.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e2bab0ecb94c4ea40777733195abe1b">others</a>
* <a href="{{ site.github.repository_url }}/blob/master/others/dice.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-16 02:38:04+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class Dice {
    int l, r, f, b, d, u;

public:
    Dice(const int l, const int r, const int f, const int b, const int d,
         const int u)
        : l(l), r(r), f(f), b(b), d(d), u(u) {}
    void roll_x() { cyclic_shift(d, f, u, b); }
    void roll_x_() { cyclic_shift(d, b, u, f); }
    void roll_y() { cyclic_shift(f, l, b, r); }
    void roll_y_() { cyclic_shift(f, r, b, l); }
    void roll_z() { cyclic_shift(d, l, u, r); }
    void roll_z_() { cyclic_shift(d, r, u, l); }
    bool operator==(const Dice &rhs) const {
        return l == rhs.l && r == rhs.r && f == rhs.f && b == rhs.b &&
               d == rhs.d && u == rhs.u;
    }

    vector<Dice> all_rolls() {
        vector<Dice> ret;
        rep(i, 6) {
            rep(j, 4) {
                ret.push_back(*this);
                roll_z();
            }
            if (i % 2 == 0)
                roll_x();
            else
                roll_y();
        }
        return ret;
    }
    bool equivalent_to(const Dice &rhs) {
        for (const auto &lhs : all_rolls()) {
            if (lhs == rhs)
                return true;
        }
        return false;
    }

private:
    void cyclic_shift(int &a, int &b, int &c, int &d) {
        int e = a;
        a = b, b = c, c = d, d = e;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "others/dice.cpp"
class Dice {
    int l, r, f, b, d, u;

public:
    Dice(const int l, const int r, const int f, const int b, const int d,
         const int u)
        : l(l), r(r), f(f), b(b), d(d), u(u) {}
    void roll_x() { cyclic_shift(d, f, u, b); }
    void roll_x_() { cyclic_shift(d, b, u, f); }
    void roll_y() { cyclic_shift(f, l, b, r); }
    void roll_y_() { cyclic_shift(f, r, b, l); }
    void roll_z() { cyclic_shift(d, l, u, r); }
    void roll_z_() { cyclic_shift(d, r, u, l); }
    bool operator==(const Dice &rhs) const {
        return l == rhs.l && r == rhs.r && f == rhs.f && b == rhs.b &&
               d == rhs.d && u == rhs.u;
    }

    vector<Dice> all_rolls() {
        vector<Dice> ret;
        rep(i, 6) {
            rep(j, 4) {
                ret.push_back(*this);
                roll_z();
            }
            if (i % 2 == 0)
                roll_x();
            else
                roll_y();
        }
        return ret;
    }
    bool equivalent_to(const Dice &rhs) {
        for (const auto &lhs : all_rolls()) {
            if (lhs == rhs)
                return true;
        }
        return false;
    }

private:
    void cyclic_shift(int &a, int &b, int &c, int &d) {
        int e = a;
        a = b, b = c, c = d, d = e;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

