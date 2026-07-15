/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:22:38 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:24:18 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
// Evaluamos usando los literales de carácter '0' y '9'.
	// En la tabla ASCII, los números están colocados de forma consecutiva
	// desde el código 48 ('0') hasta el código 57 ('9').
	if (c >= '0' && c <= '9')
		return (1); // Retorna 1 (verdadero) si es un dígito
	return (0); // Retorna 0 (falso) si es cualquier otro carácter
}
/*
#include <stdio.h>

int	main(void)
{
// '4' es un dígito -> Retorna 1
	printf("4: %d\n", ft_isdigit('4'));

// '0' es un dígito -> Retorna 1
	printf("0: %d\n", ft_isdigit('0'));

// 'a' es una letra -> Retorna 0
	printf("a: %d\n", ft_isdigit('a'));

// ' ' es un espacio -> Retorna 0
	printf(" : %d\n", ft_isdigit(' '));

// '/' es el carácter previo al '0' en ASCII (código 47) -> Retorna 0
	printf("/: %d\n", ft_isdigit('/'));
	return (0);
}*/
