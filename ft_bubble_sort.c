/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/06/24 09:35:23 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_sa(t_node_list **lst_a)
{
	t_node_list	*temp;

	if (lst_a == NULL || *lst_a == NULL || (*lst_a)->next == NULL)
		return ;
	temp = (*lst_a)->next;
	(*lst_a)->next = temp->next;
	temp->next = (*lst_a);
	(*lst_a) = temp;
}

void	ft_ra(t_node_list **lst)
{
	t_node_list	*tmp_first;
	t_node_list	*tmp_last;

	if (!lst)
		return ;
	if ((*lst) == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	{
		tmp_first = (*lst);
		(*lst) = (*lst)->next;
		tmp_first->next = NULL;
		tmp_last = ft_lstlast(*lst);
		tmp_last->next = tmp_first;
	}
}

void	bubble_sort(t_node_list **lst)
{
	int	swapped; // actuará como un interruptor (booleano) para saber si hubo cambios
	int	size; // guardará el tamaño de la lista,
	int	i; // será el contador para el bucle

// 1. Obtener el tamaño total de la lista
	size = ft_lstsize(*lst); // contar cuántos elementos tiene la lista y guarda ese valor
// 2. Proteger la función: si no hay lista o solo tiene 1 nodo, no hace nada
	if (*lst == NULL || (lst) == NULL || (*lst)-> next == NULL)
		return ;
// 3. Activar el interruptor para entrar al bucle
	swapped = 1; // (verdadero) para asegurar que el bucle while principal se ejecute al menos una vez.
	while (swapped)
	{
		swapped = 0; // Si al final de la vuelta sigue en 0, significa que la lista ya está ordenada y el bucle terminará.
		i = 0;
		// 4. Recorrer la lista nodo por nodo
		while (i < size - 1) // recorrerá la lista nodo por nodo hasta llegar al penúltimo elemento (size - 1)
		{
			// Si el nodo actual es mayor que el siguiente, se intercambian
			if ((*lst)-> content > (*lst)-> next -> content)
			{
				ft_sa(lst); // Intercambia los dos primeros nodos
				swapped = 1; // Hubo un cambio, se necesitará otra vuelta
			}
			ft_ra(lst); // Rota la lista para pasar al siguiente par de nodos
			i ++;
		}
		// 5. Rotación final para reajustar la lista antes de la siguiente pasada
		ft_ra(lst);
	}
}

int	main(void)
{
	t_node_list	*lst_a;

	lst_a = NULL;
	lst_a = ft_lstnew(14);
	ft_lstadd_back(&lst_a, ft_lstnew(12));
	ft_lstadd_back(&lst_a, ft_lstnew(15));
	ft_lstadd_back(&lst_a, ft_lstnew(1));
	ft_lstadd_back(&lst_a, ft_lstnew(13));
	ft_lstadd_back(&lst_a, ft_lstnew(16));
	ft_lstadd_back(&lst_a, ft_lstnew(18));
	ft_lstadd_back(&lst_a, ft_lstnew(2));
	ft_lstadd_back(&lst_a, ft_lstnew(9));

	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
	printf("Fifth A node: %d\n", lst_a -> next -> next -> next -> next -> content);
	printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);
	printf("siete A node: %d\n", lst_a -> next -> next -> next -> next -> next -> next -> content);
	printf("ocho A node: %d\n", lst_a -> next -> next -> next -> next -> next -> next-> next -> content);
	printf("nueve A node: %d\n\n", lst_a -> next -> next -> next -> next -> next -> next-> next -> next -> content);

	bubble_sort(&lst_a);
	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
	printf("Fifth A node: %d\n", lst_a -> next -> next -> next -> next -> content);
	printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);
	printf("siete A node: %d\n", lst_a -> next -> next -> next -> next -> next -> next -> content);
	printf("ocho A node: %d\n", lst_a -> next -> next -> next -> next -> next -> next-> next -> content);
	printf("nueve A node: %d\n\n", lst_a -> next -> next -> next -> next -> next -> next-> next -> next -> content);

	ft_lstclear(&lst_a);
	return (0);
}