*Este proyecto ha sido creado como parte del currículo de 42 por ugarcia-*

# LIBFT

## Descripción
El proyecto consiste en crear una librería en C que contendrá una serie de funciones. Este proyecto tiene como objetivo ayudarme a comprender cómo actuán
estas funciones, implementarlas por mi cuenta y aprender a utilizarlas de forma eficaz.

## FUNCIONES DE LIBC

### `isalpha`
La función isalpha comprueba si un carácter específico es una letra del alfabeto (ya sea mayúscula o minúscula).

Valores de retorno:
* Distinto de 0 (Verdadero): Si el carácter es una letra.
* 0 (Falso): Si el carácter no es una letra (por ejemplo, si es un '5', un '$' o un salto de línea).

### `isdigit`
La función isdigit comprueba si un carácter específico es dígito decimal (del '0' al '9').

Valores de retorno:
* Distinto de 0 (Verdadero): Si el carácter es un número (del '0' al '9')
* 0 (Falso): Si el carácter no es un número (por ejemplo, si es una letra 'A', un símbolo '$' o un espacio).

### `isalnum`
La función isalnum comprueba si el carácter es una letra (A-Z, a-z) o un número (0-9).

Valores de retorno:
* Distinto de 0 (Verdadero): Si el carácter es alfanumérico (letras o dígitos).
* 0 (Falso): Si el carácter es cualquier otra cosa (espacios, signos de puntuación, símbolos matemáticos, etc.)

### `isascii`
La función isascii comprueba si el valor se encuentra en la tabla ascii.

Valores de retorno:
* Distinto de 0 (Verdadero): Si el valor está entre 0 y 127.
* 0 (Falso): Si el valor es mayor a 127 o negativo.

### `isprint`
La función isprint comprueba si el carácter C es un carácter imprimible, incluyendo el espacio en blanco.

Valores de retorno:
* Distinto de 0 (Verdadero): Si el valor de c está entre 32 y 126 inclusive.

* 0 (Falso): Si el valor no es imprimible (caracteres de control del 0 al 31, y el 127).

### `strlen`
La función strlen calcula la longitud de la cadena de caracteres apuntada por s, sin incluir el carácter nulo terminador ('\0').

Valores de retorno:
* Número de caracteres: Devuelve el total de bytes/caracteres que hay desde el inicio hasta encontrar el primer nulo.

### `memset`
La función memset copia el caracter c(convertido en un unsigned char) en determinados len bytes en el string b.

### `bzero`
La función bzero coloca n bytes de ceros en la cadena s. Si n es 0, no hace nada.

Valores de retorno:
* Ninguno (void): A diferencia de memset, esta función no devuelve un puntero.

### `memcpy`
La función memcpy copia n bytes desde el área de memoria de src al área de memoria de dest. Las áreas de memoria no deben solaparse.

Valores de retorno:
* dest: Devuelve un puntero original al área de destino.

### `memmove`
La función memmove copia len bytes desde el área de memoria src al área de memoria dst.

Valores de retorno:
* dest: Devuelve un puntero al área de destino.

### `strlcpy`
La función strlcpy copia hasta size - 1 caracteres de la cadena src a dest, asegurando que el resultado final esté terminado en nulo, siempre que size sea mayor que 0.

Valores de retorno:
* La longitud de src: Devuelve el tamaño total de la cadena que intentó crear. Esto es útil para saber si la cadena fue truncada (si el valor devuelto es mayor o igual a size). Retorna el tamaño de la string.

### `strlcat`
La función strlcat concatena la cadena src al final de dst. Concatena strings con una longitud limitada y lo termina en NULL siempre que el size sea mayor a el string original de dst. Retorna la longitud del string que esta tratando crear (siempre que haya espacio disponible).

Valores de retorno:
* Longitud total que intentó crear: Es decir, la longitud inicial de dst más la longitud de src.

Caso especial: Si size es menor o igual a la longitud de dest, devuelve size + strlen(src).

### `toupper`
La función toupper convierte una letra minúscula a su correspondiente mayúscula. Si el carácter pasado no es una letra minúscula, la función lo devuelve sin cambios.

