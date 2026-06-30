/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:51:52 by patperez          #+#    #+#             */
/*   Updated: 2026/06/30 08:23:06 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswaplib.h"

void	ft_lstclear(t_stack *lst)
{
	t_node_list	*buffer;
	t_node_list	*tmp;

	buffer = NULL;
	if (!lst)
		return ;
	tmp = lst -> head;
	while (lst->size)
	{
		buffer = tmp-> next;
		free(tmp);
		tmp = buffer;
		lst->size -= 1;
	}
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
	free(lst);
}

int	ft_lstsize(t_node_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
