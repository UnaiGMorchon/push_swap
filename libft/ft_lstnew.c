/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:52:14 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 09:00:38 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_nodo; // Declaramos un puntero al tipo de estructura t_list

// 1. Reserva de memoria
	// Solicitamos a la RAM el espacio exacto que ocupa nuestra estructura t_list
	new_nodo = (t_list *)malloc(sizeof(t_list));
// Protección clásica de malloc: si el sistema se queda sin memoria,
	// devolvemos NULL para evitar futuros fallos de segmento.
	if (!new_nodo)
		return (NULL);
// 2. Inicialización de los miembros de la estructura
	// Asignamos el puntero 'content' que recibimos por parámetro al miembro 'content' del nodo.
	// Al ser de tipo 'void *', puede almacenar cualquier tipo de dato (un string, un int, otra estructura...).
	new_nodo->content = content;
// ¡Muy importante! Todo nodo nuevo nace "huérfano". 
	// Inicializamos su puntero 'next' a NULL para indicar que, por ahora, no tiene a nadie detrás.
	new_nodo->next = NULL;
// 3. Devolvemos el puntero al nodo que acabamos de crear
	return (new_nodo);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*nodo;

// Creamos un nuevo nodo que almacena el string "Hello world"
	nodo = ft_lstnew("Hello world");

	if (nodo)
	{
		printf("Nodo content: %s\n", (char *)nodo->content);
	// Recordatorio de buenas prácticas: al terminar de probar en el main, 
	// deberías liberar la memoria reservada por el nodo.
	free(nodo);
	}
	return (0);
}*/