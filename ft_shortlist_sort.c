/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortlist_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:52:16 by patperez          #+#    #+#             */
/*   Updated: 2026/07/17 15:11:12 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

static void	shortlist_under_three(t_stack *lst, t_bench *bench)
{
	int	counter;

	counter = 0;
	if (lst -> size == 2)
	{
		if (lst -> head -> index > lst -> head -> next -> index)
			ft_sa(lst, bench);
	}
	if (lst -> size == 3)
	{
		while (counter < lst -> size)
		{
			if (lst -> head -> index > lst -> head -> next -> index)
				ft_sa(lst, bench);
			else if ((lst -> head -> index < lst -> head -> next -> index)
				&& (lst -> head -> next -> index < lst -> tail -> index)
				&& (lst -> head -> index < lst -> tail -> index))
				return ;
			else
				ft_rra(lst, bench);
			counter++;
		}
	}
	ft_clearstack(lst);
}

static void	shortlist_under_five(t_stack *lst, t_bench *bench)
{
	t_stack		*lst_b;
	int			min_index;

	lst_b = ft_newstack();
	min_index = 0;
	while (lst -> size > 3)
	{
		if (lst -> head -> index == min_index)
		{
			ft_pb(lst_b, lst, bench);
			min_index++;
		}
		else
			ft_ra(lst, bench);
	}
	shortlist_under_three(lst, bench);
	if (lst_b -> head -> index < lst_b -> head -> next -> index)
		ft_sb(lst_b, bench);
	while (lst_b -> size)
		ft_pa(lst, lst_b, bench);
	ft_clearstack(lst_b);
}

void	ft_shortlist_sort(t_stack *lst, t_bench *bench)
{
	if (lst -> size <= 3)
		shortlist_under_three(lst, bench);
	if (lst -> size == 4 || lst -> size == 5)
		shortlist_under_five(lst, bench);
	ft_clearstack(lst);
}
