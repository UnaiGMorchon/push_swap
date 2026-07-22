*Este proyecto ha sido creado como parte del currículo de 42 por patperez, ugarcia-*

# Push_swap

## Descripción

**Push_swap** es un proyecto de desarrollo de algoritmos en C cuyo objetivo es ordenar un conjunto de datos numéricos en un stack (Pila A) utilizando un stack auxiliar (Pila B) y un conjunto limitado de operaciones. 

El reto del proyecto radica en la **optimización**: el programa debe calcular y mostrar por la salida estándar la secuencia de instrucciones más corta posible. La eficiencia de las soluciones se evalúa directamente según el número de operaciones generadas.

### Operaciones disponibles:

* `sa` / `sb` / `ss`: Intercambia (*swap*) los dos primeros elementos de un stack.
* `pa` / `pb`: Toma el primer elemento de un stack y lo pone (*push*) en el otro.
* `ra` / `rb` / `rr`: Desplaza hacia arriba todos los elementos (*rotate*). El primero pasa a ser el último.
* `rra` / `rrb` / `rrr`: Desplaza hacia abajo todos los elementos (*reverse rotate*). El último pasa a ser el primero.

---

## Instrucciones de Uso

### Compilación
El repositorio del proyecto se ha de clonar desde: 
```bash
git clone git@vogsphere.42urduliz.com:vogsphere/intra-uuid-4c292cfa-5a43-4f28-b01e-dce9e9ca4818-7462062-ugarcia- push_swap
```
El proyecto incluye un `Makefile` que compila el código fuente sin hacer *relink*. Los comandos disponibles son:

```bash
make          # Compila el programa push_swap
make clean    # Elimina los archivos objeto (.o)
make fclean   # Elimina los objetos y los archivos ejecutables
make re       # Limpia y vuelve a compilar todo
```

### Ejecución
El programa acepta una lista de enteros como argumento y flags opcionales para forzar la estrategia de ordenación.

### Ejecución por defecto (Estrategia Adaptativa)
```bash
./push_swap 2 1 3 6 5 8
```
La ejecución por defecto recurre a la estrategia adaptativa para el ordenamiento de acuerdo al desorden del input.

### Flags Opcionales:
El programa permite forzar una estrategia de ordenación específica y medir su rendimiento de acuerdo a las flags introducidas. El programa emplea dos tipos de flags: una para selección de estrategia y otra para medición del rendimiento. Se pueden incluir ambas, una, o ninguna.

### Flags de selección de estrategia:
```bash
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 6 3 87 23
```

### Modo Benchmark:
Si se introduce la flag opcional `--bench` , el programa redirige a la salida de error estándar (stderr) un desglose detallado del rendimiento:

```bash
./push_swap --bench 4 67 3 87 23
```

Ejemplo del uso de ambas:
```bash
./push_swap --bench --complex 4 67 3 87 23
```

## Manejo de Errores

El programa gestiona y muestra `Error\n` en la salida de errores (stderr) si detecta:

- Argumentos que contengan caracteres no numéricos.

- Números que superen los límites de un entero de 32 bits (INT_MAX o INT_MIN).

- Números duplicados en los parámetros de entrada.

## Algoritmos:
Para optimizar la eficiencia según el volumen y estado de los datos, el programa integra cuatro estrategias:

## Algoritmo Simple: Adaptación de Bubble Sort (O(n²))

### Operación y justificación:
El algoritmo utiliza la lógica clásica de ordenamiento por burbuja adaptada a la estructura cíclica de un Stack, usando únicamente las operaciones `ft_sa` y `ft_ra`. Decidimos la implementación de este algoritmo por su claridad y simplicidad. Al regirse exclusivamente por dos operaciones, su ejecución se ajusta a lo que buscabamos como representación de un algoritmo que fuese eficiente a pesar de su carencia en optimización.

---

### Puntos Clave del Funcionamiento

* **Bucle de Control (`swapped`):** El algoritmo se repite continuamente en un bucle principal mientras se sigan detectando y ejecutando intercambios de posición.
* **Comparación y Permutación (`ft_sa`):** En cada paso, comprueba si el elemento en la cima (`head`) es mayor que el que le sigue (`head->next`). Si están desordenados, los intercambia.
* **Desplazamiento Cíclico (`ft_ra`):** Después de cada verificación (hayan cambiado o no), el stack rota hacia arriba para posicionar el siguiente par de elementos en la cima y poder compararlos.
* **Corrección de Alineación:** Al terminar cada pasada completa por el stack, se aplica una rotación extra (`ft_ra`) para reajustar la alineación del stack circular antes de iniciar la siguiente vuelta.

