*Este proyecto ha sido creado como parte del currículo de 42 por patperez y ugarcia-*

# Push_swap — Porque Swap_push no suena tan natural

## Descripción

**Push_swap** es un proyecto de desarrollo de algoritmos en C cuyo objetivo es ordenar un conjunto de datos numéricos en un stack (Pila A) utilizando un stack auxiliar (Pila B) y un conjunto extremadamente limitado de operaciones. 

El verdadero reto del proyecto radica en la **optimización**: el programa debe calcular y mostrar por la salida estándar (`stdout`) la secuencia de instrucciones más corta posible. La eficiencia de las soluciones se evalúa directamente según el número de operaciones generadas (complejidad en base a movimientos del modelo *Push_swap*).

### Las Reglas del Juego
Disponemos de dos stacks (`a` y `b`) y los siguientes movimientos autorizados:
* `sa` / `sb` / `ss`: Intercambia (*swap*) los dos primeros elementos de un stack.
* `pa` / `pb`: Toma el primer elemento de un stack y lo pone (*push*) en el otro.
* `ra` / `rb` / `rr`: Desplaza hacia arriba todos los elementos (*rotate*). El primero pasa a ser el último.
* `rra` / `rrb` / `rrr`: Desplaza hacia abajo todos los elementos (*reverse rotate*). El último pasa a ser el primero.

---

## Instrucciones de Uso

### Compilación
El proyecto incluye un `Makefile` que compila el código fuente sin hacer *relink*. Los comandos disponibles son:
```bash
make          # Compila el binario push_swap
make clean    # Elimina los archivos objeto (.o)
make fclean   # Elimina los objetos y los binarios ejecutables
make re       # Limpia y vuelve a compilar todo
```

### Ejecución
El programa acepta una lista de enteros como argumento y flags opcionales para forzar la estrategia de ordenación:

```bash
# Ejecución por defecto (Estrategia Adaptativa)
./push_swap 2 1 3 6 5 8

# Forzar una estrategia específica
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 6 3 87 23
```

### Modo Benchmark ( --bench )
Si se activa la flag --bench , el programa redirige a la salida de error estándar ( stderr ) un desglose
detallado del rendimiento:

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

## Decisiones Técnicas y Algoritmos
Para cumplir con los requisitos de comprensión de complejidad, el binario integra cuatro estrategias diferentes:
1. Algoritmo Simple (O(n2))
- Estrategia: Bubble Sort modificado y optimizado para la estructura de dos stacks:
- Caso de uso: Stack $A$ con 3 a 5 elementos.
- Justificación: Para volúmenes de datos tan pequeños, los algoritmos complejos añaden un overhead innecesario de código y cálculo. Se implementa una lógica de árbol de decisión (hardcoding ordenado para 3 elementos) y búsquedas mecánicas del mínimo/máximo para 5 elementos, garantizando la resolución en un máximo de 2 a 12 movimientos (muy por debajo del límite de 12 para el caso de 5 elementos).

2. Algoritmo Intermedio (O(n√n))
- Estrategia: Bins / Bucket adaptado.
- Caso de uso: Stack $A$ con 100 elementos.
- Justificación: En lugar de ordenar directamente en el stack $A$, los elementos se pre-indexan de $0$ a $n-1$. Posteriormente, se dividen en "bloques" o buckets dinámicos basados en la raíz cuadrada del total de elementos ($\sqrt{n}$).Mecánica: Se envían los elementos al stack $B$ solo si pertenecen al bloque actual, manteniendo una estructura de "reloj de arena" (hourglass) en $B$. Esto reduce drásticamente el coste de rotación al devolver los elementos a $A$ ya semi-ordenados. Consigue una media de ~600 movimientos para 100 elementos (el límite para la máxima puntuación es 700).

3. Algoritmo Complejo (O(n log n))
- Estrategia: Radix binario (LSD - Least Significant Digit).
- Caso de uso: Stack $A$ con 500 elementos (o como fallback de alta eficiencia).
- Justificación: Al procesar bits en lugar de valores absolutos, el algoritmo garantiza una predictibilidad absoluta en el número de operaciones.Mecánica: Aprovechando los índices simplificados de los elementos, se evalúa cada bit (desde el menos significativo al más significativo). Si el bit actual es 0, el elemento se desplaza a $B$ (pb); si es 1, se mantiene en $A$ mediante una rotación (ra). Una vez procesados todos los bits, el stack queda perfectamente ordenado. Su coste para 500 elementos es estrictamente determinista y altamente eficiente en la estructura de push/rotate.

