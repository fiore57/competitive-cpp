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