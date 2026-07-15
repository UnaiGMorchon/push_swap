/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:46:21 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:38:44 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
// Evaluamos si el carácter se encuentra en el rango de las letras minúsculas.
	// En la tabla ASCII, la 'a' es el código 97 y la 'z' es el código 122.
	if (c >= 'a' && c <= 'z')
// Al igual que en tolower, la distancia entre mayúsculas y minúsculas es de 32.
	// Como las mayúsculas están antes en la tabla ASCII (la 'A' es el 65),
	// restamos 32 para "subir" en la tabla y obtener la letra en mayúscula.
	// Ejemplo: 'a' (97) - 32 = 'A' (65).
		return (c - 32);
// Si no era una letra minúscula, devolvemos el carácter tal cual lo recibimos.
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 'h'; // Código ASCII 104
	c = ft_toupper(c); // Debería transformarse en 'H' (Código ASCII 72)
	printf("h = %c\n", c);

// Pruebas de control para asegurar la robustez:
	printf("A = %c\n", ft_toupper('A')); // Ya es mayúscula, debe seguir siendo 'A'
	printf("[ = %c\n", ft_toupper('[')); // Es un símbolo (ASCII 91), debe seguir siendo '['
	return (0);
}*/
