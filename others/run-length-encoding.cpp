template <typename T>
vector<pair<T, ll>> rle(const vector<T> &v) {
    vector<pair<T, ll>> ret;
    ret.reserve(v.size() / 2);
    for (const auto &x : v) {
        if (ret.empty() || ret.back().first != x) {
            ret.emplace_back(x, 1);
        } else {
            ++ret.back().second;
        }
    }
    return ret;
}
vector<pair<char, ll>> rle(const string &s) {
    vector<pair<char, ll>> ret;
    ret.reserve(s.size() / 2);
    for (const auto &c : s) {
        if (ret.empty() || ret.back().first != c) {
            ret.emplace_back(c, 1);
        } else {
            ++ret.back().second;
        }
    }
    return ret;
}