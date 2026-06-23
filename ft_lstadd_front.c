/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:28:52 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/23 12:11:35 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_lstadd_front(t_node_list **lst, t_node_list *new)
{
// 1. Protección contra punteros nulos
	// Si el puntero doble 'lst' no existe (no apunta a una dirección válida de la variable cabeza)
	// O si el nodo 'new' que queremos añadir es NULL, no hacemos nada y salimos.
	if (!lst || !new)
		return ;
// 2. Conectar el nuevo nodo a la lista existente
	// Hacemos que el puntero 'next' del nuevo nodo apunte hacia donde apunta actualmente '*lst'
	// (es decir, el que hasta ahora era el primer nodo de la lista).
	// NOTA: Si la lista estaba vacía (*lst == NULL), 'new->next' pasará a ser NULL de forma correcta.
	new->next = *lst;
// 3. Actualizar la cabeza de la lista
	// Ahora que el nuevo nodo está bien enganchado a la cadena, modificamos el puntero original
	// de la lista (*lst) para que apunte a 'new'. El nuevo nodo es oficialmente el primero.
	*lst = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*lst_head;

	lst_head = NULL; // Inicializamos la lista vacía
// 1. Añadimos el nodo "hello". 
	// Como lst_head era NULL, la lista pasa a ser: ["hello"] -> NULL
	ft_lstadd_front(&lst_head, ft_lstnew("hello"));
// 2. Añadimos el nodo "world" al frente.
	// El 'next' de "world" apuntará a "hello".
	// 'lst_head' se actualiza para apuntar a "world".
	// La lista ahora es: ["world"] -> ["hello"] -> NULL
	ft_lstadd_front(&lst_head, ft_lstnew("world"));
// Debería imprimir: "world"
	printf("The first one: %s\n", (char *)lst_head->content);
// Debería imprimir: "hello"
	printf("Behind of first: %s\n", (char *)lst_head->next->content);
}
*/