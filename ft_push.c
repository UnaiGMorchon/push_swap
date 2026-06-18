/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:35:09 by patperez          #+#    #+#             */
/*   Updated: 2026/06/18 12:16:25 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"
#include <stdio.h>
#include <stdlib.h>

/* take first element atop b and put it atop a. nothing done if b empty */
void	ft_pa(t_node_list **lst_a, t_node_list **lst_b)
{
	t_node_list	*tmp;

	if (!lst_a || !lst_b)
		return ;
	if (*lst_b == NULL)
		return ;
	tmp = (*lst_b)-> next;
	ft_lstadd_front(lst_a, *lst_b);
	*lst_b = tmp;
}

/* take first element atop a and put it atop b. nothing done if a empty */
void	ft_pb(t_node_list **lst_b, t_node_list **lst_a)
{
	t_node_list	*tmp;

	if (!lst_b || !lst_a)
		return ;
	if (*lst_a == NULL)
		return ;
	tmp = (*lst_a)-> next;
	ft_lstadd_front(lst_b, *lst_a);
	*lst_a = tmp;
}

/*int	main(void)
{
	t_node_list	*lst_a;
	t_node_list	*lst_b;

	lst_a = ft_lstnew(1);
	lst_b = ft_lstnew(2);
	// STACK_A
	ft_lstadd_back(&lst_a, ft_lstnew(12));
	ft_lstadd_back(&lst_a, ft_lstnew(13));
	// STACK_B
	ft_lstadd_back(&lst_b, ft_lstnew(22));

	ft_pa(&lst_a, &lst_b);
	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);
	printf("First B node: %d\n", lst_b -> content);

	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	return (0);
}*/
