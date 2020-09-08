ll myPow(ll x, ll n, const ll mod = -1) {
    ll ret = 1;
    if (mod > 0) {
        while (n > 0) {
            if (n & 1)
                ret = (ret * x) % mod;
            x = (x * x) % mod;
            n >>= 1;
        }
    } else {
        while (n > 0) {
            if (n & 1)
                ret = ret * x;
            x *= x;
            n >>= 1;
        }
    }
    return ret;
}