/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortlist_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:52:16 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:50:25 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declarar una variable entera 'counter' para hacer el seguimiento de las iteraciones en listas de tamaño 3.
	2. Inicializar 'counter' en 0 antes de comenzar la lógica de ordenación.
	3. Si el tamaño de la pila es exactamente 2, comparar los dos elementos superiores.
	4. Si el índice del primer elemento es mayor que el del segundo, intercambiarlos usando 'ft_sa'.
	5. Si el tamaño de la pila es 3, iniciar un bucle de evaluación para corregir el orden de la pila.
	6. Intercambiar los elementos superiores con 'ft_sa' si la cabeza actual es mayor que el siguiente elemento.
	7. Salir de la función anticipadamente si los elementos ya están en perfecto orden ascendente.
	8. En caso contrario, aplicar una rotación inversa a la pila con 'ft_rra' para desplazar los elementos a su posición.
	9. Incrementar 'counter' para evitar pasadas de ejecución infinitas.
*/

static void	ft_shortlist_under_three(t_stack *lst, t_bench *bench)
{
	int	counter;

	counter = 0;
	if (lst -> size == 2)
	{
		if (lst -> head -> index > lst -> head -> next -> index)
			ft_sa(lst, bench);
	}
	if (lst -> size == 3)
	{
		while (counter < lst -> size)
		{
			if (lst -> head -> index > lst -> head -> next -> index)
				ft_sa(lst, bench);
			else if ((lst -> head -> index < lst -> head -> next -> index)
				&& (lst -> head -> next -> index < lst -> tail -> index)
				&& (lst -> head -> index < lst -> tail -> index))
				return ;
			else
				ft_rra(lst, bench);
			counter++;
		}
	}
}
/*
	1. Declarar el puntero 'lst_b' para la pila auxiliar y el entero 'min_index' para rastrear los objetivos.
	2. Asignar e inicializar una pila vacía 'lst_b'.
	3. Inicializar el objetivo 'min_index' en 0 para buscar secuencialmente los elementos más pequeños.
	4. Iterar mientras el tamaño de la pila principal sea mayor que 3 elementos.
	5. Si el nodo cabeza actual coincide con 'min_index', empujarlo a la pila B usando 'ft_pb' e incrementar el objetivo.
	6. En caso contrario, rotar la pila A con 'ft_ra' para escanear el siguiente elemento.
	7. Ordenar los 3 elementos restantes en la pila A usando 'ft_shortlist_under_three'.
	8. Asegurar que la pila B quede en orden descendente llamando a 'ft_sb' si es necesario.
	9. Empujar todos los elementos de vuelta de la pila B a la pila A usando 'ft_pa'.
	10. Liberar la memoria asignada para la pila auxiliar B.
*/

static void	ft_shortlist_under_five(t_stack *lst, t_bench *bench)
{
	t_stack		*lst_b;
	int			min_index;

	lst_b = ft_newstack();
	min_index = 0;
	while (lst -> size > 3)
	{
		if (lst -> head -> index == min_index)
		{
			ft_pb(lst_b, lst, bench);
			min_index++;
		}
		else
			ft_ra(lst, bench);
	}
	ft_shortlist_under_three(lst, bench);
	if (lst_b -> head -> index < lst_b -> head -> next -> index)
		ft_sb(lst_b, bench);
	while (lst_b -> size)
		ft_pa(lst, lst_b, bench);
	ft_clearstack(lst_b);
}
/*
	1. Comprobar si el tamaño de la pila es 3 o menor, y delegar en 'ft_shortlist_under_three'.
	2. Comprobar si el tamaño de la pila es 4 o 5, y delegar en 'ft_shortlist_under_five'.
	3. Liberar la memoria asociada con la estructura de la pila principal una vez finalizada la ordenación.
*/

void	ft_shortlist_sort(t_stack *lst, t_bench *bench)
{
	if (lst -> size <= 3)
		ft_shortlist_under_three(lst, bench);
	if (lst -> size == 4 || lst -> size == 5)
		ft_shortlist_under_five(lst, bench);
	ft_clearstack(lst);
}
