/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:19:02 by patperez          #+#    #+#             */
/*   Updated: 2026/07/14 16:02:45 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	get_max_bits(t_stack *lst)
{
	t_node_list	*copy;
	int	i;
	int	bits;

	i = 0;
	bits = 0;
	copy = lst -> head;
	while (copy -> next != lst -> head)
	{
		while (i < copy)
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

void	ft_radix(t_stack *lst_a, t_bench *bench)
{
	t_stack	*lst_b;
	int	i;
	int	j;
	int	max_bits;
	t_node_list	*tmp_lst_a;

	if (lst_a == NULL || lst_a -> head == NULL || lst_a -> size <= 1)
		return ;
	lst_b = ft_newstack();
	i = 0;
	tmp_lst_a = lst_a -> head;
	max_bits = get_max_bits(lst_a);
	while (i++ < max_bits)
	{
		j = 0;
		while (j++ < lst_a -> size)
		{
			if (((tmp_lst_a -> index >> i) & 1) == 1)
				ra(lst_a, bench);
			else
				pb(lst_b, lst_a, bench);
		}
		while (lst_b)
			pa(lst_a, lst_b, bench);
		ft_lstclear(lst_b);
	}
}