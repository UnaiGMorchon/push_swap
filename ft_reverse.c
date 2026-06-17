/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:54:15 by patperez          #+#    #+#             */
/*   Updated: 2026/06/17 15:21:14 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"
#include <stdio.h>

void	ft_reva(t_node_list **lst_a)
{
	t_node_list *tmp_newfirst;
    t_node_list	*tmp_newlast;
    t_node_list *tmp_lst_copy;
	t_node_list	*to_delete;

    tmp_lst_copy = (*lst_a);
	if (!lst_a || lst_a == NULL)
		return ;
	tmp_newfirst = ft_lstlast(tmp_lst_copy); // saves last node "15" 
	while (tmp_lst_copy && tmp_lst_copy -> next -> next != NULL)
	{
		if (tmp_lst_copy -> next -> next == NULL)
		{
			tmp_newlast = tmp_lst_copy;
			to_delete = tmp_lst_copy -> next;
			to_delete = NULL;
			free(to_delete);
		}
		tmp_lst_copy = tmp_lst_copy -> next;
	}
	ft_lstadd_back(lst_a, tmp_newlast);
	ft_lstadd_front(lst_a, tmp_newfirst); // pushes "15" to top of list
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
	//ft_lstadd_back(&lst_a, ft_lstnew(14));
    //ft_lstadd_back(&lst_a, ft_lstnew(15));
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

    printf("First A node: %d\n", lst_a -> content);
    printf("Second A node: %d\n", lst_a -> next -> content);
    printf("Third A node: %d\n\n", lst_a -> next -> next -> content);
    //printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
    //printf("Fifth A node: %d\n\n", lst_a -> next -> next -> next -> next -> content);
    //printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);

    ft_reva(&lst_a);
	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
	printf("Fifth A node: %d\n", lst_a -> next -> next -> next -> next -> content);
	printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);
	//printf("First B node: %d\n", lst_b -> content);

	return (0);
}
