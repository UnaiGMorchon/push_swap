/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:57:52 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/09 15:45:36 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **lst)
{
	void	*temp;

// Protegemos la función: si la lista está vacía o tiene un solo nodo, no hacemos nada
	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;

// Intercambiamos los contenidos
	temp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = temp;

	// Imprimimos el movimiento
	write(1, "sa\n", 3);
}

int	main(void)
{
	t_list  nodo1;
	t_list  nodo2;
	t_list  *mi_lista;

	// 1. Configuramos el primer nodo
	nodo1.content = "Hola";
	nodo1.next = &nodo2; // Apunta al segundo nodo

	// 2. Configuramos el segundo nodo
	nodo2.content = "Mundo";
	nodo2.next = NULL;   // Es el final de la lista

	// 3. El puntero de la lista apunta al primer nodo
	mi_lista = &nodo1;

	// Mostramos el estado inicial
	printf("Antes del swap:\n");
	printf("1º Nodo: %s\n", (char *)mi_lista->content);
	printf("2º Nodo: %s\n\n", (char *)mi_lista->next->content);

	// 4. Llamamos a tu función pasándole la dirección del puntero
	ft_sa(&mi_lista);

	// Mostramos el resultado
	printf("Después del swap:\n");
	printf("1º Nodo: %s\n", (char *)mi_lista->content);
	printf("2º Nodo: %s\n", (char *)mi_lista->next->content);
	return (0);
}