Valores de retorno:
* El carácter convertido: Si C era una minúscula ('a' - 'z').

* El carácter original: Si C ya era mayúscula, un número, un símbolo o cualquier otro valor.

### `tolower`
La función tolower convierte una letra mayúscula a su correspondiente minúscula. Si el carácter pasado no es una letra mayúscula, la función lo devuelve sin cambios.

Valores de retorno:
* El carácter convertido: Si C era una mayúscula ('A' - 'Z').

* El carácter original: Si C no era una letra mayúscula.

### `strchr`
La función strchr busca la primera aparición del carácter C (convertido a char) en la cadena apuntada por s.

Valores de retorno:
* Puntero al carácter: Devuelve un puntero a la posición exacta donde se encontró el carácter por primera vez.

* NULL: Si el carácter no aparece en la cadena.

### `strrchr`
La función strrchr busca la última aparición del carácter C (convertido a nsigned char) en la cadena S. Al igual que su hermana strchr, el carácter nulo terminador (\0) se considera parte de la cadena.

Valores de retorno:
* Puntero a la última aparición: Un puntero a la posición del carácter.

* NULL: Si el carácter no se encuentra en la cadena.

### `strncmp`
La función strncmp compara las cadenas s1 y s2 hasta un máximo de n caracteres. La comparación se detiene si se encuentra un carácter nulo (\0) en cualquiera de las cadenas o si se alcanza el límite n.

Valores de retorno:
* 0: Si las cadenas son idénticas hasta el carácter n o hasta el final de las mismas.

* Positivo (> 0): Si el valor ASCII del primer carácter diferente es mayor en s1.

* Negativo (< 0): Si el valor ASCII del primer carácter diferente es menor en s1.

### `memchr`
La función memchr escanea los primeros n bytes del área de memoria apuntada por s en busca de la primera aparición del carácter C (convertido a unsigned char). Tanto el área de memoria como el carácter se interpretan como unsigned char.

Valores de retorno:
* Puntero al byte: Devuelve un puntero a la ubicación de la primera coincidencia.

* NULL: Si el carácter no se encuentra dentro de los primeros n bytes.

### `memcmp`
La función memcmp compara los primeros n bytes de las áreas de memoria s1 y s2. Ambos bloques se interpretan como unsigned char, lo que permite comparar cualquier tipo de dato (estructuras, imágenes, arrays de enteros, etc.).

Valores de retorno:
* 0: Si los primeros n bytes de ambos bloques son idénticos.

* Diferencia (s1 - s2): Devuelve la diferencia entre los primeros dos bytes que difieren.

* Positivo: Si el primer byte diferente es mayor en s1.

* Negativo: Si el primer byte diferente es mayor en s2.

### `strnstr`
La función strnstr localiza la primera aparición de la cadena needle (terminada en nulo) dentro de la cadena haystack, buscando no más de len caracteres. Los caracteres que aparecen después de un \0 no se buscan.

Valores de retorno:
* haystack: Si needle es una cadena vacía.

* NULL: Si needle no aparece en los primeros len caracteres de haystack.

* Puntero: Un puntero al primer carácter de la primera aparición de needle.

### `atoi`
La función atoi convierte la porción inicial de la cadena apuntada por str en una representación de tipo int.

Pasos que sigue la función:

Espacios: Salta todos los caracteres de "espacio en blanco" (espacios, tabuladores, saltos de línea, etc.).

Signo: Acepta un único signo opcional (+ o -).

Conversión: Lee los caracteres numéricos y los convierte en el valor entero correspondiente.

Parada: Se detiene en cuanto encuentra el primer carácter que no sea un número.

Valores de retorno:
* El número convertido: El valor entero resultante.

* 0: Si no hay una conversión válida posible.

### `calloc`
La función calloc se utiliza para reservar un bloque de memoria dinámica.

Inicialización a cero: Limpia la memoria reservada, poniendo todos los bits a 0.

Valores de retorno:
* Éxito: Devuelve un puntero al bloque de memoria reservada.

