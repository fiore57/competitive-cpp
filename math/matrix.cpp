using Vector = vll;
using Matrix = vvll;

// A * B
Matrix matMul(const Matrix &A, const Matrix &B, const int Mod) {
    Matrix C(A.size(), Vector(B.front().size()));
    rep(i, A.size()) rep(k, B.size()) rep(j, B.front().size()) C[i][j] =
        (C[i][j] + A[i][k] * B[k][j]) % Mod;
    return C;
}

// A^n
Matrix matPow(Matrix A, ll n, const int Mod) {
    Matrix B(A.size(), Vector(A.size()));
    rep(i, A.size()) B[i][i] = 1;
    while (n > 0) {
        if (n & 1)
            B = matMul(B, A, Mod);
        A = matMul(A, A, Mod);
        n >>= 1;
    }
    return B;
}