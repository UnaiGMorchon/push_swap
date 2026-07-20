/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:19:02 by patperez          #+#    #+#             */
/*   Updated: 2026/07/20 07:49:54 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while (size != 0)
	{
		size = size / 2;
		bits ++;
	}
	return (bits);
}

void	ft_radix(t_stack *lst_a, t_bench *bench)
{
	t_stack		*lst_b;
	int			i;
	int			j;
	int			max_bits;

	lst_b = ft_newstack();
	i = 0;
	max_bits = get_max_bits(lst_a->size - 1);
	while (i < max_bits)
	{
		j = 0;
		while (j < lst_a -> size)
		{
			if (((lst_a -> head -> index >> i) & 1) == 1)
				ft_ra(lst_a, bench);
			else
				ft_pb(lst_b, lst_a, bench);
			j++;
		}
		while (lst_b-> size)
			ft_pa(lst_a, lst_b, bench);
		i++;
	}
	ft_clearstack(lst_b);
}
