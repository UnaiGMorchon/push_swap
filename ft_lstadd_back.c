/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:22:09 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/26 12:14:56 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_lstadd_back(t_node_list **lst, t_node_list *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return ;
	if ((*lst))
	{
		tmp = ft_lstlast(*lst);
		tmp->head->next = new;
	}
	else
		*lst = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*lst_head;

	lst_head = NULL;
	ft_lstadd_front(&lst_head, ft_lstnew("hello"));
	ft_lstadd_front(&lst_head, ft_lstnew("world"));
	printf("The first one: %s\n", (char *)lst_head->content);
	printf("Behind of first: %s\n", (char *)lst_head->next->content);
	ft_lstadd_back(&lst_head, ft_lstnew("green"));
	while (lst_head)
	{
		printf("result = %s\n", (char *)lst_head->content);
		lst_head = lst_head ->next;
	}
}*/
