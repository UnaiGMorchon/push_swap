/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:50:06 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:06:22 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
// 1. Protección contra listas vacías
	// Si el puntero 'lst' es NULL (la lista no tiene ningún nodo),
	// no hay último elemento que buscar, así que devolvemos NULL inmediatamente.
	if (!lst)
		return (NULL);
// 2. Bucle de navegación
	// Queremos detenernos EXACTAMENTE en el último nodo.
	// El último nodo se reconoce porque su puntero 'next' apunta a NULL.
	// Por tanto, avanzamos mientras 'lst->next' NO sea NULL.
	while (lst->next != NULL)
	{
		lst = lst->next; // Avanzamos al siguiente nodo de la lista
	}
// 3. Retorno
	// Al salir del bucle, 'lst->next' es NULL, lo que significa que 'lst'
	// está apuntando ahora mismo al último nodo real de la lista. Lo devolvemos.
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*lst_head;
	t_list	*result;

	lst_head = NULL;
	
	lst_head = ft_lstnew("position 1");
	lst_head -> next = ft_lstnew("position 2");
	lst_head -> next = ft_lstnew("position 3");
	printf("The first one: %s\n", (char *)lst_head->content);
	printf("Behind of first: %s\n", (char *)lst_head->next->content);
	result = ft_lstlast(lst_head);
	printf("size = %d\n", ft_lstsize(lst_head));
	printf("result = %s\n", (char *)result->content);
}*/