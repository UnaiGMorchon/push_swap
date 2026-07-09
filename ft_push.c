/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:35:09 by patperez          #+#    #+#             */
/*   Updated: 2026/07/09 09:33:38 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"
#include <stdio.h>
#include <stdlib.h>

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
	9. Use ft_lstadd_front to insert the isolated node at the top of stack A.
*/

void	ft_pa(t_stack *lst_a, t_stack *lst_b)
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
	ft_lstadd_front(lst_a, node_to_move);
}

/* take first element atop a and put it atop b. nothing done if a empty */
void	ft_pb(t_stack *lst_b, t_stack *lst_a)
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
	ft_lstadd_front(lst_b, tmp);
}

/* 
void	ft_print_list(t_stack *stack, int size)
{
	int			counter;
	t_node_list	*lst_tmp;

	counter = 0;
	lst_tmp = stack->head;

	while (counter < size)
	{
		printf(
			"Node %d\n"
			"  addr       : %p\n"
			"  content    : %d\n"
			"  prev content: %d\n"
			"  prev       : %p\n"
			"  next content: %d\n"
			"  next       : %p\n\n",
			counter,
			(void *)lst_tmp,
			lst_tmp->content,
			lst_tmp->prev->content,
			(void *)lst_tmp->prev,
			lst_tmp->next->content,
			(void *)lst_tmp->next
			);
		lst_tmp = lst_tmp->next;
		counter++;
	}
}


int	main(void)
{
	t_stack		*lst_a;
	t_stack		*lst_b;
	t_node_list	*node_a;
	t_node_list	*node_b;

	lst_a = ft_newstack();
	lst_b = ft_newstack();
	node_a = ft_lstnew(1);
	node_b = ft_lstnew(2);
	// STACK_A
	ft_lstadd_back(lst_a, node_a);
	ft_lstadd_back(lst_a, ft_lstnew(12));
	ft_lstadd_back(lst_a, ft_lstnew(13));
	// STACK_B
	ft_lstadd_back(lst_b, node_b);
	ft_lstadd_back(lst_b, ft_lstnew(22));
	ft_lstadd_back(lst_b, ft_lstnew(33));

	printf("---------------STACK A-----------\n");
	ft_print_list(lst_a, lst_a -> size);
	printf("---------------STACK B-----------\n");
	ft_print_list(lst_b, lst_b -> size);

	ft_pa(lst_a, lst_b);
	printf("---------------push A--------------- \n");
	ft_print_list(lst_a, lst_a -> size);

	printf("---------------%d--------------- \n", lst_b->size);

	ft_pb(lst_b, lst_a);
	printf("---------------push B--------------- \n");

	printf("---------------push A--------------- \n");
	ft_print_list(lst_b, lst_b -> size);
	printf("%d \n", lst_a->head->content);
	printf("%d \n", lst_a->size);
	printf("%d \n", lst_a->tail->content);
	printf("%p \n", (void *)lst_a->tail);
	printf("%p \n", (void *)lst_a->head);
	printf("%p\n", (void *)lst_a->head->prev);
	printf("%p", (void *)lst_a->tail->next);

	return (0);
}
 */