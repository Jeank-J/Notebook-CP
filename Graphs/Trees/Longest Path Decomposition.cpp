# Longest Path Decomposition (LPD)

Descompone un árbol en caminos disjuntos.

Idea:
Desde cada nodo se continúa por el hijo cuya profundidad
hasta una hoja es máxima.

Los demás hijos comienzan nuevos caminos.
Cada nodo pertenece exactamente a un camino.

int nxt[N];
int depth[N];

vector <vector <int>> g(N);

void dfs_depth(int u){

    nxt[u] = -1;
    depth[u] = 0;

    for(int v: g[u]){        

        dfs_depth(v);
        if(depth[v] + 1 > depth[u]){
            depth[u] = depth[v] + 1;
            nxt[u] = v;
        }
    }
}

void build(int u,int id){

    paths[id].push_back(u);
    if(nxt[u] != -1) build(nxt[u],id);

    for(int v: g[u]){

        if(v == nxt[u])continue;
        paths.pb({});
        build(v,sz(paths)-1);
    }
}

bool cmp(vector <int> &a, vector <int> &b){
    return sz(a) > sz(b);
}


// llamado

dfs_depth(1);
  
paths.pb({});
build(1,0);

sort(all(paths), cmp);
