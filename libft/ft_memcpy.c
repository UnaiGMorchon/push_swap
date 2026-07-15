/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:57:43 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:51:25 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*source; // Puntero auxiliar para leer 'src' byte a byte
	size_t		i; // Contador de bytes copiados
	char		*destination; // Puntero auxiliar para escribir en 'dest' byte a byte

// 1. Conversión de tipos (Casting)
	// Pasamos los punteros genéricos 'void *' a punteros de tipo carácter ('char *')
	// para poder operar con ellos índice por índice (ya que 1 char = 1 byte).
	destination = (char *)dest;
	source = (const char *)src;
	i = 0;
// 2. Protección especial contra doble puntero nulo
	// Si tanto el destino como el origen son NULL, no hay nada que copiar ni donde hacerlo.
	// Según el estándar oficial de C, en este caso específico se retorna NULL.
	if (destination == NULL && source == NULL)
		return (NULL);
// 3. Bucle de copia tradicional (De izquierda a derecha)
	// Copiamos a ciegas exactamente 'n' bytes desde el origen al destino
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
// 4. Retorno estándar de memcpy
	// Devolvemos el puntero original 'dest' recibido por parámetr
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "hello world";
	char	dest_main[] = "hello";

// OJO CON ESTE MAIN EN UN CASO REAL:
	// Estás intentando copiar 10 bytes de 'src' dentro de 'dest_main'.
	// Sin embargo, 'dest_main' se inicializó con "hello", lo que significa que su array
	// solo tiene espacio para 6 bytes (h, e, l, l, o, \0).
	// Copiar 10 bytes aquí causará un desbordamiento de búfer (Buffer Overflow),
	// lo cual puede corromper la memoria del programa.
	ft_memcpy(dest_main, src, 10);
	printf("%s\n", dest_main);
	return (0);
}*/
