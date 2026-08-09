struct Matrix {
    int n, m;
    vector<vector<ll>> a;

    Matrix(int n, int m, vector<vector<ll>> a)
        : n(n), m(m), a(a) {}

    Matrix operator*(const Matrix& other) const {
        Matrix res(n, other.m,
                   vector<vector<ll>>(n, vector<ll>(other.m, 0)));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                for (int j = 0; j < other.m; j++) {
                    res.a[i][j] += a[i][k] * other.a[k][j];
                    res.a[i][j] %= MOD;
                }
            }
        }

        return res;
    }
};

Matrix expo_matrix(Matrix base, long long potencia) {
    Matrix res(
        base.n,
        base.n,
        vector<vector<ll>>(base.n, vector<ll>(base.n, 0))
    );

    for (int i = 0; i < base.n; i++)
        res.a[i][i] = 1;

    while (potencia) {
        if (potencia & 1)
            res = res * base;

        base = base * base;
        potencia >>= 1;
    }

    return res;
};


vector<vector<ll>> v = {
    {2, 1, 1},
    {0, 1, 1},
    {0, 0, 1}
};

Matrix M(3, 3, v);

Matrix ans = expo_matrix(M, n);
