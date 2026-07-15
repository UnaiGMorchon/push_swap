/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:02:55 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 07:51:03 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*source; // Puntero auxiliar para evitar problemas con caracteres extendidos (ASCII > 127)
	int				i; // Índice para movernos por la cadena

// 1. Conversión de tipo (Casting)
	// Convertimos 's' a 'unsigned char *' para comparar los bytes correctamente sin importar el signo
	source = (unsigned char *)s;
// 2. Encontrar el final de la cadena
	i = 0;
	while (s[i] != '\0')
	{
		i++; // Incrementamos 'i' hasta que apunte al carácter nulo '\0'
	}
// 3. Búsqueda de derecha a izquierda (desde el '\0' hacia atrás)
	// El bucle se ejecuta mientras 'i' sea mayor que 0
	while (i)
	{
// Si el carácter en la posición 'i' coincide con 'c' (convertido a unsigned char)
		if (s[i] == (unsigned char) c)
			return ((char *)&source[i]); // Retornamos la dirección de memoria de ese carácter, casteada a (char *)
		i--; // Retrocedemos una posición hacia la izquierda
	}
	// 4. Comprobación del primer carácter (índice 0)
	// Como el bucle 'while (i)' se detiene cuando 'i == 0', tenemos que chequear la posición 0 manualmente aquí fuera
	if (source[i] == (unsigned char) c)
		return ((char *)&source[i]);
// 5. Si no se encuentra el carácter en toda la cadena, devolvemos NULL
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "Hello world";

// 1. Debe imprimir la dirección de memoria de la ÚLTIMA 'l' (la de "world")
	printf("%p\n", ft_strrchr(s, 'l'));

// 2. Debe imprimir "ld" (la cadena desde la última 'l' hasta el final)
	printf("%s\n", ft_strrchr(s, 'l'));
	
// 3. Debe funcionar también buscando el carácter nulo '\0'. 
	// Como empezamos desde el final (donde está el '\0'), lo encuentra de primero e imprime una cadena vacía.
	printf("%s\n", ft_strrchr(s, '\0'));
	return (0);
}*/
