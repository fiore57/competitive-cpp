class Dice {
    int l, r, f, b, d, u;

public:
    Dice(const int l, const int r, const int f, const int b, const int d,
         const int u)
        : l(l), r(r), f(f), b(b), d(d), u(u) {}
    void roll_x() { cyclic_shift(d, f, u, b); }
    void roll_x_() { cyclic_shift(d, b, u, f); }
    void roll_y() { cyclic_shift(f, l, b, r); }
    void roll_y_() { cyclic_shift(f, r, b, l); }
    void roll_z() { cyclic_shift(d, l, u, r); }
    void roll_z_() { cyclic_shift(d, r, u, l); }
    bool operator==(const Dice &rhs) const {
        return l == rhs.l && r == rhs.r && f == rhs.f && b == rhs.b &&
               d == rhs.d && u == rhs.u;
    }

    vector<Dice> all_rolls() {
        vector<Dice> ret;
        rep(i, 6) {
            rep(j, 4) {
                ret.push_back(*this);
                roll_z();
            }
            if (i % 2 == 0)
                roll_x();
            else
                roll_y();
        }
        return ret;
    }
    bool equivalent_to(const Dice &rhs) {
        for (const auto &lhs : all_rolls()) {
            if (lhs == rhs)
                return true;
        }
        return false;
    }

private:
    void cyclic_shift(int &a, int &b, int &c, int &d) {
        int e = a;
        a = b, b = c, c = d, d = e;
    }
};