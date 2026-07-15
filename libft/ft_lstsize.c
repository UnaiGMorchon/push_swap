/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:11:59 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:57:59 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i; // Contador para almacenar el número de nodos

	i = 0; // Inicializamos el contador en 0
// Bucle de recorrido de la lista enlazada
	// Se ejecutará mientras 'lst' apunte a un nodo válido.
	// Cuando llegue al último nodo, el puntero 'lst->next' valdrá NULL, 
	// haciendo que en la siguiente vuelta 'lst != NULL' sea falso y el bucle termine.
	while (lst != NULL)
	{
		i++; // Sumamos 1 al contador por el nodo actual en el que estamos
		lst = lst->next; // ¡La clave! Avanzamos al siguiente nodo de la lista asignando su dirección a 'lst'
	}
// Devolvemos el total de nodos contados
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
t_list  *lst_head;

	lst_head = NULL;

	// Añadimos "hello" a la lista. La lista ahora es: [ "hello" ] -> NULL
	ft_lstadd_front(&lst_head, ft_lstnew("hello"));

	// Añadimos "world" al frente. La lista ahora es: [ "world" ] -> [ "hello" ] -> NULL
	ft_lstadd_front(&lst_head, ft_lstnew("world"));

	// Imprime el contenido del primer nodo ("world")
	printf("The first one: %s\n", (char *)lst_head->content);

	// Imprime el contenido del segundo nodo ("hello")
	printf("Behind of first: %s\n", (char *)lst_head->next->content);

	// Llama a tu función, que debería contar exactamente 2 nodos.
	printf("Counter = %d\n", ft_lstsize(lst_head));
	return (0);
}*/