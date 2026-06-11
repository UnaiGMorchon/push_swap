/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:56:15 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/11 11:59:07 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_sb(t_list **lst)
{
	t_list	*temp;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	temp->next = (*lst)->next;
	
	
}