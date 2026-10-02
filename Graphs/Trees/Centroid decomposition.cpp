 // Idea general, el codigo es con un enfoque a un problema en concreto

const int N = 2e5+1;
vector < vector <int> > g(N);
int pivot = 1;
int removed[N];
int subtree_size[N];
 
unordered_set <int> op;
 
int get_subtree_size(int u, int p = -1) {
    subtree_size[u] = 1;
    for (int v: g[u]) {
        if (v == p or removed[v] == pivot) continue;
        subtree_size[u] += get_subtree_size(v, u);
    }
    return subtree_size[u];
}
 
int get_centroid(int u, int tree_size, int p = -1) {
    for (int v: g[u]) {
        if (v == p or removed[v] == pivot) continue;
        if (subtree_size[v] * 2 > tree_size)
            return get_centroid(v, tree_size, u);
    }
    return u;
}
 
void get_distances(int u, int p, int dist, vector<int>& distances) {    
    if (sz(g[u]) == 1)
        distances.push_back(dist);
 
    for (int v: g[u]){
        if (v == p or removed[v] == pivot) continue;
        get_distances(v, u, dist + 1, distances);
    }
}
 
 
int all_distances[N];
int used[N];
int pivot2 = 1;
ll ans[N];
 
 
 
void process_centroid(int centroid) {    
    pivot2++;
    if (sz(g[centroid]) == 1){
        used[0] = pivot2;
        all_distances[0] = 1;
    }
 
 
    for (int v: g[centroid]) {
        if (removed[v] == pivot) continue;
 
        vector<int> current_distances;
        get_distances(v, centroid, 1, current_distances);
 
        for (int d: current_distances) {
            for (auto X: op){
                if (X - d >= 0 and used[X-d] == pivot2)  ans[X] += (all_distances[X - d]);            
            }
        }
 
        for (int d: current_distances){
            if (used[d] != pivot2){
                used[d] = pivot2;
                all_distances[d] = 0;
            }
            all_distances[d]++;
        }
    }
}
 
 
void decompose(int u) {
 
 
    int tree_size = get_subtree_size(u);
    int centroid = get_centroid(u, tree_size);
 
    process_centroid(centroid);
    removed[centroid] = pivot;
 
    for (int v : g[centroid]) {
        if (removed[v] != pivot) {
            decompose(v);
        }
    }
}
