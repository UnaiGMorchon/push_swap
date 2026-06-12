/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:54:15 by patperez          #+#    #+#             */
/*   Updated: 2026/06/12 13:44:18 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"
#include <stdio.h>

void	ft_reva(t_node_list **lst_a)
{
	t_node_list *tmp_last;
    
	if (!lst_a)
		return ;
	tmp_last = ft_lstlast(*lst_a);
	(ft_lstfind(lst_a, tmp_last)) -> next = NULL;
	ft_lstadd_front(lst_a, tmp_last);
//	*lst_a = tmp_last;
}

int	main(void)
{
	t_node_list   *lst_a;
	t_node_list   *lst_b;
	t_node_list   *node_a;
	t_node_list   *node_b;

	lst_a = NULL;
	lst_b = NULL;
	node_a = ft_lstnew(1);
	node_b = ft_lstnew(2);
	/* STACK_A */
	ft_lstadd_back(&lst_a, node_a);
	ft_lstadd_back(&lst_a, ft_lstnew(12));
	ft_lstadd_back(&lst_a, ft_lstnew(13));
	/* STACK_B */
	ft_lstadd_back(&lst_b, node_b);
	ft_lstadd_back(&lst_b, ft_lstnew(22));

	/*while (lst_a)
	{
		printf("%d\n", lst_a -> content);
		lst_a = lst_a -> next;
	}
	while (lst_b)
	{
	printf("%d\n", lst -> content);
		lst_b = lst -> next;
	}
	printf("Salida\n\n");*/

    ft_reva(&lst_a);
	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("FOURTH A node: %d\n", lst_a -> next -> next -> next -> content);
	//printf("First B node: %d\n", lst_b -> content);

	return (0);
}
