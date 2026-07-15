/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:11:15 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:31:56 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char	*source; // Puntero auxiliar para movernos byte a byte

	// Casteamos el puntero genérico 'void *s' a 'char *'.
	// Esto es obligatorio porque 'void *' no tiene un tamaño definido,
	// y al convertirlo a 'char *' le decimos al compilador que queremos 
	// modificar la memoria byte a byte (ya que 1 char = 1 byte).
	source = (char *)s;
// Bucle que se ejecutará tantas veces como bytes hayamos pedido borrar
	while (n > 0)
	{
// 1. Ponemos a 0 el byte actual apuntado por 'source'.
	// 2. El operador de post-incremento (source++) avanza el puntero 
	//    al siguiente byte inmediatamente después de hacer la asignación.
		*(source++) = 0;
		n--; // Restamos 1 al contador de bytes pendientes
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "hello world";

	ft_bzero(s, 6);
	printf("Printed: %s\n", s);
	return (0);
}*/
