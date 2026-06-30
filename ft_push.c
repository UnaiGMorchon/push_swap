/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:35:09 by patperez          #+#    #+#             */
/*   Updated: 2026/06/30 09:23:12 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"
#include <stdio.h>
#include <stdlib.h>

/* take first element atop b and put it atop a. nothing done if b empty */
void	ft_pa(t_stack *lst_a, t_stack *lst_b)
{
	t_node_list	*node_to_move;
// 1. Comprobar que las estructuras existan y que B no esté vacía
	if (!lst_a || !lst_b || !lst_b-> head) // si no existen salgo
		return ;
	node_to_move = lst_b-> head; // Guardo en temporal la cabeza Apuntar al nodo que vamos a mover (el primero de B)
	lst_b-> head = lst_b -> head-> next; // la cabeza pasa a ser el segundo
// 2. Mantener la circularidad de la lista B tras extraer el nodo
	if (lst_b -> size == 1) // si quedan nodos
	{
// Si solo había un nodo, la lista B ahora queda vacía
		lst_b->head = NULL; // de primer nodo ya no tiene prev a null
		lst_b->tail = NULL;
	}
	else
	{
		lst_b->head->prev = lst_b->tail; // El nuevo primer nodo apunta hacia atrás al último
		lst_b->tail->next = lst_b->head; // El último nodo apunta hacia adelante al nuevo primero
	}
	lst_b -> size -=1; // restamos 1 a lst_b
// Limpiar los punteros del nodo que movemos para que no arrastre basura
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