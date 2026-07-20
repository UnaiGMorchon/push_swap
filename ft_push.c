/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:35:09 by patperez          #+#    #+#             */
/*   Updated: 2026/07/20 12:59:31 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/* take first element atop b and put it atop a. nothing done if b empty */
/*
	1. Declare a pointer variable 'node_to_move' to store the node from B.
	2. Security check: if pointers are NULL or stack B is empty, stop.
	3. Save the current head of stack B into 'node_to_move'.
	4. Move stack B's head pointer to the next node in the list.
	5. If B had only 1 node, set head and tail to NULL (stack B becomes empty).
	6. If B had more nodes, reconnect head's prev and tail's next to keep it circ
	7. Decrement the total size counter of stack B by 1.
	8. Isolate the moved node by setting its next and prev pointers to NULL.
	9. Use ft_stackadd_front to insert the isolated node at the top of stack A.
*/

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

/* take first element atop a and put it atop b. nothing done if a empty */
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