* Fallo: Devuelve NULL (si no hay memoria suficiente o si hay un desbordamiento en el cálculo).

### `strdup`
La función strdup retorna un puntero a la nueva string que es un duplicado de s1. La memoria para la nueva string se reserva con malloc y puede ser liberada con free. Retorna NULL si no hay suficiente memoria.

## FUNCIONES ADICIONALES

### `substr`
La función substr crea una nueva cadena (reservada con malloc) que es una porción de la cadena original s.

Valores de retorno:
* Éxito: Un puntero a la nueva cadena "cortada".

* Fallo: Devuelve NULL si el malloc falla.

### `strjoin`
la función reserva (con malloc(3)) y devuelve una nueva string, formada por la concatenación de ’s1’ y ’s2’.

Valores de retorno:
* El nuevo string: Un puntero al bloque de memoria que contiene la frase unida.

* NULL: Si la reserva de memoria con malloc falla o si las cadenas de entrada no son válidas.

### `strtrim`
Esta función elimina todos los caracteres de la string set desde el principio y desde el final de s1, hasta encontrar un carácter n perteneciente a set. La string resultante se devuelve con una reserva de malloc.

Valores de retorno:
* La string recortada: Un puntero a la nueva cadena limpia.

* NULL: Si la reserva de memoria con malloc falla o si s1 no existe.

* String vacía: Si todos los caracteres de s1 pertenecen a set, devuelve una cadena vacía reservada con malloc.

### `split`
La función split fragmenta una cadena de texto s en varias subcadenas, utilizando un carácter c como punto de corte, y las almacena en un array de strings.

Valores de retorno:
* El array de nuevas strings: Un puntero doble (char ) que contiene las direcciones de todas las subcadenas creadas.

* NULL: Si la reserva de memoria falla en cualquier punto o si la cadena s no existe.

### `itoa`
La función itoa (Integer to ASCII) convierte un número entero con signo (int) en una cadena de caracteres que lo represente.

Valores de retorno:
* La string numérica: Un puntero a la cadena que representa el entero.

* NULL: Si la reserva de memoria con malloc falla.

### `strmapi`
La función strmapi aplica una función de transformación a cada carácter de una cadena s, teniendo en cuenta su posición (índice), para crear una nueva cadena resultante.

Valores de retorno:
* La nueva string: Un puntero a la cadena creada con las transformaciones aplicadas.

* NULL: Si la reserva de memoria falla o si s o f son inexistentes.

### `striteri`
La función striteri recorre una cadena de caracteres y aplica una función f sobre cada uno de ellos. Al pasar la dirección del carácter, permite que la función f modifique la cadena original directamente.

Valores de retorno:
* Ninguno (void): La función no devuelve nada, ya que su objetivo es producir efectos secundarios directamente sobre la cadena recibida.

### `putchar_fd`
La función putchar_fd escribe un único carácter en un flujo de salida determinado por un descriptor de archivo (file descriptor).

Valores de retorno:
* Ninguno (void): La función simplemente ejecuta la acción de escritura.

### `putstr_fd`
La función putstr_fd escribe una cadena de caracteres completa en el descriptor de archivo (file descriptor) especificado.

Valores de retorno:
* Ninguno (void): Su única misión es realizar la operación de salida.

### `putendl_fd`
La función putendl_fd escribe una cadena de caracteres en el descriptor de archivo especificado, añadiendo un carácter de salto de línea ('\n') al final de la operación.

Valores de retorno:
* Ninguno (void): Realiza la escritura y finaliza.

### `putnbr_fd`
La función putnbr_fd convierte un número entero n en caracteres imprimibles y los envía al descriptor de archivo especificado.

Valores de retorno:
* Ninguno (void): La función realiza la conversión y la salida directamente.


## LISTAS ENLAZADAS

### `lstnew`
La función lstnew reserva memoria para un nuevo nodo de una lista enlazada y asigna el contenido proporcionado.

Valores de retorno:
* El nuevo nodo: Un puntero a la estructura t_list recién creada.

