/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:57:52 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/02 13:13:56 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declare 'temp' to hold the integer content during the swap.
	2. Declare 'temp_index' to hold the node's index during the swap.
	3. Security check: if stack A does not exist or has less than 2 nodes, stop.
	4. Save the content of the first node (head) into the 'temp' variable.
	5. Save the index of the first node (head) into the 'temp_index' variable.
	6. Copy the content of the second node into the first node.
	7. Copy the index of the second node into the first node.
	8. Move the original first node's content from 'temp' into the second node.
	9. Move the original first node's index from 'temp_index' into second node.
	10. Write the operation string "sa\n" to the standard output.
*/

void	ft_sa(t_stack *lst_a)
{
	int	temp;
	int	temp_index;

	if (lst_a == NULL || lst_a-> size < 2)
		return ;
	temp = lst_a-> head-> content;
	temp_index = lst_a-> head-> index;
	lst_a -> head -> content = lst_a -> head-> next -> content;
	lst_a -> head -> index = lst_a -> head-> next -> index;
	lst_a-> head -> next-> content = temp;
	lst_a-> head -> next-> index = temp_index;
	write(1, "sa\n", 3);
}

/*
	1. Declare 'temp' to hold the integer content during the swap.
	2. Declare 'temp_index' to hold the node's index during the swap.
	3. Security check: if stack B does not exist or has less than 2 nodes, stop.
	4. Save the content of the first node (head) into the 'temp' variable.
	5. Save the index of the first node (head) into the 'temp_index' variable.
	6. Copy the content of the second node into the first node.
	7. Copy the index of the second node into the first node.
	8. Move the original first node's content from 'temp' into the second node.
	9. Move the original first node's index from 'temp_index' into second node
	10. Write the operation string "sb\n" to the standard output.
*/

void	ft_sb(t_stack *lst_b)
{
	int	temp;
	int	temp_index;

	if (lst_b == NULL || lst_b -> size < 2)
		return ;
	temp = lst_b-> head -> content;
	temp_index = lst_b-> head-> index;
	lst_b ->head-> content = lst_b ->head -> next-> content;
	lst_b -> head -> index = lst_b -> head-> next -> index;
	lst_b->head->next->content = temp;
	lst_b-> head -> next-> index = temp_index;
	write(1, "sb\n", 3);
}

/*
	1. Security check: verify both stacks exist and both have at least 2 nodes.
	2. Call ft_sa to swap the top two elements of stack A.
	3. Call ft_sb to swap the top two elements of stack B.
	4. Write the combined operation string "ss\n" to the standard output.
*/

void	ft_ss(t_stack *lst_a, t_stack *lst_b)
{
	if (!lst_a || lst_a->size < 2 || !lst_b || lst_b->size < 2)
	{
		ft_sa(lst_a);
		ft_sb(lst_b);
		write(1, "ss\n", 3);
	}
}
/* 
void	ft_get_index(t_stack *lst_a)
{
	int			index_count;
	t_node_list	*current;
	t_node_list	*current_aux;
	int			i;
	int			j;

	current = lst_a -> head;
	i = 0;
	while (i < lst_a->size)
	{
		index_count = 0;
		current_aux = lst_a->head;
		j = 0;
		while (j < lst_a->size)
		{
			if (current_aux -> content < current -> content)
			{
				index_count += 1;
			}
			current_aux = current_aux -> next;
			j++;
		}
		current -> index = index_count;
		current = current ->next;
		i++;
	}
} */

/* static void	ft_print_list(t_stack *stack, int size)
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
			"  prev       : %p\n"
			"  next       : %p\n\n",
			counter,
			(void *)lst_tmp,
			lst_tmp->content,
			(void *)lst_tmp->prev,
			(void *)lst_tmp->next
			);
		lst_tmp = lst_tmp->next;
		counter++;
	}
} */
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
	ft_get_index(mi_lista);
	printf("Antes del swap:\n");
	printf("1º Nodo: %d\n", mi_lista -> head -> content);
	printf("1º Nodo indice: %d\n", mi_lista -> head -> index);
	printf("2º Nodo: %d\n", mi_lista -> head -> next ->content);
	printf("2º Nodo indice : %d\n", mi_lista -> head -> next ->index);
	printf("3º Nodo: %d\n", mi_lista-> head -> next -> next -> content);
	printf("3º Nodo indice: %d\n\n", mi_lista-> head -> next -> next -> index);


	// 4. Llamamos a tu función pasándole la dirección del puntero
	ft_sa(mi_lista);

	printf("despues del swap:\n");
	printf("1º Nodo: %d\n", mi_lista -> head -> content);
	printf("1º Nodo: %d\n", mi_lista -> head -> index);
	printf("2º Nodo: %d\n", mi_lista -> head -> next ->content);
	printf("2º Nodo: %d\n", mi_lista -> head -> next ->index);
	printf("3º Nodo: %d\n", mi_lista-> head -> next -> next -> content);
	printf("3º Nodo: %d\n\n", mi_lista-> head -> next -> next -> index);
	ft_lstclear(mi_lista);
	return (0);
}
 */