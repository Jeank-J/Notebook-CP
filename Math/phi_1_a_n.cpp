vector<int> phi_1_a_n(int n) {

    vector<int> phi(n + 1);

    // Inicializar
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    // Criba tipo Euler
    for (int i = 2; i <= n; i++) {
        // Si aún no cambió, es primo
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }

    return phi;
}
