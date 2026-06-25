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
