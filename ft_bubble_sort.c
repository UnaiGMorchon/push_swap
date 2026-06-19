/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/06/19 10:29:14 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	bubble_sort(t_node_list *lst)
{
	int	swapped;
	int	lst_size;
	t_node_list	*circle_back;

	swapped = 1;
	lst_size = ft_lstsize(lst);
	circle_back = *lst;
	ft_lstlast(*lst) -> next = circle_back;
	while (*lst)
	{
		while (lst > lst -> next)
		{
			ft_sa(lst);
			swapped = 0;
			*lst = *lst -> next;
		}
	}
}
