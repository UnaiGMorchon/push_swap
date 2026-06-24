/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INVALID_buble_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/06/24 10:14:03 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"



t_node_list	ft_min_number(t_node_list **lst_a)
{
	t_node_list	*temp;

	temp = (*lst_a) -> content;
	while (lst_a)
	{
		if (temp < (*lst_a) -> next -> content)
		{
			temp = (*lst_a) -> content;
		}
		ft_ra(lst_a);
		return (*temp);
	}
}

void	ft_bucket(t_node_list **lst_a)
{
	t_node_list	**lst_b;
	t_node_list	number;
	t_node_list *total;
	t_node_list *bucket;

	if (lst_a == NULL || *lst_a == NULL || (*lst_a) -> next == NULL)
		return ;
	lst_b = NULL;
	number = ft_min_number(*lst_a);
	total = ft_lstsize (*lst_a);
	bucket = ft_raiz_cuadrada(total);

	while (lst_a)
	{
		if ((bucket + number) < (*lst_a) -> next -> content ||
			(*lst_a) -> next == NULL)
		{
			ft_pb(lst_b, lst_a);
			if ((*lst_b) -> content < (*lst_b) -> next -> content)
				ft_sb(lst_b);
			else
				while ((*lst_b) -> content > (*lst_b) -> next -> content)
					ft_rb(lst_b);
		}
		else
			ft_ra(lst_a);
	}
	while (lst_b)
		ft_pa(lst_a, lst_b);
	ft_lstclear(lst_b);
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

	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);    
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
	printf("Fifth A node: %d\n\n", lst_a -> next -> next -> next -> next -> content);
	//printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);

	bubble_sort(&lst_a);

	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
	printf("Fifth A node: %d\n\n", lst_a -> next -> next -> next -> next -> content);
	//printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);

	ft_lstclear(&lst_a);
	return (0);
}

/*
while (lst_a)
	{
		if ((*lst_a) -> content < (*lst_a) -> next -> content ||
			(*lst_a) -> next == NULL)
		{
			ft_pb(lst_b, lst_a);
			if ((*lst_b) -> content < (*lst_b) -> next -> content)
				ft_sb(lst_b);
			else
				while ((*lst_b) -> content > (*lst_b) -> next -> content)
					ft_rb(lst_b);
		}
		else
			ft_ra(lst_a);
	}
	while (lst_b)
		ft_pa(lst_a, lst_b);
	ft_lstclear(lst_b);
*/

/*
		while ((bucket + number) < (*lst_a) -> content)
		{
			ft_pb;
		}
		(bucket + number) + bucket;
	}
*/

