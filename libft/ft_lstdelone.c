/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:22:24 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:11:33 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
// 1. Protección inicial contra punteros nulos
	// Si el nodo no existe (lst == NULL) O la función de borrado 'del' es nula,
	// salimos inmediatamente para evitar un fallo de segmento.
	if (!lst || !del)
		return ;
// 2. Liberación del contenido del nodo
	// Pasamos el miembro 'content' a la función 'del'. 
	// Esto es necesario porque el contenido puede requerir su propia lógica de liberación
	// (por ejemplo, si es una cadena duplicada con malloc o una estructura compleja).
	del(lst -> content);
// 3. Liberación de la estructura del nodo
	// Una vez que el interior del nodo está limpio, liberamos la memoria 
	// del "eslabón" (la estructura t_list) propiamente dicha.
	free(lst);
}
/*
static void	ft_del(void * content)
{
	free(content);
}

int	main(void)
{
	t_list	*node;

// 1. Creamos un contenido dinámico seguro con ft_strdup (o strdup)
	// 2. Creamos el nodo con ft_lstnew
	node = ft_lstnew(ft_strdup("hello"));
// Verificamos que se haya creado correctamente antes de borrarlo
	if (node)
	{
		printf("content before to erase: %s\n", (char *)node->content);
		// Llamamos a tu función pasándole el puntero 'node'
		ft_lstdelone(node, ft_del);
		printf("¡Nodo free!\n");
	}
	return (0);
}
*/