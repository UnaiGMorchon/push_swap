/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 07:39:25 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:06:24 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	counter; // Índice para recorrer las cadenas y copiar caracteres
	size_t	src_length; // Variable para almacenar la longitud de 'src'

	counter = 0;
	// 1. Calcular la longitud de la cadena de origen
	src_length = ft_strlen(src);
// 2. Caso especial: si el tamaño del destino es 0
	// No hay espacio ni para el carácter nulo '\0'. 
	// Según el estándar, no copiamos nada pero devolvemos la longitud de 'src'.
	if (size == 0)
		return (src_length);
// 3. Bucle de copia segura
	// Copiamos caracteres mientras existan en 'src' Y el contador sea menor que (size - 1).
	// Reservamos ese "- 1" para asegurarnos de tener espacio para el '\0' al final.
	while (src[counter] && counter < (size - 1))
	{
		dst[counter] = src[counter]; // Copia el carácter de origen al destino
		counter++;
	}
// 4. Asegurar el cierre de la cadena
	// Ponemos el carácter nulo en la posición actual de 'counter' (que como máximo será size - 1).
	// Esto garantiza que 'dst' sea SIEMPRE una cadena válida y terminada en nulo.
	dst[counter] = '\0';
// 5. Retorno estándar de strlcpy
	// Devolvemos la longitud total de 'src'. Esto sirve para que el programador 
	// pueda saber si la cadena fue truncada (si el retorno es >= size, hubo truncamiento).
	return (ft_strlen(src));
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[20];
	char	src[] = "hello";
	int		result;

// Pasamos sizeof(dest) que es 20. Como "hello" mide 5, cabe de sobra.
	result = ft_strlcpy(dest, src, sizeof(dest));
	printf("dest = %s\n", dest); // Imprimirá: "hello"
	printf("src = %s\n", src); // Imprimirá: "hello"

	printf("length = %zu\n", result); // Imprimirá: 5 (longitud de src)
	return (0);
}*/
