# DP Divide and Conquer — O(k·n²) → O(k·n log n)

Se aplica a DPs por capas de la forma:

```
dp[i][j] = min_{z<j} ( dp[i-1][z] + C(z+1, j) )
```

- `i`: número de grupos (cada capa depende solo de la anterior).
- `j`: cantidad de elementos tomados del inicio.
- `z`: cuántos elementos se llevan los primeros i-1 grupos.
- `C(l, r)`: costo de un grupo con las posiciones l..r.

Típico: partir un arreglo en k segmentos consecutivos minimizando la suma de costos.

Se debe cumplir la monotonía del corte óptimo: `opt[i][j] <= opt[i][j+1]`.

Se garantiza si C cumple la desigualdad del cuadrángulo. Para todo a <= b <= c <= d:

```
C(a,c) + C(b,d) <= C(a,d) + C(b,c)
⇔ C(a,d) - C(a,c) >= C(b,d) - C(b,c)
```

Es decir, agregar los mismos elementos al final cuesta más si el segmento es más largo.
Suele cumplirse con `f(suma)` si f es convexa y los elementos son >= 0, y con conteos de pares dentro del segmento.
Si hay duda: comparar contra la DP O(k·n²) con casos random y verificar que opt no decrezca.

Idea: para llenar la capa i, se resuelve primero la j del medio. Su corte óptimo sirve de techo para las j menores y de piso para las mayores. Cada nivel de la recursión recorre O(n) en total y hay log n niveles.

C(l, r) debe salir en O(1) (prefijos, etc.). Si no se puede, se mantiene un segmento actual con dos punteros (add/rem como en Mo, sin ordenar): el orden de la recursión ya hace que se muevan O(n log n) por capa.

```cpp
const int N = 1e5+1;
const int M = 21;

ll dp[M][N];   // dp[i][j]: costo mínimo de dividir los primeros j elementos en i grupos
int v[N];      // indexado desde 1
int freq[N];

// segmento actual [curL, curR] para calcular C(l, r) moviendo punteros
// add/rem dependen del costo del problema (aquí: pares de valores iguales)
int curL = 0, curR = -1;
ll curCost = 0;
void add(int pos){
    curCost += freq[v[pos]];
    freq[v[pos]]++;
}
void rem(int pos){
    freq[v[pos]]--;
    curCost -= freq[v[pos]];
}

// C(l, r) = costo del grupo v[l..r]; primero agrandar, luego achicar
ll C(int l, int r){
    while (curL > l) add(--curL);
    while (curR < r) add(++curR);
    while (curL < l) rem(curL++);
    while (curR > r) rem(curR--);
    return curCost;
}

// l..r       -> qué valores de j (dp[i][j]) calcula esta llamada
// optl..optr -> rango donde puede estar el corte óptimo de esas j
void calcule(int i, int l, int r, int optl, int optr){
    if (l > r) return;
    int mid = (l + r) / 2;
    ll ans = 1e18;
    int z = optl;
    // itero sobre el rango válido; j <= mid-1 porque el último grupo necesita al menos un elemento
    for (int j = optl; j <= min(optr, mid-1); j++){
        // j elementos en i-1 grupos + el grupo nuevo que va de j+1 a mid
        ll cost = dp[i-1][j] + C(j+1,mid);
        if (cost < ans){
            ans = cost;
            z = j;
        }
    }
    dp[i][mid] = ans;

    // por monotonía: las j < mid cortan en <= z, las j > mid en >= z
    calcule(i, l, mid-1, optl, z);
    calcule(i, mid+1, r, z, optr);
}

void solve(){
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> v[i];

    // caso base: dp[0][0] = 0, el resto INF
    for (int i = 0; i < N; i++) dp[0][i] = 1e18;
    dp[0][0] = 0;

    // cada capa se llena entera: j en [1, n], cortes posibles en [0, n-1]
    for (int i = 1; i <= k; i++){
        calcule(i,1,n,0,n-1);
    }

    cout << dp[k][n] << endl;   // respuesta
}
```
