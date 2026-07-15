/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 09:39:06 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:30:33 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	long int	size_total; // Variable para almacenar el tamaño total
	size_t		i; // Contador para inicializar la memoria
	char		*ptr; // Puntero auxiliar byte a byte (char *)

// 1. PROTECCIÓN CONTRA DESBORDAMIENTO (Overflow)
	// Esta condición es excelente. Comprueba si 'nmemb' y 'size' son tan grandes
	// que al multiplicarlos superarían el valor máximo que puede almacenar un 'size_t'.
	// (size_t)-1 es un truco matemático en C para obtener el valor máximo de un tipo sin signo.
	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
// 2. RESERVA DE MEMORIA
	size_total = nmemb * size;
	ptr = malloc(size_total);
	// Protección clásica: si malloc falla, devolvemos NULL
	if (ptr == NULL)
		return (NULL);
// 3. INICIALIZACIÓN A CERO (The calloc way)
	// Recorremos el bloque completo byte a byte para ponerlo a '\0' (cero
	i = 0;
	while (i < (nmemb * size))
	{
		ptr[i] = '\0';
		i++;
	}
// 4. RETORNO
	// Devolvemos el puntero casteado a 'void *' para que sea genérico
	return ((void *)ptr);
}
/*
#include <stdio.h>

int	main(void)
{
// Reservamos espacio para 5 elementos de tamaño 4 bytes cada uno (20 bytes en total)
	char	*ptr = ft_calloc(5, 4);

	printf("%p\n", ptr); // direccion de memoria
	free (ptr); // Muy importante liberar la memoria
	return (0);
}*/
