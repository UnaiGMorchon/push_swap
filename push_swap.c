/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/10 08:38:59 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	main(int argc, char **argv)
{
	char	**args;

	args = NULL;
	if (argc < 2)
		return (0);
	args = new_args(argc, argv, args);
	if ((ft_is_validint(args)) == 0 || (ft_isrepeat(args)) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
