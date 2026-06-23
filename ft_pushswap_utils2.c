/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:51:52 by patperez          #+#    #+#             */
/*   Updated: 2026/06/23 11:47:42 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswaplib.h"

void	ft_lstclear(t_node_list **lst)
{
	t_node_list *buffer;

	buffer = NULL;
	if (!lst)
		return ;
	while (*lst)
	{
		buffer = (*lst)-> next;
		free(*lst);
		*lst = buffer;
	}
	free(*lst);
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