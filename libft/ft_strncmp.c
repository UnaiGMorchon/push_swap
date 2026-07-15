/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 08:37:48 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 07:57:24 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i; // Índice para recorrer ambas cadenas en paralelo

	i = 0;
// 1. Caso base: si 'n' es 0, no debemos comparar ningún carácter.
	// Según el estándar, si no se compara nada, las cadenas se consideran iguales (retorna 0).
	if (n == 0)
		return (0);
// 2. Bucle de comparación
	// Recorremos las cadenas mientras el índice 'i' sea menor que el límite 'n'
	while (i < n)
	{
		// Si los caracteres en la posición 'i' son iguales...
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++; // Si no era el final, avanzamos al siguiente carácter
		else
		// 3. Si encontramos una diferencia:
			// Retornamos la resta de los valores ASCII de los caracteres diferentes.
			// Se hace un casting a (unsigned char) para evitar problemas con caracteres no ASCII (valores > 127)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	// 4. Si el bucle termina porque 'i == n' o por el 'break', las cadenas son iguales hasta 'n'
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
// El carácter '\200' es un valor octal que en decimal equivale a 128.
	// Al ser mayor que 127, si no usaras (unsigned char), en muchos sistemas se leería como un número negativo (-128).
	char	s1[20] = "test\200";
	char	s2[20] = "test\0";
	int		rest;

// Comparamos hasta 6 caracteres
	rest = ft_strncmp(s1, s2, 6);

// Debería imprimir un valor positivo (128 - 0 = 128) gracias al casteo unsigned.
	printf ("resultado = %d\n", rest);
	return (0);
}*/
