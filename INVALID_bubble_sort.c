/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INVALID_bubble_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/06/24 11:02:11 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

double	sqrt(double x)
{
	double	y;
	int	p;
	int	square;
	int	c;

	p = 0;
	square = 0;
	c = 0;
	while (x > square)
	{
		p++;
		square = (p + 1) * (p + 1);
	}
	y = (double)p;
	while (c < 10)
	{
		y = (x / y + y) / 2;
		if (y * y == x)
			return (y);
		c++;
	}
	return (y);
}

void	bubble_sort(t_node_list **lst_a)
{
	t_node_list	**lst_b;

	printf("ENTER FUNCTION");
	if (lst_a == NULL || *lst_a == NULL || (*lst_a) -> next == NULL)
		return ;
	lst_b = NULL;
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
