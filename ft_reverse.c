/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:54:15 by patperez          #+#    #+#             */
/*   Updated: 2026/06/23 08:44:14 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"
#include <stdio.h>

void	ft_rra(t_node_list **lst_a)
{
	t_node_list	*tmp_newfirst; // Apuntará al nodo que será el nuevo primero (el antiguo último)
	t_node_list	*tmp_newlast; // Apuntará al nodo que será el nuevo último (el antiguo penúltimo)
	t_node_list	*tmp_lst_copy; // Una copia del puntero original para no perder la referencia inicial

	tmp_lst_copy = (*lst_a); // Guarda la dirección del primer nodo en tmp_lst_copy.
	if (!lst_a || lst_a == NULL)
		return ;
	tmp_newfirst = ft_lstlast(tmp_lst_copy); // Busca el último nodo de la lista. Este nodo se convertirá en la nueva cabeza de la lista (tmp_newfirst).
	tmp_newlast = ft_lstfind(&tmp_lst_copy); // Busca el penúltimo nodo. Al pasarle el doble puntero &tmp_lst_copy, la función modifica tmp_lst_copy, pero no modifica la lista real lst_a. Esto guarda el penúltimo nodo en tmp_newlast.
	ft_lstadd_front(lst_a, tmp_newfirst); // Toma el antiguo último nodo (tmp_newfirst) y lo pone al principio de la lista lst_a. Ahora la lista empieza con ese nodo, y el segundo elemento es el que antes era el primero.
	tmp_newlast -> next = NULL; // Marcar el final de la estructura.
}

void	ft_rrb(t_node_list **lst_b)
{
	t_node_list	*tmp_newfirst;
	t_node_list	*tmp_newlast;
	t_node_list	*tmp_lst_copy;

	tmp_lst_copy = (*lst_b);
	if (!lst_b || lst_b == NULL)
		return ;
	tmp_newfirst = ft_lstlast(tmp_lst_copy);
	tmp_newlast = ft_lstfind(&tmp_lst_copy);
	ft_lstadd_front(lst_b, tmp_newfirst);
	tmp_newlast -> next = NULL;
}

void	ft_rrr(t_node_list **lst_a, t_node_list **lst_b)
{
	if ((!lst_a || lst_a == NULL) || (!lst_b || lst_b == NULL))
		return ;
	ft_rra(lst_a);
	ft_rrb(lst_b);
}


int	main(void)
{
	//* STACK_A *
	t_node_list	*lst_a;

	//lst_a = NULL;
	lst_a = ft_lstnew(1);
	ft_lstadd_back(&lst_a, ft_lstnew(12));
	ft_lstadd_back(&lst_a, ft_lstnew(13));
	ft_lstadd_back(&lst_a, ft_lstnew(14));
	ft_lstadd_back(&lst_a, ft_lstnew(15));

	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);	
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
	printf("Fifth A node: %d\n\n", lst_a -> next -> next -> next -> next -> content);
//	printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);

	ft_rra(&lst_a);
	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
	printf("Fifth A node: %d\n", lst_a -> next -> next -> next -> next -> content);
//	printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);


/*	* STACK_B *
	t_node_list   *lst_b;

	//lst_b = NULL;
	lst_b = ft_lstnew(2);
	ft_lstadd_back(&lst_b, ft_lstnew(22));
	ft_lstadd_back(&lst_b, ft_lstnew(23));
	ft_lstadd_back(&lst_b, ft_lstnew(24));
	ft_lstadd_back(&lst_b, ft_lstnew(25));

	printf("First B node: %d\n", lst_b -> content);
	printf("Second B node: %d\n", lst_b -> next -> content);
	printf("Third B node: %d\n\n", lst_b -> next -> next -> content);
	//printf("Fourth B node: %d\n", lst_b -> next -> next -> next -> content);
	//printf("Fifth B node: %d\n\n", 
		lst_b -> next -> next -> next -> next -> content);
	//printf("Sixth B node: %d\n", 
		lst_b -> next -> next -> next -> next -> next -> content);

	ft_reva(&lst_b);
	printf("First B node: %d\n", lst_b -> content);
	printf("Second B node: %d\n", lst_b -> next -> content);
	printf("Third B node: %d\n", lst_b -> next -> next -> content);
	printf("Fourth B node: %d\n", lst_b -> next -> next -> next -> content);
	//printf("Fifth B node: %d\n", 
		lst_b -> next -> next -> next -> next -> content);
	//printf("Sixth B node: %d\n", 
		lst_b -> next -> next -> next -> next -> next -> content);

	ft_revboth(&lst_a, &lst_b);
	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);
	printf("Third A node: %d\n\n", lst_a -> next -> next -> content);
	printf("First B node: %d\n", lst_b -> content);
	printf("Second B node: %d\n", lst_b -> next -> content);
	printf("Third B node: %d\n\n", lst_b -> next -> next -> content);
*/
	ft_lstclear(&lst_a);
	//ft_lstclear(&lst_b);
	return (0);
}
