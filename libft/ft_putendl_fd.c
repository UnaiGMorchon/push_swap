/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:41:19 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:41:54 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
// 1. Protección contra punteros nulos y descriptores inválidos
	// Los descriptores válidos en Unix van de 0 en adelante (0 es STDIN).Los inválidos son los negativos.
	// Cambiar '!fd' por 'fd < 0' asegura que no rompas el programa si alguien usa el fd 0.
	if (!fd || !s)
		return ;
// 2. Imprimir la cadena de texto
	// Llamamos a tu función ft_putstr_fd para que envíe toda la cadena 's' al descriptor 'fd'.
	ft_putstr_fd (s, fd);
// 3. Añadir el salto de línea (End of Line)
	// Usamos 'write' para escribir el carácter de salto de línea '\n' (1 byte) 
	// justo al final del texto que acabamos de imprimir.
	write(fd, "\n", 1);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s;

	s = "Hello world";
// El '1' representa la salida estándar (la terminal).
	// Imprimirá "Hello world" seguido de un salto de línea invisible.
	ft_putendl_fd(s, 1);
}*/