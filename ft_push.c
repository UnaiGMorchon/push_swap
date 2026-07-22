/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:35:09 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:44:20 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declarar una variable puntero 'node_to_move' para almacenar el nodo proveniente de la pila B.
	2. Comprobación de seguridad: si los punteros son NULL o la pila B está vacía, detener la ejecución.
	3. Guardar la cabeza actual de la pila B en 'node_to_move'.
	4. Mover el puntero cabeza de la pila B al siguiente nodo de la lista.
	5. Si la pila B solo tenía 1 nodo, establecer cabeza y cola a NULL (la pila B queda vacía).
	6. Si la pila B tenía más nodos, reconectar prev de la cabeza y next de la cola para mantenerla circular.
	7. Decrementar en 1 el contador del tamaño total de la pila B.
	8. Aislar el nodo movido estableciendo sus punteros next y prev a NULL.
	9. Usar ft_stackadd_front para insertar el nodo aislado en la parte superior de la pila A.
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

/*
	1. Declarar una variable puntero 'tmp' para almacenar el nodo extraído de la pila A.
	2. Comprobación de seguridad: si los punteros son NULL o la pila A está vacía, detener la ejecución.
	3. Guardar la cabeza actual de la pila A en 'tmp'.
	4. Mover el puntero cabeza de la pila A al siguiente nodo de la lista.
	5. Si la pila A solo tenía 1 nodo, establecer cabeza y cola a NULL (la pila A queda vacía).
	6. Si la pila A tenía más nodos, reconectar prev de la cabeza y next de la cola para mantenerla circular.
	7. Decrementar en 1 el contador del tamaño total de la pila A.
	8. Aislar el nodo movido estableciendo sus punteros next y prev a NULL.
	9. Usar ft_stackadd_front para insertar el nodo aislado en la parte superior de la pila B.
*/
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
