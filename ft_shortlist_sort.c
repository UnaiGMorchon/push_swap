/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortlist_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:52:16 by patperez          #+#    #+#             */
/*   Updated: 2026/07/17 10:39:25 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

static void	shortlist_under_three(t_stack *lst, t_bench *bench)
{
	if (lst -> size == 2)
	{
		if (lst -> head > lst -> head -> next)
			ft_sa(lst, bench);
	}
	if (lst -> size == 3)
	{
		while (!(lst -> head < lst -> head -> next)
			&& !(lst -> head -> next < lst -> head -> next -> next))
		{
			if (lst -> head > lst -> head -> next)
				ft_sa(lst, bench);
			else
				ft_rra(lst, bench);
		}
	}
	ft_lstclear(lst);
}

/* static void	shortlist_under_five(t_stack *lst, t_bench *bench)
{
	if ()
	ft_lstclear(lst);
} */

void	ft_shortlist_sort(t_stack *lst, t_bench *bench)
{
	if (lst -> size <= 3)
		shortlist_under_three(lst, bench);
	/*if (lst -> size <= 5)
		shortlist_under_five(lst, bench);*/
}
