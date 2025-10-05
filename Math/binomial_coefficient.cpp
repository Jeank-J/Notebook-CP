#define ll long long

const ll mod = 1e9 + 7;
const int MX = 1e6 + 7;

ll factorial[MX];
ll inv[MX];
ll inverse_factorial[MX];

void precompute(){

    inv[1] = factorial[0] = inverse_factorial[0] = 1;

    for (int i = 2; i < MX; i++){
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }
    
    for (int i = 1; i < MX; i++) {
        factorial[i] = factorial[i - 1] * i % mod;
        inverse_factorial[i] = inverse_factorial[i - 1] * inv[i] % mod;
    }
}

ll binomial_coefficient(ll n, ll k){
    return factorial[n] * inverse_factorial[k] % mod * inverse_factorial[n - k] % mod;
}
