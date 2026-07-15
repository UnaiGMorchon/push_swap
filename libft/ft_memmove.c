/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:25:15 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:48:57 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// =========================================================================
// 1. FUNCIÓN AUXILIAR: Copia los bytes evitando destruir datos solapados
// =========================================================================
static void	ft_fill(char *destination, const char *source, size_t n)
{
	size_t	i;

// CASO A: El destino empieza DESPUÉS del origen (Solapamiento crítico)
	// Si copiáramos de izquierda a derecha, escribiríamos sobre datos de 'source' que aún no hemos leído.
	// Solución: Copiamos de derecha a izquierda (desde el final hacia el principio).
	if (destination > source)
	{
		i = n; // Empezamos desde el tamaño total
		while (i > 0)
		{
			i--; // Decrementamos primero para apuntar al índice correcto (de n - 1 hasta 0)
			destination[i] = source[i]; // Copiamos el byte
		}
	}
// CASO B: El destino empieza ANTES del origen (o no hay solapamiento)
	// Aquí es completamente seguro copiar de forma tradicional: de izquierda a derecha (desde el principio al final).
	else
	{
		i = 0;
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
}

// =========================================================================
// 2. FUNCIÓN PRINCIPAL: ft_memmove
// =========================================================================
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destination;
	char	*source;

// 1. Conversión de tipos (Casting)
	// Casteamos los punteros genéricos 'void *' a 'char *' para poder manipularlos byte a byte
	destination = (char *)dest;
	source = (char *)src;
// 2. Casos base de optimización
	// Si el destino y el origen son la misma dirección de memoria, o si nos piden mover 0 bytes,
	// no hay nada que hacer. Retornamos inmediatamente 'dest'.
	if ((destination == source) || n == 0)
		return (dest);
// 3. Llamada a la función de copia inteligente
	ft_fill(destination, source, n);
// 4. Retorno estándar de memmove
	// Según el estándar de C, se debe devolver el puntero original al bloque de destino
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[] = "Hello world";
	char	src[] = "Hi";

// Copia los 2 primeros bytes de src ("Hi") en dest.
	ft_memmove(dest, src, 2);
// Debería imprimir: "Illo world" (reemplaza 'H' y 'e' por 'H' e 'i')
	printf("%s\n", dest);
	return (0);
}*/
