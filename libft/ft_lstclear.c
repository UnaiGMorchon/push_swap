/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:54:27 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/20 07:57:24 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp; // Puntero auxiliar para no perder la referencia del siguiente nodo

// 1. Protección inicial contra punteros nulos
	// Verificamos si el puntero doble 'lst' existe, si la lista apunta a algo (*lst) 
	// y si la función de borrado 'del' es válida.
	if (!lst || !del)
		return ;
// 2. Bucle de liberación total
	// Se ejecutará mientras queden nodos en la lista (*lst no sea NULL)
	while (*lst != NULL)
	{
		// ¡La clave! Guardamos la dirección del SIGUIENTE nodo en 'temp' antes de destruir el actual.
		// Si no hiciéramos esto, al hacer free(*lst) perderíamos el puente hacia el resto de la lista.
		temp = (*lst)->next;
		// Liberamos el contenido del nodo actual usando la función 'del'
		del((*lst)->content);
		// Liberamos la estructura del nodo actual
		free((*lst));
		// Avanzamos al siguiente nodo haciendo que '*lst' apunte a lo que guardamos en 'temp'
		*lst = temp;
	}
// 3. Seguridad final
	// Aunque el bucle ya termina cuando *lst es NULL, dejarlo explícito asegura 
	// que el puntero de la función que nos llamó quede limpio y seguro en NULL.
	*lst = NULL;
}
/*
void	ft_del(void * content)
{
	free(content);
}

#include <stdio.h>

int	main(void)
{
	t_list	*node;

	node = ft_lstnew(ft_strdup("hello"));
	ft_lstclear(&node, ft_del);
	if (node == NULL)
		printf("List successfully deleted\n");
	return (0);
}*/
