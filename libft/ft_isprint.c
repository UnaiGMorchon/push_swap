/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:22:42 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:22:58 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
// En la tabla ASCII, los caracteres imprimibles empiezan en el 32 (el espacio ' ')
	// y terminan en el 126 (el carácter de la tilde de la eñe o virgulilla '~').
	// Los valores del 0 al 31, y el 127, son caracteres de control no imprimibles (como \n, \t, DEL).
	if (c >= 32 && c <= 126)
		return (1); // Retorna 1 (verdadero) si está en el rango imprimible
	return (0); // Retorna 0 (falso) si es un carácter de control
}
/*
#include <stdio.h>

int	main(void)
{
// 'A' está en el número 65 -> Imprimible (Retorna 1)
	printf("A= %d\n", ft_isprint('A'));

// El espacio ' ' es el número 32 -> Imprimible (Retorna 1)
	printf("espace = %d\n", ft_isprint(' '));

// '\n' (salto de línea) es el número 10 -> Control (Retorna 0)
	printf("\\n = %d\n", ft_isprint('\n'));

// '\t' (tabulador) es el número 9 -> Control (Retorna 0)
	printf("\\t = %d\n", ft_isprint('\t'));

// '\0' (terminador nulo) es el número 0 -> Control (Retorna 0)
	printf("\\0 = %d\n", ft_isprint('\0'));
}*/
