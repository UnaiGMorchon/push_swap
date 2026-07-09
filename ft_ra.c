/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:53:15 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/18 15:46:40 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_ra(t_node_list **lst)
{
	t_node_list	*tmp_first;
	t_node_list	*tmp_last;

	if (!lst)
		return ;
	if ((*lst) == NULL || lst == NULL || (*lst)->next == NULL)
		return ;
	{
		tmp_first = (*lst);
		(*lst) = (*lst)->next;
		tmp_first->next = NULL;
		tmp_last = ft_lstlast(*lst);
		tmp_last->next = tmp_first;
	}
}

void    ft_rb(t_node_list **lst)
{
	t_node_list *tmp_first;
	t_node_list *tmp_last;

	if (!lst)
		return ;
	if ((*lst) == NULL || lst == NULL || (*lst)->next == NULL)
		return ;
	{
		tmp_first = (*lst);
		(*lst) = (*lst)->next;
		tmp_first->next = NULL;
		tmp_last = ft_lstlast(*lst);
		tmp_last->next = tmp_first;
	}
}

void	ft_rr(t_node_list **lst_a, t_node_list **lst_b)
{
	if ((!lst_a || lst_a == NULL) || (!lst_b || lst_b == NULL))
		return ;
	ft_ra(lst_a);
	ft_rb(lst_b);
}

/*int main(void)
{
	t_node_list nodo1;
	t_node_list nodo2;
	t_node_list nodo3;
	t_node_list *mi_lista;

	// 1. Configuramos los contenidos de los nodos
	nodo1.content = 8;
	nodo2.content = 14;
	nodo3.content = 66;

	// 2. Creamos los enlaces de la lista (nodo1 -> nodo2 -> nodo3 -> NULL)
	nodo1.next = &nodo2; 
	nodo2.next = &nodo3;
	nodo3.next = NULL;

	// El puntero "head" de la lista apunta al primer nodo
	mi_lista = &nodo1;

	// --- ESTADO INICIAL ---
	printf("--- Antes del rotate (ft_ra) ---\n");
	printf("1º Nodo (Cabeza): %d\n", mi_lista->content);
	printf("2º Nodo:          %d\n", mi_lista->next->content);
	printf("3º Nodo (Cola):   %d\n\n", mi_lista->next->next->content);

	// 3. Llamamos a tu función pasándole la dirección del puntero
	ft_ra(&mi_lista);

	// --- ESTADO FINAL ---
	// Tras ft_ra, el orden debería ser: nodo2 (14) -> nodo3 (66) -> nodo1 (8) -> NULL
	printf("--- Después del rotate (ft_ra) ---\n");
	printf("1º Nodo (Cabeza): %d\n", mi_lista->content);
	printf("2º Nodo:          %d\n", mi_lista->next->content);
	printf("3º Nodo (Cola):   %d\n", mi_lista->next->next->content);

	// Verificación de seguridad: el último nodo ahora debe apuntar a NULL
	if (mi_lista->next->next->next == NULL)
	printf("\n¡Perfecto! El último nodo apunta a NULL correctamente.\n");
	else
		printf("\n¡Error! La lista no termina en NULL.\n");

	return (0);
}*/
