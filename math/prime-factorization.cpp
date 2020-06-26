map<ll, ll> primeFactorization(ll n) {
    map<ll, ll> ret;
    for (int i = 2; i <= sqrt(n) + 1; ++i) {
        while (n % i == 0) {
            ++ret[i];
            n /= i;
        }
        if (n == 1)
            break;
    }
    if (n != 1)
        ++ret[n];
    return ret;
}
map<ll, ll> gcdPrimeFactorization(const ll a, const ll b) {
    map<ll, ll> ret;
    const auto mpa = primeFactorization(a);
    auto mpb = primeFactorization(b);
    for (const auto e : mpa) {
        if (mpb[e.first] == 0)
            continue;
        ret[e.first] = min(e.second, mpb[e.first]);
    }
    return ret;
}
map<ll, ll> lcmPrimeFactorization(const ll a, const ll b) {
    map<ll, ll> ret;
    const auto mpa = primeFactorization(a);
    auto mpb = primeFactorization(b);
    for (const auto e : mpa) {
        ret[e.first] = max(e.second, mpb[e.first]);
    }
    return ret;
}