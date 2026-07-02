/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/02 14:59:53 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	main(int argc, char **argv)
{
	// Si no hay argumentos extras, terminamos el programa
	if (argc < 2)
		return (1);
	printf("Número total de argumentos: %d\n", argc);
	printf("El primer número es: %s\n", argv[1]);
	return (0);
}
