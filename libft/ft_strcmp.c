/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:05:16 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:25:26 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i; // Índice para recorrer ambas cadenas en paralelo

	i = 0;
// Bucle principal de comparación
	// Se ejecuta mientras el carácter en 's1' sea exactamente igual al de 's2'
	// Y además nos aseguremos de que 's1' no haya llegado al final ('\0')
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++; // Avanzamos al siguiente carácter si son iguales
	}
// Al salir del bucle (porque encontramos una diferencia o llegamos al final),
	// restamos los valores ASCII de los caracteres en esa posición 'i'.
	// - Si s1 es menor que s2, devolverá un número negativo.
	// - Si s1 es mayor que s2, devolverá un número positivo.
	// - Si son idénticas, ambos caracteres serán '\0' (0 - 0) y devolverá 0.
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
int	main(void)
{
	char	s1[];
	char	s2[];

	int		rest;

// Comparamos "Hola" y "Holb".
	// Las primeras tres letras ('H', 'o', 'l') son iguales.
	// En el índice 3, 'a' (ASCII 97) es diferente de 'b' (ASCII 98).
	// El bucle se rompe y resta: 97 - 98 = -1.
	rest = ft_strcmp("Hola", "Holb");
// Debería imprimir: "resto = -1"
	printf("resto = %d\n", rest);
}*/
