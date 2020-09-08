template <typename T, typename S>
class SWAG {
    using F1 = function<S(S, T)>;
    using F2 = function<S(T, S)>;
    const F1 f1;
    const F2 f2;
    S id;
    vector<T> lt, rt;
    vector<S> ls, rs;

public:
    SWAG(const F1 f1, const F2 f2, const S id)
        : f1(f1), f2(f2), id(id), ls(1, id), rs(1, id) {}
    // S, T identical / commutative is not required
    // clang-format off
    SWAG(const F1 f1, const S id)
        : SWAG(f1, [&f1](const T y, const S x) { return f1(y, x); }, id) {}
    // clang-format on

    void push(const T x) {
        rt.emplace_back(x);
        rs.emplace_back(f1(rs.back(), x));
    }

    void pop() {
        if (lt.empty()) {
            reverse(rt.begin(), rt.end());
            for (auto x : rt) {
                lt.emplace_back(x);
                ls.emplace_back(f2(x, ls.back()));
            }
            rt.resize(0);
            rs.resize(1);
        }
        lt.pop_back();
        ls.pop_back();
    }

    template <typename Q>
    void fold(const Q q) const {
        q(ls.back(), rs.back());
    }
};