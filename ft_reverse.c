/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:54:15 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:49:00 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declarar un puntero 'tmp_newlast' para guardar el nodo que se convertirá en la nueva cola.
	2. Asignar la cabeza actual a la variable temporal (valor inicial de guardia).
	3. Comprobación de seguridad: si el puntero de la pila no existe, salir de la función.
	4. Localizar el nodo justo anterior a la cola actual y guardarlo como la nueva cola.
	5. Desplazar el puntero cabeza de la pila hacia atrás para apuntar al nodo cola actual.
	6. Actualizar el puntero cola de la pila para que apunte al nodo 'tmp_newlast' guardado.
*/

void	ft_rra(t_stack *lst_a, t_bench *bench)
{
	t_node_list	*tmp_newlast;

	tmp_newlast = lst_a -> head;
	if (!lst_a || lst_a == NULL)
		return ;
	tmp_newlast = lst_a -> tail-> prev;
	lst_a -> head = lst_a -> tail;
	lst_a -> tail = tmp_newlast;
	bench -> rra += 1;
	bench -> total += 1;
	write(1, "rra\n", 4);
}

/*
	1. Declarar un puntero 'tmp_newlast' para guardar el nodo que se convertirá en la nueva cola.
	2. Asignar la cabeza actual a la variable temporal (valor inicial de guardia).
	3. Comprobación de seguridad: si el puntero de la pila no existe, salir de la función.
	4. Localizar el nodo justo anterior a la cola actual y guardarlo como la nueva cola.
	5. Desplazar el puntero cabeza de la pila hacia atrás para apuntar al nodo cola actual.
	6. Actualizar el puntero cola de la pila para que apunte al nodo 'tmp_newlast' guardado.
*/

void	ft_rrb(t_stack *lst_b, t_bench *bench)
{
	t_node_list	*tmp_newlast;

	tmp_newlast = lst_b -> head;
	if (!lst_b || lst_b == NULL)
		return ;
	tmp_newlast = lst_b -> tail-> prev;
	lst_b -> head = lst_b -> tail;
	lst_b -> tail = tmp_newlast;
	bench -> rrb += 1;
	bench -> total += 1;
	write(1, "rrb\n", 4);
}

/*
	1. Comprobación de seguridad: si la pila A o la pila B no existen, detener la ejecución.
	2. Llamar a ft_rra para realizar una operación de rotación inversa en la pila A.
	3. Llamar a ft_rrb para realizar una operación de rotación inversa en la pila B.
*/

void	ft_rrr(t_stack *lst_a, t_stack *lst_b, t_bench *bench)
{
	if ((!lst_a || lst_a == NULL) || (!lst_b || lst_b == NULL))
		return ;
	ft_rra(lst_a, bench);
	ft_rrb(lst_b, bench);
	bench -> rrr += 1;
	bench -> rra -= 1;
	bench -> rrb -= 1;
	bench -> total -= 1;
	write(1, "rrr\n", 4);
}
