/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INVALID_bubble_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/06/24 13:50:30 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

double	sqroot(int x)
{
	double	y;
	int		p;
	int		square;
	int		c;

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

int	ft_min_number(t_node_list **lst_a)
{
	int	temp;

	temp = (*lst_a) -> content;
	while (lst_a)
	{
		if (temp < (*lst_a) -> next -> content)
		{
			temp = (*lst_a) -> content;
		}
		ft_ra(lst_a);
	}
	return (temp);
}

void	ft_bucket(t_node_list **lst_a)
{
	t_node_list	**lst_b;
	int number; // Para guardar el VALOR del número más pequeño
	int total; // Para guardar la cantidad total de elementos
	int bucket_number; // Para guardar el tamaño del bloque (raíz cuadrada)
	int number_limit; // Para guardar tu "número límite" actual
	int	end_of_bucket;
	
	if (lst_a == NULL || *lst_a == NULL || (*lst_a) -> next == NULL)
		return ;
	lst_b = NULL;
	number = ft_min_number(lst_a);
	total = ft_lstsize (*lst_a);
	bucket_number = sqroot(total);
	number_limit = (bucket_number + number);
	end_of_bucket = ft_lstlast(*lst_a) -> content;

	while (lst_a)
	{
		printf("nmber limit %i", number_limit);
		while ((*lst_a) -> content < number_limit)
		{
			ft_pb(lst_b, lst_a);
			printf("THIS IS PUSH IN INNER WHILE");
		}
		if ((*lst_a) -> content == end_of_bucket)
		{
			number_limit = number_limit + bucket_number;
			return ;
		}
		/*else
			ft_rb(lst_a);*/
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

	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);    
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
	printf("Fifth A node: %d\n\n", lst_a -> next -> next -> next -> next -> content);
	//printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);

	ft_bucket(&lst_a);

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

