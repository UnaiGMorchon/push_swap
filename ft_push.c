/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:35:09 by patperez          #+#    #+#             */
/*   Updated: 2026/07/23 10:37:34 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_pa(t_stack *lst_a, t_stack *lst_b, t_bench *bench)
{
	t_node_list	*node_to_move;

	if (!lst_a || !lst_b || !lst_b-> head)
		return ;
	node_to_move = lst_b-> head;
	lst_b -> head = lst_b -> head -> next;
	if (lst_b -> size == 1)
	{
		lst_b->head = NULL;
		lst_b->tail = NULL;
	}
	else
	{
		lst_b->head->prev = lst_b->tail;
		lst_b->tail->next = lst_b->head;
	}
	lst_b -> size -= 1;
	node_to_move -> next = NULL;
	node_to_move -> prev = NULL;
	ft_stackadd_front(lst_a, node_to_move);
	bench -> pa += 1;
	bench -> total += 1;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *lst_b, t_stack *lst_a, t_bench *bench)
{
	t_node_list	*tmp;

	if (!lst_b || !lst_a || !lst_a->head)
		return ;
	tmp = lst_a->head;
	lst_a -> head = lst_a ->head ->next;
	if (lst_a -> size == 1)
	{
		lst_a->head = NULL;
		lst_a->tail = NULL;
	}
	else
	{
		lst_a->head->prev = lst_a->tail;
		lst_a->tail->next = lst_a->head;
	}
	lst_a -> size -= 1;
	tmp->next = NULL;
	tmp->prev = NULL;
	ft_stackadd_front(lst_b, tmp);
	bench -> pb += 1;
	bench -> total += 1;
	write(1, "pb\n", 3);
}
