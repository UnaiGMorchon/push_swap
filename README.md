*Este proyecto ha sido creado como parte del currículo de 42 por patperez y ugarcia-*

# Push_swap

## Descripción

**Push_swap** es un proyecto de desarrollo de algoritmos en C cuyo objetivo es ordenar un conjunto de datos numéricos en un stack (Pila A) utilizando un stack auxiliar (Pila B) y un conjunto extremadamente limitado de operaciones. 

El verdadero reto del proyecto radica en la **optimización**: el programa debe calcular y mostrar por la salida estándar, la secuencia de instrucciones más corta posible. La eficiencia de las soluciones se evalúa directamente según el número de operaciones generadas (complejidad en base a movimientos del modelo *Push_swap*).

### Las Reglas
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

## Algoritmo Simple: Bubble Sort Modificado (O(n²))

### Estrategia y Operación Principal
El algoritmo utiliza la lógica clásica de ordenamiento por burbuja adaptada a la estructura cíclica de un Stack, usando únicamente las operaciones `ft_sa` y `ft_ra`.

* **Nota de Arquitectura:** Los volúmenes pequeños de **3 a 5 elementos se gestionan en otro módulo optimizado** (árbol de decisión y búsqueda de mínimos) para cumplir estrictamente el límite de 2 a 12 movimientos del proyecto. Este bloque es la lógica base del algoritmo.

---

### Puntos Clave del Funcionamiento

* **Bucle de Control (`swapped`):** El algoritmo se repite continuamente en un bucle principal mientras se sigan detectando y ejecutando intercambios de posición.
* **Comparación y Permutación (`ft_sa`):** En cada paso, comprueba si el elemento en la cima (`head`) es mayor que el que le sigue (`head->next`). Si están desordenados, los intercambia inmediatamente en el tope del stack.
* **Desplazamiento Cíclico (`ft_ra`):** Después de cada verificación (hayan cambiado o no), el stack rota hacia arriba para posicionar el siguiente par de elementos en la cima y poder compararlos.
* **Corrección de Alineación:** Al terminar cada pasada completa por el stack, se aplica una rotación extra (`ft_ra`) para reajustar la alineación del stack circular antes de iniciar la siguiente vuelta.






/*1. Algoritmo Simple (O(n2))
- Estrategia: Bubble Sort modificado y optimizado para la estructura de dos stacks:
- Caso de uso: Stack $A$ con 3 a 5 elementos. ??????? lo hace otro.
- Justificación: Para volúmenes de datos tan pequeños, los algoritmos complejos añaden un overhead innecesario de código y cálculo. Se implementa una lógica de árbol de decisión (hardcoding ordenado para 3 elementos) y búsquedas mecánicas del mínimo/máximo para 5 elementos, garantizando la resolución en un máximo de 2 a 12 movimientos (muy por debajo del límite de 12 para el caso de 5 elementos).*/

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

Thia / Thiasix Su rol se centró en la fase de investigación, lógica matemática adaptativa, validación inicial de datos y el desarrollo de la fontanería base (operaciones de los stacks).

 Tareas Principales:Lógica Matemática y Algoritmo Adaptativo:Diseñó e implementó la métrica de desorden (por inversión de pares), que sirve para evaluar el caos del stack y decidir qué algoritmo aplicar.Creó una función personalizada de raíz cuadrada ($\sqrt{n}$), clave para calcular dinámicamente el tamaño de los bloques (buckets) en el algoritmo intermedio.Investigó e inició la estructura preliminar del algoritmo complejo (Radix Sort).Operaciones Base de los Stacks (Punteros):Escribió el pseudocódigo original y los primeros tests de aprendizaje con nodos.Desarrolló y depuró las operaciones pa y pb (push a y push b), solucionando los primeros fallos de memoria (segfaults).Se encargó de la compleja lógica de punteros de las funciones de rotación inversa (reverse rotate), asegurando que funcionaran sin fugas de memoria (leaks).Validación de Entradas y Refactorización:Implementó los primeros filtros de verificación de errores para los argumentos introducidos por consola.Unificó los nombres de los archivos iniciales y pasó la Norminette en las operaciones de push.

ugarcia- Tu rol fue el de arquitecto principal, integrador del proyecto y desarrollador del núcleo algorítmico definitivo, asegurando la robustez y optimización del código final.

 Tareas Principales:Arquitectura de Datos y Robustez (Gestión de Errores):Diseñaste y modificaste la estructura final de los nodos (añadiendo variables críticas como head, tail, size, prev e índices).Implementaste la lógica de intercambio seguro (contenido vs. nodos) para evitar corrupciones de memoria.Evolucionaste el parseo de argumentos: concatenación con split, sustitución de atoi por atol para controlar desbordamientos (overflows) y detección estricta de duplicados.Desarrollo y Optimización de Algoritmos:Algoritmo Simple: Tu versión de Bubble Sort fue la que se quedó en el proyecto final por ser más limpia y eficiente (descartando pruebas anteriores).Algoritmo Medio: Desarrollaste e indexaste el Bucket Sort definitivo, gestionando los bloques y el paso eficiente de elementos al stack B usando la raíz cuadrada.Algoritmo Complejo: Implementaste y corregiste los fallos del Radix Sort hasta dejarlo totalmente operativo.Integración, Git Master y Entrega:Realizaste los merges críticos de la rama pat para unificar el trabajo de ambos y resolviste todos los conflictos de código intermedios.Te encargaste de la depuración final de leaks, la creación y mantenimiento del Makefile (integrando libft y ft_printf), y de adaptar todo el código a la Norminette.
 
  Resumen para la Defensa (En pocas palabras)Thia aportó la base matemática (métrica de desorden, raíz cuadrada para buckets), la validación inicial de los inputs y resolvió la difícil lógica de punteros de los movimientos push y reverse rotate.Unai diseñó la arquitectura final de las estructuras de datos, programó los tres algoritmos de ordenación definitivos (simple, buckets y radix), controló exhaustivamente los errores/leaks e integró todo el código bajo los estándares de la Norminette y el Makefile.

## Recursos y Uso de IA