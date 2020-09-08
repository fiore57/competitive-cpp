template <typename Container>
inline void UNIQUE(Container &&c) {
    c.erase(std::unique(begin(c), end(c)), end(c));
}