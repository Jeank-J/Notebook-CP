#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MX = 1e6;

vector <int> primes;
bool compuesto[MX];

void sieve(){        
    for (int i = 2; i < MX; i++){
        if (compuesto[i] == false){
            primes.push_back(i);
            for (ll j = 1LL * i * i;j <  MX; j+= i){
                compuesto[j] = true;
            }
        }
    }
}
