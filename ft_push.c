/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:35:09 by patperez          #+#    #+#             */
/*   Updated: 2026/06/29 09:56:56 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"
#include <stdio.h>
#include <stdlib.h>

/* take first element atop b and put it atop a. nothing done if b empty */
void	ft_pa(t_stack *lst_a, t_stack *lst_b)
{
	t_node_list	*node_to_move;

	if (!lst_a || !lst_b || !lst_b-> head) // si no existen salgo
		return ;
	node_to_move = lst_b-> head; // Guardo en temporal la cabeza
	lst_b-> head = lst_b -> head-> next; // la cabeza pasa a ser el segundo
	if(lst_b -> head != NULL) // si quedan nodos
		lst_b-> head -> prev = NULL; // de lst_b prev a null
	else // si no quedan nodos
		lst_b -> tail = NULL; // lst_b tail a null
	lst_b -> size -=1; // restamos 1 a lst_b
	node_to_move -> next = NULL;
	node_to_move -> prev = NULL;
	ft_lstadd_front(lst_a, node_to_move); // meto el nodo en lst_a
}

/* take first element atop a and put it atop b. nothing done if a empty */
void	ft_pb(t_stack *lst_b, t_stack *lst_a)
{
	t_node_list	*tmp;

	if (!lst_b || !lst_a || !lst_a->head)
		return ;
	tmp = lst_a->head;
	lst_a -> head = lst_a ->head ->next;
	if (lst_a -> head != NULL)
		lst_a -> head -> prev = NULL;
	else
		lst_a -> tail = NULL;
	lst_a -> size -= 1;
	tmp->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(lst_b, tmp);
}


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
	t_stack	*lst_a;
	t_stack	*lst_b;
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
	ft_print_list(lst_b, lst_b -> size);
	ft_print_list(lst_a, lst_a -> size);
	return (0);
}
