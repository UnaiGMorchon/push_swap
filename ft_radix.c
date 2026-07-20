/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:19:02 by patperez          #+#    #+#             */
/*   Updated: 2026/07/20 13:11:27 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

static int	ft_get_max_bits(int size)
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
	int			max_bits;
	int			size;

	lst_b = ft_newstack();
	i = 0;
	max_bits = ft_get_max_bits(lst_a->size - 1);
	while (i < max_bits)
	{
		size = lst_a -> size;
		while (size-- > 0)
		{
			if (((lst_a -> head -> index >> i) & 1) == 1)
				ft_ra(lst_a, bench);
			else
				ft_pb(lst_b, lst_a, bench);
		}
		while (lst_b-> size)
			ft_pa(lst_a, lst_b, bench);
		i++;
	}
	ft_clearstack(lst_b);
}
