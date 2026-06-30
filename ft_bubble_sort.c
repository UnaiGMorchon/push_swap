/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/06/30 09:44:39 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_sa(t_stack *lst_a)
{
	int	temp;
// Verificar si la lista existe y si tiene al menos dos elementos para poder intercambiar
	if (lst_a == NULL || lst_a->size < 2)
		return ;
// 1. Guardar el valor del primer nodo en una variable temporal
	temp = lst_a-> head->content;
// 2. Copiar el valor del segundo nodo en el primer nodo
	lst_a ->head-> content = lst_a ->head->next-> content;
// 3. Pasar el valor original del primer nodo (guardado en temp) al segundo nodo
	lst_a->head->next->content = temp;
	write(1, "sa\n", 3);
}

void	ft_ra(t_stack *lst_a)
{
	t_node_list	*tmp_first;

	if (!lst_a)
		return ;
// 1. Guardas de seguridad: comprobar que la lista exista y tenga al menos dos nodos
	if (lst_a == NULL || lst_a == NULL || lst_a -> head-> next == NULL)
		return ;
// 2. Guardar el nodo que actualmente está al principio en una variable temporal
	tmp_first = lst_a -> head;
// 3. Mover la cabeza de la lista al segundo nodo (el segundo pasa a ser el primero)
	lst_a -> head = lst_a-> head -> next;
// 4. Conectar el antiguo primer nodo al final de la lista (después del actual tail)
	lst_a -> tail -> next = tmp_first;
// 5. Actualizar el puntero tail para que apunte al nuevo último nodo
	lst_a -> tail = tmp_first;
}

void	bubble_sort(t_stack *lst)
{
	int	swapped;
	int	i;

	if (lst == NULL || lst-> head -> next == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < lst -> size - 1)
		{
			if (lst-> head-> content > lst-> head -> next -> content)
			{
				ft_sa(lst);
				swapped = 1;
			}
			ft_ra(lst);
			i ++;
		}
		ft_ra(lst);
	}
}
/* 
static void	ft_print_list(t_stack *stack, int size)
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
}

int	main(void)
{
	t_stack	*lst_a;

	lst_a = ft_newstack();
	// STACK_A
	ft_lstadd_back(lst_a, ft_lstnew(12));
	ft_lstadd_back(lst_a, ft_lstnew(15));
	ft_lstadd_back(lst_a, ft_lstnew(1));
	ft_lstadd_back(lst_a, ft_lstnew(13));
	ft_lstadd_back(lst_a, ft_lstnew(16));
	ft_lstadd_back(lst_a, ft_lstnew(18));
	ft_lstadd_back(lst_a, ft_lstnew(2));
	ft_lstadd_back(lst_a, ft_lstnew(9));
	// STACK_B

	printf("---------------STACK A-----------\n");
	ft_print_list(lst_a, lst_a -> size);

	bubble_sort(lst_a);
	printf("---------------sorted--------------- \n");
	ft_print_list(lst_a, lst_a -> size);
	printf("---------------%d lista tamaño A-----------\n", lst_a-> size);
	ft_lstclear(lst_a);
	return (0);
} */
