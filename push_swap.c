/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/02 15:26:22 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
convertirlo a string?
hacerle el split?
validar que sea números osea convertirlos a números
que no hay duplicados
que no sean negativos
que no se salgan d los limites
*/

int	ft_putstr(char *s)
{
	int	i;
	int	counter;

	if (!s)
		s = "(null)";
	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		counter += write(1, &s[i], 1);
		i++;
	}
	return (counter);
}

int	main(int argc, char **argv)
{
	char	*s;
	s = 0;

	// Si no hay argumentos extras, terminamos el programa
	if (argc < 2)
		return (1);
	printf("Número total de argumentos: %d\n", argc);
	printf("El primer número es: %s\n", argv[1]);
	ft_putstr(s);
	printf("string números : %s\n", s);

	return (0);
}
