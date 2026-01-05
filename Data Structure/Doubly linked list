#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> lis = {1, 4, 5, 9, 0, 10};

    // 1) Guardar iteradores (acceso directo O(1))
    vector<list<int>::iterator> pos(11);
    for (auto it = lis.begin(); it != lis.end(); ++it)
        pos[*it] = it;

    // 2) Consultar previo y siguiente (O(1))
    int x = 9;
    auto it = pos[x];
    auto it_prev = (it == lis.begin() ? lis.end() : prev(it));
    auto it_next = next(it); // puede ser end()

    // 3) Eliminar en O(1) usando iterador
    lis.erase(it);
    pos[x] = lis.end(); // invalida referencia

    // 4) Insertar / mover sin invalidar iteradores
    auto it0 = pos[0];
    lis.insert(it0, 7); // inserta antes de 0

    // 5) Splice: mover nodos reales en O(1)
    list<int> other = {2, 3};
    auto first = prev(lis.end(), 2);
    other.splice(other.end(), lis, first, lis.end());

    // other: 2 3 0 10
}
