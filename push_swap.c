/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/03 12:45:15 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
convertirlo a string separados por espacios, concatenar.
trocear hacerle el split?. trocerar
validar que sea números, convertirlos a números isdigit? validar
sin duplicados, sin negativos, no se salgan de los limites, atoi? convertir
*/

int	main(int argc, char **argv)
{
	char	dest[50] = "";
	int		i;
	char	string;

	i = 1;
	while (i < argc)
	{
		string = ft_strlcat(dest, argv[i], 50);
		i++;
	}

	if (argc < 2)
		return (1);
	printf("Número total de argumentos: %d\n", argc);
	printf("El primer número es: %s\n", argv[1]);
	printf("total string size: %d\n", string);
	printf("string destino: %s\n", dest);
	return (0);
}
