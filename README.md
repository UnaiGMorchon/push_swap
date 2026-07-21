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

Ejecución básica

### Ejecución por defecto (Estrategia Adaptativa)
```bash
./push_swap 2 1 3 6 5 8
```
Banderas / Flags Opcionales
El programa permite forzar una estrategia de ordenación específica o medir su rendimiento:

### Forzar una estrategia específica
```bash
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

### Verificación con el Checker oficial y conteo de líneas

```bash
# Contar el número de operaciones generadas
./push_swap 4 67 3 1 23 7 0 | wc -l

# Verificar con cheker oficial
ARG="4 67 3 1 23 7 0"; ./push_swap $ARG | ./checker $ARG
```
## Manejo de Errores

El programa gestiona y muestra `Error\n` en la salida de errores (stderr) si etecta:

- Argumentos que contengan caracteres no numéricos.

- Números que superen los límites de un entero de 32 bits (INT_MAX o INT_MIN).

- Números duplicados en los parámetros de entrada.

## Decisiones Técnicas y Algoritmos
Para optimizar la eficiencia según el volumen y estado de los datos, el binario integra cuatro estrategias:

## Casos Pequeños (3 a 5 elementos)
Gestionados mediante un módulo optimizado de árbol de decisión y búsqueda de mínimos, garantizando cumplir el límite estricto de 2 a 12 movimientos.

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

## Algoritmo Intermedio: Chunk / Bucket Sort ($O(n\sqrt{n})$)

### Estrategia y Operación Principal
El algoritmo optimiza el número de movimientos dividiendo el problema en bloques (*chunks* / *buckets*). Asigna a cada número una posición relativa de $0$ a $n-1$ (`ft_get_index`) y define un rango de bloque dinámico basado en la raíz cuadrada del total de elementos ($\sqrt{n}$).

* **Nota de Arquitectura:** En lugar de buscar una posición exacta en cada pasada, traslada a la **Pila B** cualquier elemento que pertenezca al bloque actual. Al vaciar la Pila A por bloques, el retorno desde B hacia A se realiza devolviendo siempre el elemento máximo disponible, reduciendo drásticamente las rotaciones.

---

### Puntos Clave del Funcionamiento

* **Pre-indexación (`ft_get_index`):** Normaliza los datos originales asignando a cada nodo un índice de $0$ a $n-1$ según su valor. Esto permite trabajar con rangos continuos independientes de los valores reales.
* **Cálculo de Bloques (`ft_sqroot`):** Establece la dimensión del *bucket* inicial como $\sqrt{\text{tamaño}}$ y define el límite superior (`number_limit`) de los elementos permitidos en la Pila B en cada etapa.
* **Vaciado Eficiente a Pila B (`ft_exist_bucket`):**
  * Si el elemento en la cima (`head->index`) entra dentro del límite actual, se envía a B con `ft_pb`.
  * Si no está en la cima pero aún quedan elementos dentro del rango en la Pila A, se rota con `ft_ra` para buscarlo.
  * Si ya no quedan elementos dentro del rango actual, se incrementa el límite (`number_limit += end_bucket`) para abrir el siguiente bloque.
* **Reintegración Optimizada a Pila A (`ft_rotate_decide`):**
  * Localiza la dirección del elemento con el índice más alto en B con `ft_max_index`.
  * Calcula si el elemento objetivo está en la mitad superior o inferior del stack.
  * Selecciona el camino más corto: rota hacia arriba (`ft_rb`) o rotación inversa hacia abajo (`ft_rrb`).
  * Al llegar a la cima, lo devuelve a A mediante `ft_pa`, dejando la Pila A ordenada de forma ascendente.


## Algoritmo Complejo (O(n log n))

### Estrategia y Operación Principal
Aprovecha la representación binaria de los índices previamente simplificados (de $0$ a $n-1$). Evalúa el stack bit a bit, desde el **Bit Menos Significativo (LSB)** hasta el **Bit Más Significativo (MSB)**, garantizando una complejidad determinista y predecible.

* **Nota de Arquitectura:** Al trabajar directamente sobre la propiedad `index` de los nodos en lugar de sus valores originales, el algoritmo normaliza la entrada. No realiza comparaciones directas entre valores (`<` o `>`), basándose puramente en operaciones bit a bit sobre dicho índice, lo que elimina los casos de peor rendimiento (*worst-case scenarios*).

---

### Puntos Clave del Funcionamiento

* **Cálculo de Pasadas (`ft_get_max_bits`):** Determina el número exacto de bits necesarios para representar el índice más alto ($\text{size} - 1$), marcando el total de iteraciones principales del algoritmo.
* **Evaluación Bit a Bit:** Un bucle principal procesa el bit $i$-ésimo en cada ciclo (empezando en $i = 0$).
* **Distribución Binaria en Pila A y B:**
  * Examina si el bit $i$ del nodo en la cima es `1` mediante el desplazamiento `(head->index >> i) & 1`.
  * **Si el bit es `1`:** El elemento se mantiene en la Pila A desplazándolo al fondo con `ft_ra`.
  * **Si el bit es `0`:** El elemento se expulsa a la Pila B con `ft_pb`.
* **Reconstrucción del Stack:** Al terminar de evaluar los $n$ elementos para el bit actual, todo el contenido acumulado en B se devuelve de nuevo a la Pila A usando `ft_pa`.
* **Alineación Final:** Al repetir este ciclo para todos los bits hasta `max_bits`, la Pila A queda automáticamente ordenada de menor a mayor sin requerir reajustes adicionales.

## Algoritmo Adaptativo (Selección por Índice de Desorden)
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

## 👥 Contribuciones y Trabajo en Equipo

Este proyecto fue desarrollado bajo la metodología de **Pair Programming**. Ambos integrantes comprenden y dominan el 100% de la lógica, arquitectura y decisiones del código fuente.

---

### **patperez** (Patricia) — Investigación, Lógica Matemática y Operaciones Base

* **Lógica Matemática y Algoritmo Adaptativo:**
  * Diseñó e implementó la métrica de **índice de desorden** (mediante inversión de pares) para evaluar el caos de la pila y seleccionar dinámicamente el algoritmo.
  * Desarrolló una función personalizada de raíz cuadrada ($\sqrt{n}$), clave para definir dinámicamente el tamaño de los bloques (*buckets*) en el algoritmo intermedio.
  * Realizó la investigación inicial y la estructura preliminar del algoritmo complejo (**Radix Sort**).

* **Operaciones Base y Punteros:**
  * Diseñó el pseudocódigo original y las primeras pruebas con nodos para la estructura de la pila.
  * Desarrolló y depuró las funciones `pa` y `pb` (*push*), resolviendo fallos de memoria (*segfaults*).
  * Implementó la lógica de punteros de las operaciones de rotación inversa (`rra`, `rrb`, `rrr`), garantizando su ejecución sin fugas de memoria (*leaks*).

* **Validación y Formato:**
  * Implementó los primeros filtros de verificación de errores para la validación de argumentos.
  * Estandarizó los nombres de archivos iniciales y adaptó las operaciones de *push* a la **Norminette**.

---

### **ugarcia-** (Unai) — Arquitectura de Datos, Algoritmos y Git Master

* **Arquitectura de Datos y Robustez:**
  * Rediseñó la estructura final de los nodos incorporando punteros y variables críticas (`head`, `tail`, `size`, `prev`, `index`).
  * Diseñó e implementó la lógica de intercambio seguro (contenido vs. nodos) para prevenir corrupciones de memoria.
  * Evolucionó el procesamiento de argumentos (*parsing*): concatenación con `ft_split`, sustitución de `ft_atoi` por `ft_atol` para mitigar desbordamientos (*overflows*) y detección estricta de duplicados.

* **Desarrollo y Optimización de Algoritmos:**
  * **Algoritmo Simple:** Desarrolló la versión final y optimizada de Bubble Sort.
  * **Algoritmo Medio:** Implementó e indexó el **Bucket Sort** definitivo, gestionando los bloques y el traspaso eficiente a la Pila B usando la raíz cuadrada.
  * **Algoritmo Complejo:** Desarrolló, depuró y finalizó la implementación operativa de **Radix Sort**.

* **Integración y Entrega:**
  * Gestor del repositorio Git: realizó los *merges* críticos unificando las ramas y resolviendo conflictos de código.
  * Encargado de la depuración final de fugas de memoria con Valgrind.
  * Creación y mantenimiento del `Makefile` (integrando `libft` y `ft_printf`) y adaptación final de todo el repositorio a los estándares de la **Norminette**.

---

### Resumen para la Defensa

> **Thia (`patperez`)** aportó la base matemática (métrica de desorden y cálculo de $\sqrt{n}$ para *buckets*), la validación inicial de argumentos y la lógica de punteros para las operaciones base de *push* y *reverse rotate*.
>
> **Unai (`ugarcia-`)** diseñó la arquitectura final de datos, programó los tres algoritmos definitivos (Simple, Buckets y Radix), garantizó la gestión estricta de errores y *leaks*, e integró todo el repositorio cumpliendo los estándares de Makefile y Norminette.































## Contribuciones y Trabajo en Grupo
Este es un proyecto conjunto desarrollado en un modelo de programación entre pares (pair programming). Ambos integrantes conocemos el 100% de la lógica de la base del código.

Thia / Thiasix Su rol se centró en la fase de investigación, lógica matemática adaptativa, validación inicial de datos y el desarrollo de la fontanería base (operaciones de los stacks).

 Tareas Principales:Lógica Matemática y Algoritmo Adaptativo:Diseñó e implementó la métrica de desorden (por inversión de pares), que sirve para evaluar el caos del stack y decidir qué algoritmo aplicar.Creó una función personalizada de raíz cuadrada ($\sqrt{n}$), clave para calcular dinámicamente el tamaño de los bloques (buckets) en el algoritmo intermedio.Investigó e inició la estructura preliminar del algoritmo complejo (Radix Sort).Operaciones Base de los Stacks (Punteros):Escribió el pseudocódigo original y los primeros tests de aprendizaje con nodos.Desarrolló y depuró las operaciones pa y pb (push a y push b), solucionando los primeros fallos de memoria (segfaults).Se encargó de la compleja lógica de punteros de las funciones de rotación inversa (reverse rotate), asegurando que funcionaran sin fugas de memoria (leaks).Validación de Entradas y Refactorización:Implementó los primeros filtros de verificación de errores para los argumentos introducidos por consola.Unificó los nombres de los archivos iniciales y pasó la Norminette en las operaciones de push.

ugarcia- Tu rol fue el de arquitecto principal, integrador del proyecto y desarrollador del núcleo algorítmico definitivo, asegurando la robustez y optimización del código final.

 Tareas Principales:Arquitectura de Datos y Robustez (Gestión de Errores):Diseñaste y modificaste la estructura final de los nodos (añadiendo variables críticas como head, tail, size, prev e índices).Implementaste la lógica de intercambio seguro (contenido vs. nodos) para evitar corrupciones de memoria.Evolucionaste el parseo de argumentos: concatenación con split, sustitución de atoi por atol para controlar desbordamientos (overflows) y detección estricta de duplicados.Desarrollo y Optimización de Algoritmos:Algoritmo Simple: Tu versión de Bubble Sort fue la que se quedó en el proyecto final por ser más limpia y eficiente (descartando pruebas anteriores).Algoritmo Medio: Desarrollaste e indexaste el Bucket Sort definitivo, gestionando los bloques y el paso eficiente de elementos al stack B usando la raíz cuadrada.Algoritmo Complejo: Implementaste y corregiste los fallos del Radix Sort hasta dejarlo totalmente operativo.Integración, Git Master y Entrega:Realizaste los merges críticos de la rama pat para unificar el trabajo de ambos y resolviste todos los conflictos de código intermedios.Te encargaste de la depuración final de leaks, la creación y mantenimiento del Makefile (integrando libft y ft_printf), y de adaptar todo el código a la Norminette.
 
  Resumen para la Defensa (En pocas palabras)Thia aportó la base matemática (métrica de desorden, raíz cuadrada para buckets), la validación inicial de los inputs y resolvió la difícil lógica de punteros de los movimientos push y reverse rotate.Unai diseñó la arquitectura final de las estructuras de datos, programó los tres algoritmos de ordenación definitivos (simple, buckets y radix), controló exhaustivamente los errores/leaks e integró todo el código bajo los estándares de la Norminette y el Makefile.

## Recursos y Uso de IA

Visualizadores: Uso de herramientas de visualización de push_swap para verificar el comportamiento de los bloques e identificar cuellos de botella en las rotaciones.

Uso de Inteligencia Artificial: La IA fue utilizada como apoyo pedagógico para la comprensión conceptual de algoritmos complejos (Radix Sort LSD), optimización de fórmulas matemáticas y revisión del formato de la documentación.