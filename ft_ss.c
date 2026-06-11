/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:42:04 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/11 14:49:36 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **lst_a)
{
	t_stack	*temp;

	if (lst_a == NULL || *lst_a == NULL || (*lst_a)->next == NULL)
		return ;
	temp = (*lst_a)->next;
	(*lst_a)->next = temp->next;
	temp->next = (*lst_a);
	(*lst_a) = temp;
	write(1, "sa\n", 3);
}

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

void	ft_ss(t_stack **lst_a, t_stack **lst_b)
{
	ft_sa(*lst_a);
	ft_sb(*lst_b);
}
