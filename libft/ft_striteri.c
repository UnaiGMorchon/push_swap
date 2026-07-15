/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 08:22:33 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:17:31 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i; // Índice para recorrer la cadena 's'

// 1. Protección contra punteros nulos
	// Si la cadena 's' no existe O la función 'f' es un puntero nulo, salimos inmediatamente
	if (!s || !f)
		return ;
	i = 0;
// 2. Bucle principal
	// Recorremos la cadena carácter por carácter hasta encontrar el '\0'
	while (s[i] != '\0')
	{
// Llamamos a la función 'f' pasándole:
	// - El índice actual 'i'
	// - La DIRECCIÓN DE MEMORIA del carácter actual (&s[i])
	// Esto permite a la función 'f' modificar el carácter original directamente
		f(i, &s[i]);
		i++; // Avanzamos al siguiente carácter
	}
}
/*
// Función de prueba: si el índice es par y la letra es minúscula, la pasa a mayúscula
void	f(unsigned int i, char *c)
{
// Usamos '*c' para acceder y modificar el valor apuntado por el puntero
	if (i % 2 == 0 && (*c >= 'a' && *c <= 'z'))
		*c = *c - 32;
}
#include <stdio.h>

int	main(void)
{
	char	s[];

	s[] = "hello world";
// Llamamos a la función. Al pasar 's', se modificará este mismo array.
	ft_striteri(s, f);
// Debería imprimir: "HeLlO WoRlD"
	printf("%s\n", s);
	return (0);
}*/
