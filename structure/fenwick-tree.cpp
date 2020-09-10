template <class T>
using is_signed_int =
    typename std::conditional<std::is_integral<T>::value &&
                                  std::is_signed<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<std::is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type, std::false_type>::type;

template <class T>
using to_unsigned =
    typename std::conditional<is_signed_int<T>::value, std::make_unsigned<T>,
                              std::common_type<T>>::type;

template <class T>
using to_unsigned_t = typename to_unsigned<T>::type;

template <class T>
class FenwickTree {
    using U = to_unsigned_t<T>;

public:
    FenwickTree() = default;
    explicit FenwickTree(const int n) : _n(n), floor_pow2(1), data(n) {
        while ((static_cast<uint32_t>(floor_pow2) << 1) <=
               static_cast<uint32_t>(_n))
            floor_pow2 <<= 1;
    }

    void add(int pos, const T x) {
        assert(0 <= pos && pos < _n);
        ++pos;
        for (; pos <= _n; pos += pos & -pos)
            data[pos - 1] += static_cast<U>(x);
    }

    T sum(const int l, const int r) const {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

    // sum(x) >= w となる最小のxを求める
    int lower_bound(int w) {
        if (w <= 0)
            return 0;
        int x = 0;
        for (int k = floor_pow2; k > 0; k >>= 1) {
            if (x + k <= _n && data[x + k - 1] < static_cast<U>(w)) {
                w -= data[x + k - 1];
                x += k;
            }
        }
        return x;
    }

private:
    int _n = 0;
    int floor_pow2 = 0; // _n 以下の最大の2羃
    std::vector<U> data;

    U sum(int r) const {
        U ret = 0;
        for (; r > 0; r -= r & -r)
            ret += data[r - 1];
        return ret;
    }
};