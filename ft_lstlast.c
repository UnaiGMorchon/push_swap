/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:50:06 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/12 09:00:57 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

t_node_list	*ft_lstlast(t_node_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*lst_head;
	t_list	*result;

	lst_head = NULL;
	
	lst_head = ft_lstnew("position 1");
	lst_head -> next = ft_lstnew("position 2");
	lst_head -> next = ft_lstnew("position 3");
	printf("The first one: %s\n", (char *)lst_head->content);
	printf("Behind of first: %s\n", (char *)lst_head->next->content);
	result = ft_lstlast(lst_head);
	printf("size = %d\n", ft_lstsize(lst_head));
	printf("result = %s\n", (char *)result->content);
}*/