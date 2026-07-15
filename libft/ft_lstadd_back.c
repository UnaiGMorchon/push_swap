/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:22:09 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:17:11 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp; // Puntero auxiliar para almacenar el último nodo actual

// 1. Protección contra punteros nulos
	// Si el puntero doble 'lst' no apunta a una dirección válida 
	// O si el nodo 'new' que queremos colgar no existe, salimos inmediatamente.
	if (!lst || !new)
		return ;
// 2. CASO A: La lista ya contiene nodos
	if ((*lst))
	{
	// Llamamos a 'ft_lstlast' pasándole la cabeza de la lista (*lst).
	// Esta función recorrerá el tren y nos devolverá la dirección del último vagón.
		tmp = ft_lstlast(*lst);
	// Conectamos el 'next' del que era el último nodo hacia el nuevo nodo ('new').
	// Ahora 'new' pasa a ser oficialmente el final de la lista.
		tmp->next = new;
	}
// 3. CASO B: La lista está completamente vacía (*lst == NULL)
	else
	// Si no hay ningún nodo en la lista, el nuevo nodo no se añade "detrás" de nadie;
	// se convierte directamente en el primer y único nodo (la cabeza).
		*lst = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*lst_head;

	lst_head = NULL;
	ft_lstadd_front(&lst_head, ft_lstnew("hello"));
	ft_lstadd_front(&lst_head, ft_lstnew("world"));
	printf("The first one: %s\n", (char *)lst_head->content);
	printf("Behind of first: %s\n", (char *)lst_head->next->content);
	ft_lstadd_back(&lst_head, ft_lstnew("green"));
	while (lst_head)
	{
		printf("result = %s\n", (char *)lst_head->content);
		lst_head = lst_head ->next;
	}
}*/
