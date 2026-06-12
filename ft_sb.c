/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:56:15 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/12 10:15:41 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_sb(t_node_list **lst_b)
{
	t_node_list	*temp;

	if (lst_b == NULL || *lst_b == NULL || (*lst_b)->next == NULL)
		return ;
	temp = (*lst_b)->next;
	(*lst_b)->next = temp->next;
	temp->next = (*lst_b);
	(*lst_b) = temp;
	write(1, "sb\n", 3);
}
/*
int	main(void)
{
	t_node_list	nodo1;
	t_node_list	nodo2;
	t_node_list	nodo3;
	t_node_list	*mi_lista;

	nodo1.content = 8;
	nodo1.next = &nodo2;

	nodo2.content = 14;
	nodo2.next = NULL;

	mi_lista = &nodo1;

	printf("Antes del swap:\n");
	printf("1º Nodo: %d\n", mi_lista->content);
	printf("2º Nodo: %d\n", mi_lista->next->content);

	ft_sb(&mi_lista);

	printf("Después del swap:\n");
	printf("1º Nodo: %d\n", mi_lista->content);
	printf("2º Nodo: %d\n", mi_lista->next->content);
	return (0);
}*/
