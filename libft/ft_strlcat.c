/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 07:38:23 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:10:50 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i; // Índice para movernos por el destino 'dst'
	size_t	j; // Índice para movernos por el origen 'src'
	size_t	len_dest; // Almacena la longitud inicial de 'dst'
	size_t	len_src; // Almacena la longitud de 'src'

	i = 0;
	j = 0;
// 1. Calcular las longitudes de ambas cadenas
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
// Posicionamos 'i' al final del texto actual de 'dst' para empezar a concatenar ahí
	i = len_dest;
	j = 0;
// 2. Caso especial de seguridad
	// Si el 'size' pasado es menor o igual a la longitud actual de 'dst', significa
	// que el búfer de destino ya está lleno (o no es válido). No se concatena nada,
	// y por norma se retorna 'size + len_src
	if (size <= len_dest)
		return (size + len_src);
// 3. Bucle de concatenación segura
	// Copiamos caracteres de 'src' a 'dst' mientras:
	// - No hayamos llegado al final de 'src'
	// - Quede espacio disponible en 'dst' (dejando siempre 1 espacio libre para el '\0')
	// El espacio máximo disponible para añadir texto es: size - len_dest - 1
	while (src[j] != '\0' && j < size - len_dest - 1)
	{
		dst[i] = src[j]; // Copia el carácter de origen al final del destino
		i++;
		j++;
	}
// 4. Asegurar el cierre de la cadena
	// Ponemos el carácter nulo al final de la nueva cadena concatenada
	dst[i] = '\0';
// 5. Retorno estándar de strlcat
	// Siempre devuelve la longitud teórica de la cadena que se intentó crear:
	// la longitud inicial de 'dst' + la longitud de 'src'.
	return (len_dest + len_src);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest1[10] = "abc"; // Longitud actual = 3, Capacidad total = 10
	char	str1[] = "def"; // Longitud = 3
	size_t	size1 = sizeof(dest1); // size1 = 10

	printf("%zu\n", ft_strlcat(dest1, str1, size1)); // Debería imprimir: 6 (3 + 3)
	printf ("dest1 = %s\n", dest1); // Debería imprimir: "abcdef"
}*/
