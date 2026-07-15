*Este proyecto ha sido creado como parte del currículo de 42 por ugarcia-*

# ft_printf

## Descripción

El proyecto `ft_printf` consiste en reprogramar la función `printf()` de la librería estándar de C (`libc`).

El objetivo principal es comprender cómo funcionan las funciones variádicas en C, el manejo de argumentos de tamaño variable y la conversión de diferentes tipos de datos a texto utilizando únicamente funciones autorizadas.

La función desarrollada, `ft_printf()`, imita el comportamiento del `printf` original para las conversiones obligatorias:

- `%c` → carácter
- `%s` → string
- `%p` → puntero hexadecimal
- `%d` → decimal con signo
- `%i` → entero decimal
- `%u` → decimal sin signo
- `%x` → hexadecimal minúscula
- `%X` → hexadecimal mayúscula
- `%%` → símbolo `%`


---

# Objetivos del proyecto

- Reimplementar `printf()` sin usar la versión original de la libc.
- Aprender el funcionamiento de las funciones variádicas.
- Crear una librería estática usando `ar`.
- Escribir código modular y fácilmente extensible.
- Gestionar correctamente diferentes tipos de conversiones.

---

# Instrucciones

## Compilación

Para compilar la librería:

```bash
make
```

Esto generará:

```bash
libftprintf.a
```

## Reglas disponibles

```bash
make        # Compila la librería
make clean  # Elimina archivos objeto
make fclean # Elimina archivos objeto y librería
make re     # Recompila todo
```

---

# Uso

## Prototipo

```c
int ft_printf(char const *format, ...);
```

## Ejemplo

```c
#include "printf.h"

int main(void)
{
    ft_printf("hello %s\n", "word");
    ft_printf("number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    return (0);
}
```

## Compilar con la librería

```bash
cc main.c -L. -lftprintf -o program
```

> **Nota:** `-L.` indica que la librería está en el directorio actual y `-lftprintf` busca el archivo `libftprintf.a`.

---

# Estructura del proyecto

```bash
.
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_putchar.c
├── ft_putstr.c
├── ft_putnbr.c
├── ft_putnbr_unsigned.c
├── ft_putnbr_hexa_min.c
├── ft_putnbr_hexa_may.c
└── ft_put_void.c
```

---

# Algoritmo y estructura utilizada

## Diseño general

La implementación se basa en una función principal `ft_printf()` que recorre el string de formato carácter por carácter.

Cuando encuentra un `%`, analiza el siguiente carácter para determinar el tipo de conversión y llama a una función específica encargada de imprimir ese tipo de dato.

Ejemplo:

```c
if (format[i] == '%' && format[i + 1] == 'd')
    count += ft_putnbr(va_arg(args, int));
```

---

## Uso de funciones variádicas

Se utilizan las macros de `<stdarg.h>`:

```c
va_start
va_arg
va_copy
va_end
```

Estas permiten acceder a un número variable de argumentos enviados a la función.

---

## Conversión de números

Para imprimir números se utiliza principalmente recursividad.

Por ejemplo:
- División entre 10 para decimales
- División entre 16 para hexadecimales

Esto permite imprimir los números dígito a dígito sin necesidad de buffers complejos.

Ejemplo simplificado:

```c
if (n >= 10)
    ft_putnbr(n / 10);
ft_putchar((n % 10) + '0');
```

---

## Gestión de punteros

Los punteros `%p` se imprimen:
1. Añadiendo el prefijo `0x`
2. Convirtiendo la dirección a hexadecimal

---

## Contador de caracteres

Cada función devuelve el número de caracteres impresos.

La función principal suma todos los caracteres para devolver exactamente el mismo comportamiento que `printf()` original.

---

# Decisiones técnicas

## Modularidad

Cada tipo de conversión se implementa en archivos separados para facilitar el mantenimiento y depuración del proyecto.

## Recursividad

Se eligió recursividad para:
- Simplificar conversión numérica
- Reducir complejidad del código
- Evitar buffers adicionales

## Uso exclusivo de `write`

Toda la salida se realiza usando:

```c
write()
```

para respetar las restricciones del proyecto.

---

# Funciones autorizadas

- `malloc`
- `free`
- `write`
- `va_start`
- `va_arg`
- `va_copy`
- `va_end`

---

# Recursos

## Documentación oficial

- Manual de printf:
  https://man7.org/linux/man-pages/man3/printf.3.html

- Documentación de stdarg:
  https://man7.org/linux/man-pages/man3/stdarg.3.html

- Referencia de funciones variádicas:
  https://cplusplus.com/reference/cstdarg/

---

# Recursos de aprendizaje

- GeeksForGeeks - Variadic Functions in C:
  https://www.geeksforgeeks.org/variadic-functions-in-c/

- Tutorial sobre hexadecimal:
  https://www.programiz.com/c-programming/c-data-types

- Explicación de recursividad:
  https://www.geeksforgeeks.org/c-recursion/

---

# Uso de IA

Se ha utilizado IA como herramienta de apoyo para:

- Explicación de errores de compilación y *segmentation faults*.
- Redacción de comentarios.
- Ayuda al crear el readme.md.

---

# Características principales

- Implementación modular
- Compatible con conversiones obligatorias
- Manejo de enteros negativos
- Conversión hexadecimal
- Gestión de punteros
- Retorno correcto del número de caracteres impresos

---

# Limitaciones

Esta implementación:
- No gestiona flags avanzados (`-`, `0`, `+`, etc.)
- No incluye gestión de precisión o width
- No implementa buffer interno como `printf` original

---

# Conclusión

`ft_printf` es un proyecto fundamental para comprender:
- Bajo nivel en C
- Variadic functions
- Conversión de tipos
- Diseño modular
- Gestión de memoria y escritura

Además, sirve como base para futuros proyectos más complejos dentro del currículo de 42.
