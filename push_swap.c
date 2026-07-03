/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/03 12:03:00 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
convertirlo a string separados por espacios, concatenar.
trocear hacerle el split?. trocerar
validar que sea números osea convertirlos a números isdigit? validar
sin duplicados, sin negativos, no se salgan de los limites, atoi? convertir
*/

int	main(int argc, char **argv)
{
	char	*dest;

	if (argc < 2)
		return (1);
	dest = 0;
	printf("Número total de argumentos: %d\n", argc);
	//printf("El primer número es: %s\n", argv[1]);
	printf("string destino: %ld\n", ft_strlcat(dest, *argv, argc));
	return (0);
}
