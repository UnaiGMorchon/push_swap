/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 08:23:06 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:07:39 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
// 1. Protección inicial contra punteros nulos
	// Si la lista está vacía (lst == NULL) O el puntero a la función 'f' no existe,
	// salimos inmediatamente para evitar un fallo de segmento.
	if (!lst || !f)
		return ;
// 2. Bucle principal de recorrido
	// Recorremos la lista mientras 'lst' apunte a un nodo válido.
	while (lst != NULL)
	{
		// Llamamos a la función 'f' pasándole como argumento el contenido del nodo actual.
		f(lst->content);
		// Avanzamos al siguiente nodo de la lista
		lst = lst->next;
	}
}
/*
#include <stdio.h>

static void	ft_f(void *content)
{
	printf("elements: %s\n", (char *)content);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew("Apple");
	node2 = ft_lstnew("Bannana");
	node3 = ft_lstnew("Cherry");
	node1->next = node2;
	node2->next = node3;
	ft_lstiter(node1, &ft_f);

	return (0);
}
*/