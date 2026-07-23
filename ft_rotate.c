/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:53:15 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/23 10:38:27 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_ra(t_stack *lst_a, t_bench *bench)
{
	t_node_list	*tmp_first;

	if (!lst_a)
		return ;
	if (lst_a == NULL || lst_a == NULL || lst_a -> head-> next == NULL)
		return ;
	tmp_first = lst_a -> head;
	lst_a -> head = lst_a-> head -> next;
	lst_a -> tail -> next = tmp_first;
	lst_a -> tail = tmp_first;
	bench -> ra += 1;
	bench -> total += 1;
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *lst_b, t_bench *bench)
{
	t_node_list	*tmp_first;

	if (!lst_b)
		return ;
	if (lst_b == NULL || lst_b == NULL || lst_b -> head-> next == NULL)
		return ;
	tmp_first = lst_b -> head;
	lst_b -> head = lst_b-> head -> next;
	lst_b -> tail -> next = tmp_first;
	lst_b -> tail = tmp_first;
	bench -> rb += 1;
	bench -> total += 1;
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack *lst_a, t_stack *lst_b, t_bench *bench)
{
	if (!lst_a || lst_a->size < 2 || !lst_b || lst_b->size < 2)
		return ;
	ft_ra(lst_a, bench);
	ft_rb(lst_b, bench);
	bench -> rr += 1;
	bench -> ra -= 1;
	bench -> rb -= 1;
	bench -> total -= 1;
	write(1, "rr\n", 3);
}
