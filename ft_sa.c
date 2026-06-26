/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:57:52 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/26 12:34:35 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_sa(t_node_list **lst_a)
{
	t_node_list	*temp;

	if (lst_a == NULL || *lst_a == NULL || (*lst_a)->next == NULL)
		return ;
	temp = (*lst_a) -> next;
	printf("TEMP CONTENT: %d", temp -> content);
	(*lst_a)->next = temp->next;
	temp->next = (*lst_a);
	(*lst_a) = temp;
	//write(1, "sa\n", 3);
}

/*static void	ft_print_list(t_stack *stack, int size)
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
}*/

int	main(void)
{
	t_node_list	*nodo1 = malloc(sizeof(t_node_list));
	t_node_list	*nodo2 = malloc(sizeof(t_node_list));
	t_node_list	*nodo3 = malloc(sizeof(t_node_list));
	t_stack	*mi_lista = malloc(sizeof(t_stack));

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

	/*printf("HEAD PREV: %d\n\n", mi_lista -> head -> prev -> content);
	printf("TAIL NEXT: %d\n\n", mi_lista -> tail -> next -> content);*/

	//ft_print_list(mi_lista, mi_lista -> size);
	// Mostramos el estado inicial
	printf("Antes del swap:\n");
	printf("1º Nodo: %d\n", mi_lista -> head -> content);
	printf("2º Nodo: %d\n", mi_lista -> head -> next ->content);
	printf("3º Nodo: %d\n\n", mi_lista-> head -> next -> next -> content);

	// 4. Llamamos a tu función pasándole la dirección del puntero
	ft_sa(&mi_lista);

	// Mostramos el resultado
	printf("Después del swap:\n");
	printf("1o nodo: %d\n", mi_lista -> head -> content);
	printf("2º Nodo: %d\n", mi_lista -> head -> next -> content);
	printf("3º Nodo: %d\n\n", mi_lista -> head -> next -> next -> content);


	return (0);
}
