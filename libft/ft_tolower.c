/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:46:18 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:37:21 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
// Evaluamos si el carácter se encuentra en el rango de las letras mayúsculas.
	// En la tabla ASCII, la 'A' es el código 65 y la 'Z' es el código 90.
	if (c >= 'A' && c <= 'Z')
	// En la tabla ASCII, la distancia exacta entre cualquier letra mayúscula 
	// y su versión en minúscula es de 32 posiciones. 
	// Por ejemplo: 'A' (65) + 32 = 'a' (97).
	// Así que sumando 32 convertimos la mayúscula en minúscula eficazmente.
		return (c + 32);
// Si no era una letra mayúscula, devolvemos el carácter original sin tocarlo.
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 'H'; // Código ASCII 72
	c = ft_tolower (c); // Debería transformarse en 'h' (Código ASCII 104)
	
	printf("H = %c\n", c);
// Otra prueba útil para verificar que no altere otros caracteres:
	printf("4 = %c\n", ft_tolower('4')); // Debería seguir siendo '4'
	printf("a = %c\n", ft_tolower('a')); // Debería seguir siendo 'a'
}*/
