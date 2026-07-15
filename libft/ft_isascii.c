/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:41:31 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:25:31 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
// La tabla ASCII estándar original está compuesta por exactamente 128 caracteres,
	// indexados desde el número 0 hasta el 127. 
	// Cualquier valor fuera de este rango (negativos o superiores a 127) pertenece 
	// al ASCII extendido o a otros sistemas de codificación (como UTF-8).
	if (c >= 0 && c <= 127)
		return (1); // Retorna 1 (verdadero) si el carácter es un valor ASCII válido
	return (0); // Retorna 0 (falso) si está fuera del rango estándar
}
/*
#include <stdio.h>

int	main(void)
{
// 'A' equivale al código 65 -> Es ASCII (Retorna 1)
	printf("A= %d\n", ft_isascii('A'));

// 127 es el carácter de control DEL (límite superior) -> Es ASCII (Retorna 1)
	printf("127= %d\n", ft_isascii(127));

// 200 está fuera de la tabla estándar (pertenece al ASCII extendido) -> Retorna 0
	printf("200 = %d\n", ft_isascii(200));
return (0);
}*/
