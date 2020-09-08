---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/matrix.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 14:43:17+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/matrix.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

