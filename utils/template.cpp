//g++ -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++17 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts -DLOCAL -o code1 code1.cpp && ./code1 < in.txt
//g++ -g -Wall -Wshadow -std=c++17 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts -DLOCAL -o main main.cpp && ./main < in.txt
#include <bits/stdc++.h>

using namespace std;

#define dbg(...) cerr << #__VA_ARGS__ << " = ["; dbg_out(__VA_ARGS__); cerr << "]\n"
void dbg_out() {}

template <typename T, typename... Args>
void dbg_out(T x, Args... args) {
    cerr << x;
    if (sizeof...(args)) cerr << ",";
    dbg_out(args...);
}

#define forn(i,n) for (int i = 0; i < n; i++)
#define rforn(i,n) for (int i = n-1; i >= 0; i--)
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define ll long long 
#define sz(n) (int)n.size()
#define all(x) x.begin(), x.end()
#define read(x) for(auto &el : x) cin >> el;
#define show(x) for (auto &i: x) cout << i << " "; cout << endl;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

#define pc(x) __builtin_popcount(x)
#define lsb(x) ((x) & -(x))
#define lsb_idx(x) __builtin_ctz(x)
#define on(x,i) ((x) |= (1LL << (i)))
#define off(x,i) ((x) &= ~(1LL << (i)))
#define toggle(x,i) ((x) ^= (1LL << (i)))

void solve(){
    


}

int main() {

    FAST        
    int test = 1;        
    cin >> test;
    while (test--) solve();

    return 0;
}
