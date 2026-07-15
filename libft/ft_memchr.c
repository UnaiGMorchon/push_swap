/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:23:11 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:56:04 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	character; // Variable para almacenar el byte buscado tras el casteo
	size_t			i; // Contador para controlar el límite de bytes 'n'
	unsigned char	*source;    // Puntero auxiliar para leer la memoria byte a byte

// 1. Conversión de tipos (Casting)
	// Casteamos el puntero genérico 'const void *s' a 'unsigned char *' para poder
	// movernos e inspeccionar la memoria posición por posición (1 byte por cada unsigned char).
	source = (unsigned char *)s;
// El entero 'c' lo transformamos en 'unsigned char' para asegurarnos de que la
	// comparación se haga usando exactamente 1 byte sin signo.
	character = (unsigned char)c;
	i = 0;
// 2. Bucle de búsqueda limitada por 'n'
	// Recorremos la memoria mientras no hayamos alcanzado el número máximo de bytes a escanear.
	while (i < n)
	{
		// Si el byte en la posición actual coincide con el que estamos buscando...
		if (source[i] == character)
			// ...retornamos la dirección de memoria exacta de esa posición casteada automáticamente a (void *)
			return (&source[i]);
		i++; // Avanzamos al siguiente byte
	}
// 3. Si terminamos de revisar los 'n' bytes y no encontramos nada, devolvemos NULL (0)
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "Hello world";

// Busca la 'H' dentro de los primeros 5 bytes. 
	// Como la 'H' está justo al principio (índice 0), la encuentra de inmediato.

	// Imprime la dirección de memoria en formato hexadecimal (ej. 0x7ffee3bc4a80)
	printf("%p\n", ft_memchr(s, 'H', 5));
// Casteamos el resultado a (char *) para imprimir la cadena desde esa posición en adelante.
	// Debería imprimir: "Hello world"
	printf("%s", (char *)ft_memchr(s, 'H', 5));
	return (0);
}
*/
