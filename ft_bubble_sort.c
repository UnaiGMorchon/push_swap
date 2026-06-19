/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/06/19 13:44:39 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

static void	swapper(t_node_list **lst, int swapped)
{
	
}

void	bubble_sort(t_node_list **lst)
{
	int	swapped;
	int	lst_size;
	t_node_list	*head;

	if (!lst)
		return (NULL);
	(*head) -> next = *lst;
	lst_size = ft_lstsize(lst);
	swapped = lst_size;
	while (*lst && swapped > 0)
	{
		if ((*lst) -> content > (*lst) -> next -> content)
			ft_sa(*lst);
		else
			swapped--;
		*lst = (*lst) -> next;
	}
	if (swapped == 0)
		return (*lst);
	else
	{
		swapped = lst_size;
		head -> next = *lst;
	}
}