4. Algoritmo Adaptativo Personalizado
Este método calcula el Índice de Desorden del stack antes de realizar cualquier movimiento mediante a fórmula de inversión de pares:

```bash
		Índice = Errores / Total de pares
```

Dependiendo del umbral obtenido, el programa selecciona dinámicamente la técnica interna para garantizar la máxima eficiencia en movimientos:
| Régimen de Desorden | Umbral Técnico | Estrategia Interna Elegida | Complejidad de Operaciones |
| :--- | :--- | :--- | :--- |
| **Bajo** | `desorden < 0.2` | [Estrategia optimizada en hilos] | $O(n)$ |
| **Medio** | `0.2 ≤ desorden < 0.5` | [Algoritmo de Chunks / Bloques] | $O(n\sqrt{n})$ |
| **Alto** | `desorden ≥ 0.5` | [Radix Sort / QuickSort] | $O(n \log n)$ |

Justificación de Umbrales: Cuando el desorden es menor a 0.2, el stack está "casi ordenado", por lo que un enfoque de pasadas lineales (O(n)) con swaps localizados resuelve el problema con un número mínimo de operaciones,evitando el coste de mover bloques enteros a la pila B de forma innecesaria.

## Contribuciones y Trabajo en Grupo
Este es un proyecto conjunto desarrollado en un modelo de programación entre pares (pair
programming). Ambos integrantes conocemos el 100% de la lógica de la base del código.

patperez: Responsable de la arquitectura del Parser, validación de errores, gestión de
memoria libres/leaks y el desarrollo de los algoritmos Simple (O(n2)) y Complejo (O(n log n)).

ugarcia-: Responsable de la estructura de datos (Listas doblemente enlazadas/Arrays),
implementación de las 11 operaciones primitivas, el algoritmo Intermedio (O(n√n)) y la lógica del
Índice de Desorden junto al selector adaptativo.




🧑‍💻 Unai Garcia Morchon (ugarcia-)Has sido el motor principal del desarrollo lógico, algorítmico y de infraestructura general. Te has encargado de la arquitectura de las estructuras de datos, el parseo de argumentos y la implementación de los algoritmos de ordenación pesados.🔑 Tareas Principales:Algoritmos y Lógica de Ordenación:Implementaste y corregiste el Bubble Sort inicial (algoritmo simple) para dejarlo funcional.Desarrollaste e indexaste el Bucket Sort (algoritmo medio), gestionando la lógica de los bloques y el paso de elementos al stack $B$.Te pegaste con el algoritmo complejo (Radix Sort), corrigiendo sus fallos hasta dejarlo totalmente operativo.Estructuras de Datos y Operaciones Base:Diseñaste y modificaste la estructura de los nodos (añadiendo head, tail, size, prev e índices).Creaste y corregiste operaciones fundamentales del stack como reverse y ra.Parseo y Robustez (Gestión de Errores):Implementaste el control de argumentos: desde la concatenación inicial con split, pasando por la sustitución de atoi por atol para controlar desbordamientos, hasta la detección de números duplicados.Te encargaste de la depuración de leaks (fugas de memoria) y de adaptar el código final a las normas de la Norminette.Estructura del Proyecto: Creación y mantenimiento del Makefile integrando la libft y ft_printf.🧑‍💻 Thia / Thiasix (prg202@gmail.com)Ha tenido un rol enfocado en la fase inicial de experimentación, el desarrollo de los movimientos básicos de los stacks y la limpieza/unificación de código.🔑 Tareas Principales:Operaciones Base de Push y Pruebas Iniciales:Escribió el pseudocódigo original para los operadores de push y los primeros tests de aprendizaje con nodos.Creó los archivos del main dedicados a testear el comportamiento de las funciones básicas.Desarrolló y depuró las funciones pa y pb (push a y push b), solucionando los segfaults iniciales que daban estas operaciones.Inició la lógica de las funciones de rotación (rotate).Refactorización y Estilo:Se encargó de unificar los nombres de los archivos para que fuesen coherentes en todo el proyecto.Pasó la Norminette en los archivos de operaciones de push para asegurar que cumplieran los estándares del campus.Curiosidad del Historial: Lidió con un par de conflictos de Git graciosos durante los merges de junio ("what the fuck is merging").📊 Resumen de ColaboraciónLa base y los movimientos: Fueron un trabajo muy a la par en junio, donde Thia pulió los push y tú los swaps y rotates.La lógica pesada: Todo el desarrollo de julio (algoritmos de ordenación, gestión de índices complejos, control de errores estricto y limpieza final de la Norminette) fue asumido por ti (Unai).


## Recursos y Uso de IA