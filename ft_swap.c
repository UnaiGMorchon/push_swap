/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:57:52 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/22 13:51:17 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declarar 'temp' para guardar el contenido entero durante el intercambio.
	2. Declarar 'temp_index' para guardar el índice del nodo durante el intercambio.
	3. Comprobación de seguridad: si la pila A no existe o tiene menos de 2 nodos, detener.
	4. Guardar el contenido del primer nodo (cabeza) en la variable 'temp'.
	5. Guardar el índice del primer nodo (cabeza) en la variable 'temp_index'.
	6. Copiar el contenido del segundo nodo en el primer nodo.
	7. Copiar el índice del segundo nodo en el primer nodo.
	8. Mover el contenido original del primer nodo desde 'temp' al segundo nodo.
	9. Mover el índice original del primer nodo desde 'temp_index' al segundo nodo.
	10. Escribir la cadena de operación "sa\n" en la salida estándar.
*/

void	ft_sa(t_stack *lst_a, t_bench *bench)
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
	bench -> sa += 1;
	bench -> total += 1;
	write(1, "sa\n", 3);
}

/*
	1. Declarar 'temp' para guardar el contenido entero durante el intercambio.
	2. Declarar 'temp_index' para guardar el índice del nodo durante el intercambio.
	3. Comprobación de seguridad: si la pila B no existe o tiene menos de 2 nodos, detener.
	4. Guardar el contenido del primer nodo (cabeza) en la variable 'temp'.
	5. Guardar el índice del primer nodo (cabeza) en la variable 'temp_index'.
	6. Copiar el contenido del segundo nodo en el primer nodo.
	7. Copiar el índice del segundo nodo en el primer nodo.
	8. Mover el contenido original del primer nodo desde 'temp' al segundo nodo.
	9. Mover el índice original del primer nodo desde 'temp_index' al segundo nodo.
	10. Escribir la cadena de operación "sb\n" en la salida estándar.
*/

void	ft_sb(t_stack *lst_b, t_bench *bench)
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
	bench -> sb += 1;
	bench -> total += 1;
	write(1, "sb\n", 3);
}

/*
	1. Comprobación de seguridad: verificar que ambas pilas existan y que ambas tengan al menos 2 nodos.
	2. Llamar a ft_sa para intercambiar los dos elementos superiores de la pila A.
	3. Llamar a ft_sb para intercambiar los dos elementos superiores de la pila B.
	4. Escribir la cadena de operación combinada "ss\n" en la salida estándar.
*/

void	ft_ss(t_stack *lst_a, t_stack *lst_b, t_bench *bench)
{
	if (!lst_a || lst_a->size < 2 || !lst_b || lst_b->size < 2)
	{
		ft_sa(lst_a, bench);
		ft_sb(lst_b, bench);
		bench -> ss += 1;
		bench -> sa -= 1;
		bench -> sb -= 1;
		bench -> total -= 1;
		write(1, "ss\n", 3);
	}
}
