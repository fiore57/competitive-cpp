template <typename T>
vector<pair<T, ll>> rle(const vector<T> &v) {
    vector<pair<T, ll>> ret;
    ret.reserve(v.size() / 2);
    for (const auto x : v) {
        if (ret.empty() || ret.back().first != x) {
            ret.emplace_back(x, 1);
        } else {
            ++ret.back().second;
        }
    }
    return ret;
}
struct primeSieve {
    ll n;
    vector<ll> primeFactor;
    vector<ll> primes;

    primeSieve(const ll n = 1) : n(n), primeFactor(n + 1, 0) {
        primeFactor[0] = primeFactor[1] = -1;
        for (ll i = 2; i <= n; ++i) {
            if (primeFactor[i])
                continue;
            primes.push_back(i);
            primeFactor[i] = i;
            for (ll j = i * i; j <= n; j += i) {
                if (!primeFactor[j])
                    primeFactor[j] = i;
            }
        }
    }
    bool isPrime(const ll x) const { return primeFactor[x] == x; }
    vector<ll> factorList(ll x) const {
        vector<ll> res;
        while (x != 1) {
            res.push_back(primeFactor[x]);
            x /= primeFactor[x];
        }
        return res;
    }
    vector<pair<ll, ll>> factor(const ll x) const { return rle(factorList(x)); }
};
