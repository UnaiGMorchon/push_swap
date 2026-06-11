/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:56:15 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/11 15:08:47 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stack **lst_b)
{
	t_stack	*temp;

	if (lst_b == NULL || *lst_b == NULL || (*lst_b)->next == NULL)
		return ;
	temp = (*lst_b)->next;
	(*lst_b)->next = temp->next;
	temp->next = (*lst_b);
	(*lst_b) = temp;
	write(1, "sb\n", 3);
}

int	main(void)
{
	t_stack	nodo1;
	t_stack	nodo2;
	t_stack	nodo3;
	t_stack	*mi_lista;

	nodo1.value = 8;
	nodo1.next = &nodo2;

	nodo2.value = 14;
	nodo2.next = NULL;

	mi_lista = &nodo1;

	printf("Antes del swap:\n");
	printf("1º Nodo: %d\n", mi_lista->value);
	printf("2º Nodo: %d\n", mi_lista->next->value);

	ft_sb(&mi_lista);

	printf("Después del swap:\n");
	printf("1º Nodo: %d\n", mi_lista->value);
	printf("2º Nodo: %d\n", mi_lista->next->value);
	return (0);
}
