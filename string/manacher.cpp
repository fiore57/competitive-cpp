string addDummy(const string &s) {
    string ret(s.size() * 2 + 1, '-');
    rep(i, s.size()) ret[i * 2 + 1] = s[i];
    return ret;
}
vint manacher(const string &s) {
    int n = s.size();
    vint ret(n);
    int i = 0, j = 0;
    while (i < n) {
        while (i - j >= 0 && i + j < n && s[i - j] == s[i + j])
            ++j;
        ret[i] = j;
        int k = 1;
        while (i - k >= 0 && i + k < n && k + ret[i - k] < j)
            ret[i + k] = ret[i - k], ++k;
        i += k;
        j -= k;
    }
    return ret;
}