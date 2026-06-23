/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/06/23 13:45:46 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_sa(t_node_list **lst_a)
{
	t_node_list	*temp;

	if (lst_a == NULL || *lst_a == NULL || (*lst_a)->next == NULL)
		return ;
	temp = (*lst_a)->next;
	(*lst_a)->next = temp->next;
	temp->next = (*lst_a);
	(*lst_a) = temp;
}

void	ft_ra(t_node_list **lst)
{
	t_node_list	*tmp_first;
	t_node_list	*tmp_last;

	if (!lst)
		return ;
	if ((*lst) == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	{
		tmp_first = (*lst);
		(*lst) = (*lst)->next;
		tmp_first->next = NULL;
		tmp_last = ft_lstlast(*lst);
		tmp_last->next = tmp_first;
	}
}

void	bubble_sort(t_node_list **lst)
{
	int	swapped;
	int	size;
	int	i;

	size = ft_lstsize(*lst);
	if (*lst == NULL || (lst) == NULL || (*lst)-> next == NULL)
		return ;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if ((*lst)-> content > (*lst)-> next -> content)
			{
				ft_sa(lst);
				swapped = 1;
			}
			ft_ra(lst);
			i ++;
		}
		ft_ra(lst);
	}
}

int	main(void)
{
	t_node_list	*lst_a;

	lst_a = NULL;
	lst_a = ft_lstnew(14);
	ft_lstadd_back(&lst_a, ft_lstnew(12));
	ft_lstadd_back(&lst_a, ft_lstnew(15));
	ft_lstadd_back(&lst_a, ft_lstnew(1));
	ft_lstadd_back(&lst_a, ft_lstnew(13));
	ft_lstadd_back(&lst_a, ft_lstnew(16));
	ft_lstadd_back(&lst_a, ft_lstnew(18));
	ft_lstadd_back(&lst_a, ft_lstnew(2));
	ft_lstadd_back(&lst_a, ft_lstnew(9));

	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
	printf("Fifth A node: %d\n", lst_a -> next -> next -> next -> next -> content);
	printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);
	printf("siete A node: %d\n", lst_a -> next -> next -> next -> next -> next -> next -> content);
	printf("ocho A node: %d\n", lst_a -> next -> next -> next -> next -> next -> next-> next -> content);
	printf("nueve A node: %d\n\n", lst_a -> next -> next -> next -> next -> next -> next-> next -> next -> content);

	bubble_sort(&lst_a);
	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
	printf("Fifth A node: %d\n", lst_a -> next -> next -> next -> next -> content);
	printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);
	printf("siete A node: %d\n", lst_a -> next -> next -> next -> next -> next -> next -> content);
	printf("ocho A node: %d\n", lst_a -> next -> next -> next -> next -> next -> next-> next -> content);
	printf("nueve A node: %d\n\n", lst_a -> next -> next -> next -> next -> next -> next-> next -> next -> content);

	ft_lstclear(&lst_a);
	return (0);
}