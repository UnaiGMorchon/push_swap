/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:53:15 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/22 13:49:38 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declarar un puntero 'tmp_first' para guardar la cabeza actual de la pila.
	2. Comprobación de seguridad: si la pila A no existe o tiene menos de 2 elementos, detener.
	3. Guardar el primer nodo actual (cabeza) en la variable 'tmp_first'.
	4. Mover el puntero cabeza de la pila hacia adelante al segundo nodo de la lista.
	5. Actualizar el puntero cola de la pila para que coincida con el nuevo final de la lista.
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
	1. Declarar un puntero 'tmp_first' para guardar la cabeza actual de la pila.
	2. Comprobación de seguridad: si la pila B no existe o tiene menos de 2 elementos, detener.
	3. Guardar el primer nodo actual (cabeza) en la variable 'tmp_first'.
	4. Mover el puntero cabeza de la pila hacia adelante al segundo nodo de la lista.
	5. Actualizar el puntero cola de la pila para que coincida con el nuevo final de la lista.
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
	1. Comprobación de seguridad: verificar que ambas pilas existan y que ambas tengan al menos 2 nodos.
	2. Llamar a ft_ra para rotar la pila A (desplaza el elemento superior al fondo).
	3. Llamar a ft_rb para rotar la pila B (desplaza el elemento superior al fondo).
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
