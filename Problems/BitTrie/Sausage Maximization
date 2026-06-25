/*
** Sausage Maximization
** https://codeforces.com/contest/282/problem/E
*/

//g++ -g -Wall -Wshadow -std=c++17 -Wno-unused-testult -Wno-sign-compare -Wno-char-subscripts -DLOCAL -o main main.cpp && main < in.txt
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T> using T_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class L> using T_multiset = tree<L, null_type, less_equal<L>, rb_tree_tag, tree_order_statistics_node_update>;

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
#define show(x) for (auto &num: x) cout << num << " "; cout << endl;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

#define pc(x) __builtin_popcount(x)
#define lsb(x) ((x) & -(x))
#define lsb_idx(x) __builtin_ctz(x)
#define on(x,i) ((x) |= (1LL << (i)))
#define off(x,i) ((x) &= ~(1LL << (i)))
#define toggle(x,i) ((x) ^= (1LL << (i)))

struct Trie {

    struct Node {

        int child[2]; // guarda la posicione de cada hijo en el vector trie
        int mn;

        Node() {
            child[0] = child[1] = -1;
            mn = 1e9;
        }
        void updMn(int x){
            mn = min(mn,x);
        }
    };

    vector<Node> trie;

    Trie() {
        trie.push_back(Node()); // raíz
    }

    void insert(ll num, int pos){

        int nodo = 0;
        for (int i = 40; i >= 0; i--){
            int bit = (num >> i) & 1;
            int nxt = trie[nodo].child[bit];
            if (nxt != -1){
                trie[nxt].updMn(pos);
            }else{
                nxt = trie.size();
                trie[nodo].child[bit] = nxt;
                trie.pb(Node());          
                trie[nxt].updMn(pos);
            }
            nodo = nxt;
        }
        
    }

    ll getAns(ll x, int i, int nodo, int pos){

        if (i < 0) return 0;
        int bit = (x >> i) & 1LL;
        int nxt0 = trie[nodo].child[0];
        int nxt1 = trie[nodo].child[1];

        //dbg(x,i,nodo,pos);

        // si el bit en x esta encendido, conviene buscar un cero
        if (bit == 1){
            if (nxt0 != -1 and trie[nxt0].mn < pos){                
                return getAns(x,i-1,nxt0,pos);
            }
            if (nxt1 !=-1 and trie[nxt1].mn < pos){                
                return (1LL << i) | getAns(x,i-1,nxt1,pos);
            }
            return 0;
        }

        // caso contrario
        if (nxt1 !=-1 and trie[nxt1].mn < pos){            
            return (1LL << i) | getAns(x,i-1,nxt1,pos);
        }
        if (nxt0 != -1 and trie[nxt0].mn < pos){            
            return getAns(x,i-1,nxt0,pos);
        }
        
        return 0;
    }


    


};

void solve(){
    
    
    int n;
    cin >> n;

    Trie t;

    vector <ll> v(n);
    read(v);

    ll XOR = 0;
    ll best = 0;
    forn(i,n){        
        XOR ^= (v[i]);
        t.insert(XOR,i);
        best = max(best,XOR);        
        dbg(XOR);
    }    
    XOR = 0;
    
    

    rforn(i,n){
        XOR ^= (v[i]);
        dbg(XOR);
        best = max(best, XOR);
        ll current = XOR;
        current ^= t.getAns(current,40,0,i);
        best = max(best,current);

    }

    cout << best << endl;

}

int main() {

    FAST
    int test = 1;
    //cin >> test;    
    while(test--) solve();

    return 0;
}
