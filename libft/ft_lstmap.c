/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:39:22 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/03 09:54:50 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list; // Puntero a la cabeza de la nueva lista que vamos a devolver
	void	*content;  // Variable temporal para guardar el contenido transformado por 'f'
	t_list	*new_nodo; // Variable temporal para el nodo que fabricamos en cada vuelta

// 1. Protección inicial contra punteros nulos
	if (!lst || !del || !f)
		return (NULL);
	new_list = NULL; // Inicializamos la nueva lista como vacía
// 2. Bucle principal: Recorremos la lista original
	while (lst != NULL)
	{
	// A. Aplicamos la función 'f' al contenido del nodo actual
		content = f(lst->content);
	// B. Creamos un nuevo nodo utilizando el contenido transformado
		new_nodo = ft_lstnew(content);
	// C. GESTIÓN DE ERRORES CRÍTICA: ¿Qué pasa si ft_lstnew falla (falla malloc)?
		if (new_nodo == NULL)
		{
			// Borramos el contenido transformado que se quedó flotando en memoria
			del(content); 
			// Destruimos toda la nueva lista que habíamos construido hasta ahora
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		// D. Si todo fue bien, añadimos el nuevo nodo al final de nuestra nueva lista
		ft_lstadd_back(&new_list, new_nodo);
		// E. Avanzamos al siguiente nodo de la lista original
		lst = lst->next;
	}
	// 3. Devolvemos el puntero al inicio de la nueva lista duplicada y mapeada
	return (new_list);
}
/* 
#include <stdio.h>

// Función de mapeo correcta: Recibe un string, lo muestra y devuelve una copia en malloc
static void	*ft_f(void *content)
{
	printf("elements: %s\n", (char *)content);
	// Devolvemos una copia exacta en memoria dinámica para que pueda ser liberada legítimamente
}

// Función de borrado
static void	ft_del(void *content)
{
	free(content);
} */

/* int	main(void)
{
	t_list	*lst_head;

// IMPORTANTE: El contenido del primer nodo NO puede ser un literal directo 
	// si va a pasar por funciones que puedan liberar la lista original más tarde.
	// Para este main de prueba rápido, usaremos un strdup para el nodo inicial.
	lst_head = ft_lstnew("hello");
	printf("list: %s\n", (char *)lst_head->content);
// Ejecutamos tu función ft_lstmap
	ft_lstmap(lst_head, ft_f, ft_del);
	return (0);
}
 */