## Algoritmo Intermedio: Adaptación de Chunk-based / Bucket Sort ($O(n\sqrt{n})$)

### Operación y justificación:
El algoritmo optimiza el número de movimientos dividiendo el problema en bloques (*chunks* / *buckets*). Asigna a cada número una posición relativa de $0$ a $n-1$ y define un rango de bloque dinámico basado en la raíz cuadrada del total de elementos ($\sqrt{n}$). La selección de este algoritmo se basa en su optimizacioń. Al abordar la pila en partes, se permite un mayor control del proceso de ordenamiento, reduciendo el número de operaciones redundantes, y mejorando así su optimización.

* **Nota de Arquitectura:** En lugar de buscar una posición exacta en cada pasada, traslada a la **Pila B** cualquier elemento que pertenezca al bloque actual. Al vaciar la Pila A por bloques, el retorno desde B hacia A se realiza devolviendo siempre el elemento máximo disponible, reduciendo drásticamente las rotaciones.

---

### Puntos Clave del Funcionamiento

* **Pre-indexación (`ft_get_index`):** Normaliza los datos originales asignando a cada nodo un índice de $0$ a $n-1$ según su valor. Esto permite trabajar con rangos continuos gracias a estos índices, independientemente de los valores reales.
* **Cálculo de Bloques (`ft_sqroot`):** Establece la dimensión del *bucket* inicial como $\sqrt{\text{tamaño}}$ y define el límite superior (`number_limit`) de los elementos permitidos en la Pila B en cada etapa.
* **Vaciado a Pila B (`ft_exist_bucket`):**
  * Si el elemento en la cima de A (`head->index`) entra dentro del límite actual, se envía a B con `ft_pb`.
  * Si no está en la cima, pero aún quedan elementos dentro del rango en la Pila A, se rota con `ft_ra` para buscarlo.
  * Si ya no quedan elementos dentro del rango actual, se incrementa el límite (`number_limit += end_bucket`) para abrir el siguiente bloque.
* **Reintegración Optimizada a Pila A (`ft_rotate_decide`):**
  * Localiza la dirección del elemento con el índice más alto en B con `ft_max_index`.
  * Calcula si el elemento objetivo está en la mitad superior o inferior del stack.
  * Selecciona el camino más corto: rota hacia arriba (`ft_rb`) o rotación inversa hacia abajo (`ft_rrb`).
  * Al llegar a la cima, lo devuelve a A mediante `ft_pa`, dejando la Pila A ordenada de forma ascendente.


## Algoritmo Complejo: Adaptación de Radix Sort (LSB) (O(n log n))

### Operación y justificación:
Aprovecha la representación binaria de los índices previamente simplificados (de $0$ a $n-1$). Evalúa el stack bit a bit, desde el **Bit Menos Significativo (LSB)** hasta el **Bit Más Significativo (MSB)**. La elección de este algoritmo se basa en su eficiencia. Al emplear los bits para su ordenamiento el lugar del entero en sí, evitamos movimientos redundantes e incrementamos la velocidad de ejecución.

* **Nota de Arquitectura:** Al trabajar directamente sobre la propiedad `index` de los nodos en lugar de sus valores originales, el algoritmo normaliza la entrada. No realiza comparaciones directas entre valores (`<` o `>`), basándose puramente en operaciones bit a bit sobre dicho índice, lo que elimina los casos de peor rendimiento.

---

### Puntos Clave del Funcionamiento

* **Pre-indexación (`ft_get_index`):** Normaliza los datos originales asignando a cada nodo un índice de $0$ a $n-1$ según su valor. Esto permite trabajar con rangos continuos gracias a estos índices relativos al valor binario.
* **Cálculo de Pasadas (`ft_get_max_bits`):** Determina el número exacto de bits necesarios para representar el índice más alto ($\text{size} - 1$), marcando el total de iteraciones principales del algoritmo.
* **Evaluación Bit a Bit:** Un bucle principal procesa el bit $i$ en cada ciclo (empezando en $i = 0$). Determina la acción a realizar de acuerdo al bit (1 o 0).
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
| **Bajo** | `desorden < 0.2` | [Bubble Sort] | $O(n)$ |
| **Medio** | `0.2 ≤ desorden < 0.5` | [Chunks / Bucket Sort] | $O(n\sqrt{n})$ |
| **Alto** | `desorden ≥ 0.5` | [Radix Sort] | $O(n \log n)$ |