* NULL: Si la reserva de memoria con malloc falla.

### `lstadd_front`
La función lstadd_front añade un nodo al inicio de una lista enlazada existente, actualizando el puntero de la cabeza de la lista.

Valores de retorno:
* Ninguno (void): La función modifica la lista directamente a través del puntero doble.

### `lstsize`
La función lstsize cuenta el número de elementos (nodos) que componen una lista enlazada.

Valores de retorno:
* La longitud de la lista: Un entero que representa el número total de nodos. Si la lista está vacía, devuelve 0.

### `lstlast`
La función lstlast recorre la lista completa para localizar y devolver el último nodo (aquel cuyo puntero next es NULL).

Valores de retorno:
* El último nodo: Un puntero al último elemento de la estructura t_list.

* NULL: Si la lista recibida originalmente estaba vacía.

### `lstadd_back`
La función lstadd_back añade un nuevo nodo al final de una lista enlazada, conectándolo con el que hasta ese momento era el último elemento.

Valores de retorno:
* Ninguno (void): Modifica la estructura de la lista original.

### `lstdelone`
La función lstdelone libera la memoria de un nodo individual. Utiliza una función auxiliar para limpiar el contenido y luego libera la estructura del nodo en sí.

Valores de retorno:
* Ninguno (void): Su función es exclusivamente la liberación de memoria.

### `lstclear`
La función lstclear elimina y libera el nodo y todos los consecutivos utilizando la función del y free.

Valores de retorno:
* Ninguno (void): Su objetivo es la limpieza total de la memoria.

### `lstiter`
La función lstiter itera la lista y aplica la función f en el contenido de cada nodo.

Valores de retorno:
* Ninguno (void): La función no devuelve nada, solo ejecuta la función f sobre los datos.

### `lstmap`
La función lstmap crea una nueva lista resultado de aplicar la función f al contenido de cada nodo de la lista original. Si algo falla durante el proceso (como un error de memoria), debe ser capaz de limpiar todo lo que haya creado hasta ese momento.

Valores de retorno:
* La nueva lista: Una copia transformada de la original.

* NULL: Si falla cualquier reserva de memoria.


## INSTRUCCIONES

---

## 1. Instalación y preparación

```bash
git clone git@vogsphere.42urduliz.com:vogsphere/intra-uuid-fd7cdb2a-ecb6-4a4d-9ed2-09dba63433c4-7378236-ugarcia-

cd libft
```
---

## 2. Compilación (Makefile)

Utiliza el `Makefile` incluido para gestionar la compilación de forma sencilla:

| Comando | Descripción |
| --- | --- |
| `make` | Compila las funciones obligatorias y genera `libft.a`. |
| `make bonus` | Compila e incluye las funciones de **listas enlazadas**. |
| `make clean` | Elimina los archivos objeto (`.o`). |
| `make fclean` | Elimina objetos y el archivo de librería `libft.a`. |
| `make re` | Recompila todo el proyecto desde cero. |

---

## 3. Integración en tus Proyectos

### En el código fuente

Incluye el encabezado en tus archivos `.c`:

```c
#include "libft.h"
```

### Al compilar

Indica al compilador dónde está la librería y su nombre:

```bash
gcc main.c -L. -lft -o programa
```

> **Nota:** `-L.` indica que la librería está en el directorio actual y `-lft` busca el archivo `libft.a`.

---

## Recursos
* **Stack Overflow**: Resolución de dudas sobre punteros y gestión de memoria.
* **Documentación de C**: Consulta de librerías estándar (`stdio.h`, `stdlib.h`, `string.h`).
* **Compañeros de clase**: Debate sobre la lógica de algoritmos y depuración de código.
* **GeeksforGeeks**: Guías sobre estructuras de datos y algoritmos en C.
* **Python tutor**: para probar el código y ver su recorrido.

## Uso de IA
* **Herramientas**: [Gemini]
* **Uso específico**: 
    - Explicación de errores de compilación y *segmentation faults*.
    - Redacción de comentarios.
    - Ayuda al crear el readme.md.