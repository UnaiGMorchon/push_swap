/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:20:17 by patperez          #+#    #+#             */
/*   Updated: 2026/06/30 10:31:20 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswaplib.h"

t_node_list	*ft_lstnew(int content)
{
	t_node_list	*new_node;

	new_node = malloc(sizeof(t_node_list));
	if (!new_node)
		return (NULL);
	new_node -> next = NULL;
	new_node -> prev = NULL;
	new_node -> index = -1;
	new_node -> content = content;
	return (new_node);
}

t_stack	*ft_newstack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack -> head = NULL;
	stack -> tail = NULL;
	stack -> size = 0;
	return (stack);
}

void	ft_lstadd_front(t_stack *stack, t_node_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack -> tail == NULL) // La lista está vacía
	{
		// Si la lista no tiene nada, el nuevo nodo se convierte automáticamente en el primero (head) y también en el último (tail).
		stack -> head = new_node;
		stack -> tail = new_node;
		new_node->next = new_node; // Apunta a sí mismo
		new_node->prev = new_node; // Apunta a sí mismo
	}
	else // Lista con elementos
	{
		new_node -> next = stack -> head; // 1. El 'next' del nuevo apunta al que ANTES era el primero.
		new_node -> prev = stack -> tail; // 2. lista circular, su 'prev' apunta al último.
		stack -> head -> prev = new_node;
		stack -> tail -> next = new_node;
		stack-> head = new_node; // 3. Ahora el nuevo nodo es oficialmente la nueva cabeza de la lista.
	}
	stack -> size +=1; // 4. Sumamos 1 al contador de tamaño.
}

void	ft_lstadd_back(t_stack *stack, t_node_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack -> head == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
		new_node->next = new_node; // Apunta a sí mismo
		new_node->prev = new_node; // Apunta a sí mismo
	}
	else // Lista con elementos
	{
		new_node -> prev = stack -> tail; // 2. El 'prev' del nuevo nodo apunta al que era el último.
		new_node->next = stack->head;
		stack-> tail-> next = new_node; // 1. El 'next' del que ahora es el último, ahora apuntará al nuevo nodo.
		stack->head->prev = new_node;
		stack -> tail = new_node; // 3. Ahora el nuevo nodo se convierte oficialmente en el último ('tail').
	}
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	stack -> size += 1; // 4. Sumamos 1 al tamaño.
}
