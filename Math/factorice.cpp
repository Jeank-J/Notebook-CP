#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MX = 1e6 + 7;
int spf[MX];            // menor factor primo de cada número
vector<int> primes;
bool compuesto[MX];

void sieve() {
    for (int i = 2; i < MX; i++) spf[i] = i;
    for (int i = 2; i * i < MX; i++) {
        if (!compuesto[i]) {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j < MX; j += i) {
                if (!compuesto[j]) {
                    compuesto[j] = true;
                    spf[j] = i;  // primer primo que divide a j
                }
            }
        }
    }
}


vector<pair<int,int>> factorizar(int x) {
    vector<pair<int,int>> fac;
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        fac.push_back({p, cnt});
    }
    return fac;
}