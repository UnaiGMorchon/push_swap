/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:19:02 by patperez          #+#    #+#             */
/*   Updated: 2026/07/17 10:03:32 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while (size != 0)
	{
		size = size / 2;
		bits++;
	}
	return (bits);
}

void	ft_radix(t_stack *lst_a, t_bench *bench)
{
	t_stack		*lst_b;
	int			i;
	int			j;
	int			max_bits;
	int			size;

	lst_b = ft_newstack();
	i = 0;
	ft_get_index(lst_a);
	size = lst_a -> size;
	max_bits = get_max_bits(lst_a -> size - 1);
	while (i++ < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((lst_a -> head -> index >> i) & 1) == 1)
				ft_ra(lst_a, bench);
			else
				ft_pb(lst_b, lst_a, bench);
		}
		while (lst_b -> size)
			ft_pa(lst_a, lst_b, bench);
	}
	ft_lstclear(lst_b);
}