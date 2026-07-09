/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/09 10:41:26 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
convertirlo a string separados por espacios, concatenar. (contar los que tenemos?)
trocear hacerle el split?. trocerar
validar que sea números, convertirlos a números isdigit? validar
sin duplicados, sin negativos, no se salgan de los limites, atoi? convertir
*/

int	main(int argc, char **argv)
{
	int	arg_i;

	arg_i = 1;
	if (argc < 2)
		return (0);
	while (arg_i < argc)
	{
		ft_is_validint(&argv[arg_i]);
		//ft_isrepeat(argv);
		arg_i++;
	}
	return (0);
}