Ejemplo de justificación de Umbrales: Cuando el desorden es menor a 0.2, el stack está "casi ordenado", por lo que un enfoque de pasadas lineales (O(n)) con swaps localizados resuelve el problema con un número mínimo de operaciones, evitando el coste de mover bloques enteros a la pila B de forma innecesaria.

## Contribuciones y Trabajo en Equipo

A la hora de abordar este proyecto, inicialmente distribuímos el trabajo entre ambos, pero al avanzar tras la realización de nuestros primeros pasos,  llegamos a la conclusión de que nuestro planteamiento y nuestra estructura inicial respecto al funcionamiento del programa era errónea. Hubo que reiniciar el proyecto, paso que dimos intercambiando trabajo para que los dos comprendiesemos los pasos que dabamos.

A partir de este punto, unificamos nuestras tareas: puesto que todas las piezas de este proyecto están conectadas, encontramos más eficiente y productivo trabajar juntos en todos los pasos, tanto para el entendimiento de cada parte del proceso, como para el progreso seguro del proyecto. Distribuímos ciertas tareas, pero el proceso de brainstorming inicial, depuración, y corrección se realizó en conjunto.

Dicho esto, hay ciertas áreas del proyecto en las que cada estudiante realizó aportes más significativas:

### patperez: 
* Investigación y desarrollo del esqueleto inicial de algoritmos.
* Mapeo del orden secuencial del funcionamiento del programa.
* Búsqueda de errores en el flujo secuencial.
* Integración del "Modo Benchmark" y cálculo del desorden para su implementación adaptativa.
* Estudio de fugas de memoria y su corrección.

### ugarcia-: 
* Optimización de algoritmos para su correcto funcionamiento.
* Reconstrucción de la estructura inicial e incorporación de elementos clave para el funcionamiento de las mismas.
* Resolución de la óptima integración del input para la correcta entrada y parseo de argumentos.
* Gestión e investigación del óptimo funcionamiento de repositorios para la distribución de trabajo.
* Tester del flujo del programa.
* Desarrollo de Makefile.


## Recursos y Uso de IA

Visualizador del programa:
* https://codepen.io/ahkoh/full/bGWxmVz

Documentación:
* https://en.wikipedia.org/wiki/Analysis_of_algorithms
* https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
* https://www.swhosting.com/es/comunidad/manual/algoritmos-de-ordenacion-con-ejemplos-en-c
* https://www.geeksforgeeks.org/dsa/sorting-algorithms/
* https://en.wikipedia.org/wiki/Big_O_notation
* https://www.geeksforgeeks.org/dsa/analysis-algorithms-big-o-analysis/
* https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/
* https://www.programiz.com/dsa/bubble-sort
* https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81
* https://www.geeksforgeeks.org/dsa/bucket-sort-2/
* https://www.cs.upc.edu/~conrado/research/talks/dmd06.pdf
* https://www.programiz.com/dsa/bucket-sort
* https://www.programiz.com/dsa/radix-sort
* https://www.geeksforgeeks.org/c/c-program-for-radix-sort/
* https://www.learn-c.org/en/Linked_lists
* https://medium.com/@Dev_Frank/c-linked-list-singly-linked-list-12aecb168834

Peer-to-Peer:
El apoyo entre compañeros, incluídos mentores y senseis, contribuyó en la realización de este proyecto a través del intercambio de ideas y la discusión y comprensión de errores. Entre ellos, los mentores fueron un gran apoyo a la hora de resolver bloqueos en puntos críticos del progreso del proyecto. Los contribuyentes más notables fueron:
* omarquez
* khurtado
* aunoguei (mentora)
* alejanr2 (mentor/sensei)

Uso de Inteligencia Artificial:
* Explicación de mensajes de error en fugas de memoria.
* Apoyo en la comprensión del orden secuencial en funciones específicas.
* Apoyo en la comprensión de los algoritmos.
* Creación de un esquema de organización para el presente `readme.md`.