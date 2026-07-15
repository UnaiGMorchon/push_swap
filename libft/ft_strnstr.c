/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:17:18 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 07:54:08 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i; // Índice para recorrer la cadena principal 'big'
	size_t	j; // Índice para recorrer la subcadena 'little'

// 1. Caso base (aguja vacía)
	// Según el comportamiento de strnstr, si 'little' es una cadena vacía,
	// se retorna inmediatamente la cadena 'big' completa.
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
// 2. Bucle principal
	// Recorremos 'big' mientras no termine y no hayamos superado el límite de caracteres 'len'
	while (big[i] != '\0' && i < len)
	{
		j = 0;
// 3. Bucle de comparación (Buscando la coincidencia)
	// Comparamos los caracteres de 'big' (empezando en i + j) con los de 'little' (en j).
	// Se ejecuta solo si:
	// - No hemos terminado 'big'
	// - No hemos terminado 'little'
	// - Los caracteres coinciden
	// - La posición absoluta dentro de 'big' (i + j) sigue estando dentro del límite 'len'
		while (big[i + j] != '\0'
			&& little[j] != '\0'
			&& big[i + j] == little[j] && (i + j) < len)
		{
			j++; // Avanzamos para comprobar el siguiente carácter del posible acierto
		}
// 4. Comprobación del éxito
	// Si el bucle anterior terminó porque 'little[j]' llegó al final ('\0'),
	// significa que encontramos la palabra completa. Retornamos el puntero al inicio del acierto en 'big'.
		if (little[j] == '\0')
			return ((char *)&big[i]);
// Si no hubo coincidencia completa, avanzamos una posición en 'big' e intentamos de nuevo
		i++;
	}
// 5. Si terminamos de buscar y no encontramos 'little', devolvemos NULL (0)
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello world green";
	char	*rest;

	printf("Find 'world'= ");
// Buscamos "world" en los primeros 11 caracteres de 'str'.
	// "Hello world" mide exactamente 11 caracteres (índices del 0 al 10).
	// Como la 'd' de "world" está en el índice 10, está dentro del rango (< 11), así que lo encuentra.

	rest = ft_strnstr(str, "world", 11);
	if (rest != NULL)
		printf("%s\n", rest); // Imprimirá: "world green"
	else
		printf("%s\n", "NULL\n");
	return (0);
}*/
