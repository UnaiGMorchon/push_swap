/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:06:50 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:43:10 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
// 1. Protección del Descriptor de Archivo (fd)
	// En sistemas Unix, los descriptores de archivo válidos van del 0 en adelante (0: entrada, 1: salida, 2: error).
	// Cambiar '!fd' por 'fd < 0' evita que la función se bloquee si alguien intenta usar el fd 0 (STDIN).
	if (!fd)
		return ;
// 2. Escritura del carácter
	// La función del sistema 'write' necesita:
	// - El descriptor donde va a escribir (fd).
	// - La dirección de memoria donde está el carácter a pintar (&c).
	// - El número de bytes que va a escribir (1 byte, ya que un char ocupa exactamente eso).
	write(fd, &c, 1);
}
/*
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'U';
	// El '1' representa STDOUT_FILENO (la salida estándar / la terminal).
	// Escribirá el carácter 'U' directamente en la pantalla usando write.
	ft_putchar_fd(c, 1);
	// El printf volverá a imprimir la 'U' seguida de un salto de línea.
	printf ("%c\n", c);
}*/
