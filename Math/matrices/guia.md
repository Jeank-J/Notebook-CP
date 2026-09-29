# Recurrencia con matrices

Partimos de la recurrencia:

$$
F(n) = 3F(n-1) + 2F(n-2)
$$

Desplazamos el índice:

$$
F(n+1) = 3F(n) + 2F(n-1)
$$

Definimos el estado como:

$$
\begin{pmatrix}
F(n) \\
F(n-1)
\end{pmatrix}
$$

Queremos expresarlo en función del estado anterior:

$$
\begin{pmatrix}
F(n-1) \\
F(n-2)
\end{pmatrix}
$$

Por lo tanto, planteamos una matriz desconocida:

$$
\begin{pmatrix}
F(n) \\
F(n-1)
\end{pmatrix}
=
\begin{pmatrix}
a & b \\
c & d
\end{pmatrix}
\begin{pmatrix}
F(n-1) \\
F(n-2)
\end{pmatrix}
$$

### Multiplicación de la matriz

La multiplicación se realiza fila por columna:

$$
\begin{pmatrix}
a & b \\
c & d
\end{pmatrix}
\begin{pmatrix}
F(n-1) \\
F(n-2)
\end{pmatrix}
=
\begin{pmatrix}
aF(n-1) + bF(n-2) \\
cF(n-1) + dF(n-2)
\end{pmatrix}
$$

### Igualando con la recurrencia

Comparando la primera fila con $F(n) = 3F(n-1) + 2F(n-2)$:

$$
a = 3, \quad b = 2
$$

Comparando la segunda fila con $F(n-1) = 1 \cdot F(n-1) + 0 \cdot F(n-2)$:

$$
c = 1, \quad d = 0
$$

Por lo tanto, la matriz de transición es:

$$
\begin{pmatrix}
F(n) \\
F(n-1)
\end{pmatrix}
=
\begin{pmatrix}
3 & 2 \\
1 & 0
\end{pmatrix}
\begin{pmatrix}
F(n-1) \\
F(n-2)
\end{pmatrix}
$$

### Forma matricial general

Esto permite calcular $F(n)$ elevando la matriz a la potencia $n$:

$$
\begin{pmatrix}
F(n) \\
F(n-1)
\end{pmatrix}
=
\begin{pmatrix}
3 & 2 \\
1 & 0
\end{pmatrix}^{n-1}
\begin{pmatrix}
F(1) \\
F(0)
\end{pmatrix}
$$
