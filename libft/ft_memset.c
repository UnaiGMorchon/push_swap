/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 07:24:01 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:45:55 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*memory_area; // Puntero auxiliar de 1 byte (unsigned char) para poder avanzar byte a byte

// 1. Conversión de tipo (Casting)
	// El puntero original 's' es de tipo 'void *' (puntero genérico). No podemos hacer aritmética 
	// de punteros (como memory_area++) con un void *. Por eso lo casteamos a 'unsigned char *'.
	// Usamos 'unsigned char' porque el estándar de C dicta que la memoria se manipula byte a byte
	// como datos sin signo (valores de 0 a 255).
	memory_area = (unsigned char *)s;
// 2. Bucle de llenado de memoria
	// El bucle se ejecutará exactamente 'n' veces (el número de bytes que nos pidieron rellenar)
	while (n > 0)
	{
		// Modificamos el valor de la posición de memoria actual.
		// Casteamos el entero 'c' a 'unsigned char' para asegurarnos de guardar solo 1 byte.
		*memory_area = (unsigned char)c;
		memory_area++; // Avanzamos al siguiente byte en la memoria
		n--; // Decrementamos el contador de bytes restantes
	}
	// 3. Retorno del puntero original
	// Según el estándar, memset debe devolver el puntero original 's' (el inicio del bloque modificado)
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "hello";

// Rellenamos los 5 bytes de la cadena "hello" con el carácter 'c'
	ft_memset(s, 'c', 5);
	// Debería imprimir: "ccccc"
	printf("%s\n", s);
	return (0);
}*/
