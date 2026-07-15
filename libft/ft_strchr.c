/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:14:57 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:28:51 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i; // Índice para recorrer la cadena desde el principio
	char	*source;// Puntero auxiliar para poder quitar el 'const' y retornar un 'char *'
	char	tmp_c; // Variable para almacenar el carácter buscado tras el casteo

// 1. Conversiones de tipo (Casteos)
	// Casteamos 's' a 'char *' para evitar que el compilador proteste al retornar la dirección de memoria.
	source = (char *)s;
// El entero 'c' lo casteamos a 'char' porque las cadenas en C guardan caracteres de 1 byte.
	tmp_c = (char) c;
	i = 0;
// 2. Bucle principal de búsqueda (de izquierda a derecha)
	// Recorremos la cadena mientras no encontremos el carácter nulo '\0'
	while (s[i] != '\0')
	{
// Si el carácter actual coincide con el que buscamos...
		if (s[i] == tmp_c)
			return (&source[i]); // ...retornamos inmediatamente la dirección de memoria de esa posición.
		i++; // Si no coincide, avanzamos al siguiente carácter
	}
// 3. Caso especial: buscar el carácter nulo '\0'
	// Según el estándar de C, el '\0' se considera parte de la cadena.
	// Si el bucle terminó y resulta que lo que el usuario buscaba era justamente el '\0',
	// 'i' estará apuntando al final de la cadena, por lo que retornamos su dirección.
	if (tmp_c == '\0')
		return (&source[i]);
// 4. Si recorrimos toda la cadena y no encontramos el carácter, devolvemos NULL (0)
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "Hello world";

// Busca la 'e'. La encuentra en el índice 1.
	// printf imprimirá desde esa 'e' hasta el final de la cadena.
	// Debería imprimir: "ello world"
	printf("%s\n", ft_strchr(s, 'e'));
	return (0);
}*/
