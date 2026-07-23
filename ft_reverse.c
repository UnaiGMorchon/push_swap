/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:54:15 by patperez          #+#    #+#             */
/*   Updated: 2026/07/23 10:38:20 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_rra(t_stack *lst_a, t_bench *bench)
{
	t_node_list	*tmp_newlast;

	tmp_newlast = lst_a -> head;
	if (!lst_a || lst_a == NULL)
		return ;
	tmp_newlast = lst_a -> tail-> prev;
	lst_a -> head = lst_a -> tail;
	lst_a -> tail = tmp_newlast;
	bench -> rra += 1;
	bench -> total += 1;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *lst_b, t_bench *bench)
{
	t_node_list	*tmp_newlast;

	tmp_newlast = lst_b -> head;
	if (!lst_b || lst_b == NULL)
		return ;
	tmp_newlast = lst_b -> tail-> prev;
	lst_b -> head = lst_b -> tail;
	lst_b -> tail = tmp_newlast;
	bench -> rrb += 1;
	bench -> total += 1;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *lst_a, t_stack *lst_b, t_bench *bench)
{
	if ((!lst_a || lst_a == NULL) || (!lst_b || lst_b == NULL))
		return ;
	ft_rra(lst_a, bench);
	ft_rrb(lst_b, bench);
	bench -> rrr += 1;
	bench -> rra -= 1;
	bench -> rrb -= 1;
	bench -> total -= 1;
	write(1, "rrr\n", 4);
}
