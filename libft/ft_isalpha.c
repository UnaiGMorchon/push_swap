/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:15:15 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:26:43 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
// Evaluamos si el carácter se encuentra en alguno de los dos rangos alfabéticos.
	// Rango 1: Letras minúsculas de la 'a' (ASCII 97) a la 'z' (ASCII 122).
	// Rango 2: Letras mayúsculas de la 'A' (ASCII 65) a la 'Z' (ASCII 90).
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1); // Retorna 1 (verdadero) si es una letra
	return (0); // Retorna 0 (falso) si es cualquier otro carácter (números, símbolos, etc.)
}
/*
#include <stdio.h>

int	main(void)
{
// 'A' es una letra mayúscula -> Retorna 1
	printf("A %d\n", ft_isalpha('A'));

// 'a' es una letra minúscula -> Retorna 1
	printf("a %d\n", ft_isalpha('a'));

// '1' es un número -> Retorna 0
	printf("1 %d\n", ft_isalpha('1'));

// '!' es un símbolo de puntuación -> Retorna 0
	printf("! %d\n", ft_isalpha('!'));
	return (0);
}*/
