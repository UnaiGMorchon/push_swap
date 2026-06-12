/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:20:17 by patperez          #+#    #+#             */
/*   Updated: 2026/06/12 09:23:36 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswaplib.h"

t_node_list	*ft_lstnew(int content)
{
	t_node_list	*new_node;

	new_node = malloc(sizeof(t_node_list));
	if (!new_node)
		return (NULL);
	new_node -> next = NULL;
	new_node -> content = content;
	return (new_node);
}

t_node_list	*ft_lstlast(t_node_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_front(t_node_list **lst, t_node_list *new_node)
{
	if (!lst || !new_node)
		return ;
	new_node -> next = *lst;
	*lst = new_node;
}

void	ft_lstadd_back(t_node_list **lst, t_node_list *new_node)
{
	t_node_list	*last;

	if (!lst || !new_node)
		return ;
	new_node -> next = NULL;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = new_node;
}
