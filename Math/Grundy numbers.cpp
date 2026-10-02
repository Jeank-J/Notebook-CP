/*
Para cada estado S del juego se define el numero:
G(S) = mex( G(T) : para todo T que sea un estado alcanzable desde S)

el Grundy total es:
G(S1​+S2​+S3​) = G(S1​) ^ G(S2​) ^ G(S3​)
*/


/*
Usar Grundy cuando...

Se cumplen principalmente estas condiciones:

- Es un juego de dos jugadores.
- Los jugadores tienen los mismos movimientos disponibles desde un mismo estado.
- No importa quién esté jugando.
- Ejemplo: "puedes quitar 1, 2 o 3 piedras".
- Hay información perfecta: ambos conocen todo el estado.
- No hay azar.

