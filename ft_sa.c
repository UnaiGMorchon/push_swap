/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:57:52 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/11 12:55:38 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **lst)
{
	t_list	*temp;

// Protegemos la función: si la lista está vacía o tiene un solo nodo, no hacemos nada
	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
// Intercambiamos los nodos
// 1. Guardamos el nodo B en la variable temp.
// El dueño del cable es (*lst) (que es el primer nodo). Su cable apunta a B.
	temp = (*lst)->next; // Guardamos el SEGUNDO nodo (B) en temp
// 2. Conectamos el primer nodo con el tercer nodo.
// El dueño del cable SIGUE SIENDO (*lst) (el primer nodo).
// Pero borramos su destino y lo cambiamos por temp->next (que es el tercer nodo).
	(*lst)->next = temp->next; // Conectamos el PRIMER nodo (A) con el TERCER nodo (C)
// 3. Conectamos el segundo nodo con el primer nodo.
// El dueño del cable ahora es temp (que es el segundo nodo).
// Hacemos que su cable apunte a (*lst) (que es el primer nodo).
	temp->next = (*lst); // Conectamos el SEGUNDO nodo (B) para que apunte al PRIMERO (A)
// 4. Cambiamos el inicio de la lista.
// Decimos que la lista entera (*lst) ahora empieza en el nodo que guardamos en temp.
	(*lst) = temp; // Hacemos que la cabeza de la lista apunte al SEGUNDO nodo (B)
	// Imprimimos el movimiento
	write(1, "sa\n", 3);
}

int	main(void)
{
	t_list	nodo1;
	t_list	nodo2;
	t_list	nodo3;
	t_list	*mi_lista;

	// 1. Configuramos el primer nodo
	nodo1.content = "Hola";
	nodo1.next = &nodo2; // Apunta al segundo nodo

	// 2. Configuramos el segundo nodo
	nodo2.content = "Mundo";
	nodo2.next = NULL;   // Es el final de la lista

// 2. Configuramos el segundo nodo
	nodo3.content = "verde";
	nodo3.next = NULL;   // Es el final de la lista

	
	// 3. El puntero de la lista apunta al primer nodo
	mi_lista = &nodo1;

	// Mostramos el estado inicial
	printf("Antes del swap:\n");
	printf("1º Nodo: %s\n", (char *)mi_lista->content);
	printf("2º Nodo: %s\n", (char *)mi_lista->next->content);
	//printf("3º Nodo: %s\n\n", (char *)mi_lista->next->next->content);

	// 4. Llamamos a tu función pasándole la dirección del puntero
	ft_sa(&mi_lista);

	// Mostramos el resultado
	printf("Después del swap:\n");
	printf("1º Nodo: %s\n", (char *)mi_lista->content);
	printf("2º Nodo: %s\n", (char *)mi_lista->next->content);
	//printf("3º Nodo: %s\n\n", (char *)mi_lista->next->next->content);
	return (0);
}