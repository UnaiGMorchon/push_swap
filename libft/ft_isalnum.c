/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:48:55 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:27:59 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
// Evaluamos si el carácter cumple con cualquiera de las tres condiciones válidas:
	// Condición 1: Letras minúsculas de la 'a' a la 'z'.
	// Condición 2: Letras mayúsculas de la 'A' a la 'Z'.
	// Condición 3: Dígitos numéricos de la '0' a la '9'.
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1); // Retorna 1 (verdadero) si es una letra o un número
	return (0); // Retorna 0 (falso) si es cualquier otro carácter (símbolos, espacios, control)
}
/*
#include <stdio.h>

int	main(void)
{
// 'A' es una letra mayúscula -> Alfanumérico (Retorna 1)
	printf("A %d\n", ft_isalnum('A'));

// 'a' es una letra minúscula -> Alfanumérico (Retorna 1)
	printf("a %d\n", ft_isalnum('a'));

// '1' es un dígito numérico -> Alfanumérico (Retorna 1)
	printf("1 %d\n", ft_isalnum('1'));

// '!' es un símbolo especial -> No alfanumérico (Retorna 0)
	printf("! %d\n", ft_isalnum('!'));

// ' ' es un espacio en blanco -> No alfanumérico (Retorna 0)
	printf("  %d\n", ft_isalnum(' '));
	return (0);
}*/
