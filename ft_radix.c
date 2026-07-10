/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:19:02 by patperez          #+#    #+#             */
/*   Updated: 2026/07/10 15:18:58 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	get_max_bits(t_stack *lst)
{
	t_node_list	*copy;
	int	i;
	int	bits;

	i = 0;
	bites = 0;
	copy = *lst -> head;
	while (copy -> next != head)
	{
		while (*copy[i])
		{
			bits++;
			i++;
		}
		if (bits > i)
			bits = i;
		i = 0;
		copy = copy -> next;
	}
	return (bits);
}

void	ft_radix(t_stack **lst_a, t_stack **lst_b, t_bench bench)
{
	t_node_list	*head_mark;
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	head_mark = *lst_a;
	size = ft_lstsize(lst_a);
	max_bits = get_max_bits(lst_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_mark = *lst_a;
			if (((head_a -> index >> i) & 1) == 1)
				ra(lst_a, bench);
			else
				pb(lst_b, lst_a, bench);
		}
		while (*lst_b)
			pa(lst_a, lst_b, bench);
		ft_lstclear(lst_b);
		i++;
	}
}
