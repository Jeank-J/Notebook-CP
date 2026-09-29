# Recurrencia con matrices

Partimos de la recurrencia:

```math
F(n) = 3F(n-1) + 2F(n-2)
```

Desplazamos el índice:

```math
F(n+1) = 3F(n) + 2F(n-1)
```

Definimos el estado como:

```math
\begin{pmatrix} F(n) \\ F(n-1) \end{pmatrix}
```

Queremos expresarlo en función del estado anterior:

```math
\begin{pmatrix} F(n-1) \\ F(n-2) \end{pmatrix}
```

Por lo tanto, planteamos una matriz desconocida:

```math
\begin{pmatrix} F(n) \\ F(n-1) \end{pmatrix} = \begin{pmatrix} a & b \\ c & d \end{pmatrix} \begin{pmatrix} F(n-1) \\ F(n-2) \end{pmatrix}
```

### Multiplicación de la matriz

La multiplicación se realiza fila por columna:

```math
\begin{pmatrix} a & b \\ c & d \end{pmatrix} \begin{pmatrix} F(n-1) \\ F(n-2) \end{pmatrix} = \begin{pmatrix} aF(n-1) + bF(n-2) \\ cF(n-1) + dF(n-2) \end{pmatrix}
```

### Igualando con la recurrencia

Igualamos la primera componente con $F(n) = 3F(n-1) + 2F(n-2)$:

```math
a = 3, \quad b = 2
```

La segunda componente corresponde a $F(n-1)$:

```math
c = 1, \quad d = 0
```

Por lo tanto:

```math
\begin{pmatrix} F(n) \\ F(n-1) \end{pmatrix} = \begin{pmatrix} 3F(n-1) + 2F(n-2) \\ 1 \cdot F(n-1) + 0 \cdot F(n-2) \end{pmatrix} = \begin{pmatrix} 3 & 2 \\ 1 & 0 \end{pmatrix} \begin{pmatrix} F(n-1) \\ F(n-2) \end{pmatrix}
```

### Condiciones iniciales

```math
F(0) = 1, \quad F(1) = 2
```

```math
\begin{pmatrix} F(1) \\ F(0) \end{pmatrix} = \begin{pmatrix} 2 \\ 1 \end{pmatrix}
```

### Ejemplo: calcular $F(3)$

```math
F(2) = 3F(1) + 2F(0) = 3 \cdot 2 + 2 \cdot 1 = 6 + 2 = 8
```

```math
F(3) = 3F(2) + 2F(1) = 3 \cdot 8 + 2 \cdot 2 = 24 + 4 = 28
```

### Verificación con la matriz

```math
\begin{pmatrix} F(3) \\ F(2) \end{pmatrix} = M^2 \begin{pmatrix} 2 \\ 1 \end{pmatrix}, \quad M = \begin{pmatrix} 3 & 2 \\ 1 & 0 \end{pmatrix}
```

```math
M^2 = \begin{pmatrix} 11 & 6 \\ 3 & 2 \end{pmatrix}
```

```math
M^2 \begin{pmatrix} 2 \\ 1 \end{pmatrix} = \begin{pmatrix} 11 & 6 \\ 3 & 2 \end{pmatrix} \begin{pmatrix} 2 \\ 1 \end{pmatrix} = \begin{pmatrix} 28 \\ 8 \end{pmatrix}
```

```math
\Rightarrow F(3) = 28
```
