/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:53:15 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/09 13:16:57 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declare a pointer 'tmp_first' to save the current head of the stack.
	2.Security check: if stack A does not exist or has less than 2 elements,stop
	3. Store the current first node (head) into the 'tmp_first' variable.
	4. Move the stack's head pointer forward to the second node in the list.
	5. Update the stack's tail pointer to match the new end of the list.
*/

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

/*
	1. Declare a pointer 'tmp_first' to save the current head of the stack.
	2.Security check: if stack B does not exist or has less than 2 elements,stop
	3. Store the current first node (head) into the 'tmp_first' variable.
	4. Move the stack's head pointer forward to the second node in the list.
	5. Update the stack's tail pointer to match the new end of the list.
*/

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

/*
	1. Security check: verify both stacks exist and both have at least 2 nodes.
	2. Call ft_ra to rotate stack A (shifts the top element to the bottom).
	3. Call ft_rb to rotate stack B (shifts the top element to the bottom).
*/

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

/* 
int	main(void)
{
	t_node_list	*nodo1 = malloc(sizeof(t_node_list));
	t_node_list	*nodo2 = malloc(sizeof(t_node_list));
	t_node_list	*nodo3 = malloc(sizeof(t_node_list));
	t_stack		*mi_lista = malloc(sizeof(t_stack));

	// 1. Configuramos el primer nodo
	nodo1 -> content = 8;
	nodo1 -> next = nodo2; // Apunta al segundo nodo
	nodo1 -> prev = nodo3;

	// 2. Configuramos el segundo nodo
	nodo2 -> content = 14;
	nodo2 -> next = nodo3;   // Es el final de la lista
	nodo2 -> prev = nodo1;

// 2. Configuramos el segundo nodo
	nodo3 -> content = 66;
	nodo3 -> next = nodo1;   // Es el final de la lista
	nodo3 -> prev = nodo2;

	// 3. El puntero de la lista apunta al primer nodo
	mi_lista -> head = nodo1;
	mi_lista -> tail = nodo3;
	mi_lista -> size = 3;

	//printf("HEAD PREV: %d\n\n", mi_lista -> head -> prev -> content);
	//printf("TAIL NEXT: %d\n\n", mi_lista -> tail -> next -> content);

	//ft_print_list(mi_lista, mi_lista -> size);
	// Mostramos el estado inicial
	printf("Antes del rotate:\n");
	printf("1º Nodo: %d\n", mi_lista -> head -> content);
	printf("2º Nodo: %d\n", mi_lista -> head -> next ->content);
	printf("3º Nodo: %d\n\n", mi_lista-> head -> next -> next -> content);

	// 4. Llamamos a tu función pasándole la dirección del puntero
	ft_ra(mi_lista);

	// Mostramos el resultado
	printf("Después del rotate:\n");
	printf("1o nodo: %d\n", mi_lista -> head -> content);
	printf("2º Nodo: %d\n", mi_lista -> head -> next -> content);
	printf("3º Nodo: %d\n\n", mi_lista -> head -> next -> next -> content);
	ft_lstclear(mi_lista);
	return (0);
} */
