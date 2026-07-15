/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:16:07 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:53:26 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1; // Puntero auxiliar para recorrer s1 byte a byte
	unsigned char	*string2; // Puntero auxiliar para recorrer s2 byte a byte

// 1. Conversión de tipos (Casting)
	// Pasamos los punteros genéricos 'const void *' a 'unsigned char *'.
	// Usamos 'unsigned char' porque el estándar dictamina que las comparaciones de memoria
	// se hacen tratando cada byte como un valor sin signo (de 0 a 255).
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
// 2. Bucle de comparación
	// Se ejecutará como máximo 'n' veces (el número de bytes que nos piden comparar)
	while (n > 0)
	{
		// Si el byte actual de 'string1' es diferente al de 'string2'...
		if (*string1 != *string2)
		{
			// ...retornamos la diferencia de sus valores ASCII/binarios.
			// Al ser 'unsigned char', el resultado de la resta siempre será predecible y correcto
			return (*string1 - *string2);
		}
		// Si eran iguales, avanzamos un byte en ambas zonas de memoria
		string1++;
		string2++;
		n--; // Decrementamos el contador de bytes restantes
	}
// 3. Si el bucle termina y no encontró diferencias, los primeros 'n' bytes son idénticos
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "hallo world";
	char	s2[] = "hb";

// Analiza los primeros 5 bytes. 
	// En el índice 0, ambos tienen 'h'.
	// En el índice 1, s1 tiene 'a' (ASCII 97) y s2 tiene 'b' (ASCII 98).
	// Al ser diferentes, se rompe el bucle y resta: 97 - 98 = -1.
	printf("%d\n", ft_memcmp(s1, s2, 5));
	return (0);
}*/
