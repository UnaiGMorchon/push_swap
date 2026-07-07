/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/07 08:49:40 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	main(int argc, char **argv)
{
	int	arg_i;

	arg_i = 1;
	if (argc < 2)
		return (0);
	while (arg_i <= argc)
	{
		ft_is_validint(argv);
		//ft_isrepeat(argv);
		argv++;
	}
	return (0);
}
