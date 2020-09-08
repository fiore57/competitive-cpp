class RandomNumber {
public:
    RandomNumber()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    int operator()(const int a, const int b) // [a, b)
    {
        uniform_int_distribution<int> dist(a, b - 1);
        return dist(mt);
    }
    int operator()(const int b) // [0, b)
    {
        return (*this)(0, b);
    }

private:
    mt19937 mt;
};