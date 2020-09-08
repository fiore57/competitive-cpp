bool isSquare(const ll n) {
    ll ng = INF; // 注意
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        (mid * mid <= n ? ok : ng) = mid;
    }
    return (ok * ok == n);
}