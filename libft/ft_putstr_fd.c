/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:29:33 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/27 12:17:19 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i; // Índice para recorrer la cadena de caracteres

// 1. Protección contra punteros nulos y descriptores inválidos
	// Si la cadena 's' no existe, o si 'fd' es menor que 0, salimos de la función.
	// NOTA: Un fd válido puede ser 0 (entrada estándar), así que evaluamos '!s || fd < 0'.
	if (!fd || !s)
		return ;
	i = 0;
// 2. Bucle de escritura
	// Recorremos la cadena carácter por carácter hasta encontrar el terminador nulo '\0'
	while (s[i] != '\0')
	{
	// La función 'write' recibe:
		// - El descriptor de archivo (fd) donde queremos escribir.
		// - La dirección de memoria del carácter actual (&s[i]).
		// - El número de bytes a escribir (1 byte por carácter).
		write(fd, &s[i], 1);
		i++; // Avanzamos al siguiente carácter de la cadena
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s;

	s = "hello";
// El '1' representa el "Standard Output" (la salida estándar / la terminal).
	// Esta llamada imprimirá "hello" directamente en la pantalla usando write.
	ft_putstr_fd(s, 1);
// El printf volverá a imprimir "hello\n" usando la biblioteca estándar.
	printf ("%s\n", s);
}*/