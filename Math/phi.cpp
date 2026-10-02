La función phi(n) de Euler devuelve la cantidad de enteros positivos menores o iguales a n que son coprimos con n (es decir, su MCD con n es 1).
phi(n) = n * (1 − 1 / p1​) * (1 − 1/ p2​) * ...
r = n;
-> r * (1 - 1 / i)
-> r - r / i
-> r -= r / i

int phi(int n) {
    int r = n;
    for (int i = 2; i * i <= n; i++) {

        if (n % i == 0) {

            while (n % i == 0)
                n /= i;

            r -= r / i;
        }
    }
    if (n > 1)
        r -= r / n;

    return r;
}
