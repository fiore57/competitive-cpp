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


# :warning: math/modint.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/modint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 22:27:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
constexpr int mod = 1'000'000'007;
// constexpr int mod = 998'244'353;
class mint {
private:
    std::int64_t m_x;

public:
    mint(const std::int64_t m_x = 0) : m_x((m_x % mod + mod) % mod) {}
    std::int64_t get() const { return m_x; }
    mint operator-() const { return mint(-m_x); }
    bool operator==(const mint a) const { return m_x == a.get(); }
    bool operator!=(const mint a) const { return !(*this == a); }
    mint &operator+=(const mint a) {
        if ((m_x += a.m_x) >= mod)
            m_x -= mod;
        return *this;
    }
    mint &operator-=(const mint a) {
        if ((m_x += mod - a.m_x) >= mod)
            m_x -= mod;
        return *this;
    }
    mint &operator*=(const mint a) {
        (m_x *= a.m_x) %= mod;
        return *this;
    }
    mint &operator++() { return *this += 1; }
    mint operator++(int) {
        mint tmp = *this;
        ++*this;
        return tmp;
    }
    mint operator--() { return *this -= 1; }
    mint operator--(int) {
        mint tmp = *this;
        --*this;
        return tmp;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(const std::int64_t t) const {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint &operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};
istream &operator>>(istream &is, mint &a) {
    ll x;
    is >> x;
    a = x;
    return is;
}
ostream &operator<<(ostream &os, const mint &a) {
    os << a.get();
    return os;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/modint.cpp"
constexpr int mod = 1'000'000'007;
// constexpr int mod = 998'244'353;
class mint {
private:
    std::int64_t m_x;

public:
    mint(const std::int64_t m_x = 0) : m_x((m_x % mod + mod) % mod) {}
    std::int64_t get() const { return m_x; }
    mint operator-() const { return mint(-m_x); }
    bool operator==(const mint a) const { return m_x == a.get(); }
    bool operator!=(const mint a) const { return !(*this == a); }
    mint &operator+=(const mint a) {
        if ((m_x += a.m_x) >= mod)
            m_x -= mod;
        return *this;
    }
    mint &operator-=(const mint a) {
        if ((m_x += mod - a.m_x) >= mod)
            m_x -= mod;
        return *this;
    }
    mint &operator*=(const mint a) {
        (m_x *= a.m_x) %= mod;
        return *this;
    }
    mint &operator++() { return *this += 1; }
    mint operator++(int) {
        mint tmp = *this;
        ++*this;
        return tmp;
    }
    mint operator--() { return *this -= 1; }
    mint operator--(int) {
        mint tmp = *this;
        --*this;
        return tmp;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(const std::int64_t t) const {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint &operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};
istream &operator>>(istream &is, mint &a) {
    ll x;
    is >> x;
    a = x;
    return is;
}
ostream &operator<<(ostream &os, const mint &a) {
    os << a.get();
    return os;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

