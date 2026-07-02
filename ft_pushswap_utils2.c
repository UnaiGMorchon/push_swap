/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:51:52 by patperez          #+#    #+#             */
/*   Updated: 2026/07/02 12:15:28 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_lstclear(t_stack *lst)
{
	t_node_list	*buffer;
	t_node_list	*tmp;

	buffer = NULL;
	if (!lst)
		return ;
	tmp = lst -> head;
	while (lst->size)
	{
		buffer = tmp-> next;
		free(tmp);
		tmp = buffer;
		lst->size -= 1;
	}
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
	free(lst);
}

int	ft_lstsize(t_node_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

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

int	ft_max_number(t_stack *lst_a)
{
	int			temp;
	t_node_list	*temp_list;

	temp_list = lst_a -> head;
	temp = lst_a -> head -> content;
	while (temp_list -> next != NULL)
	{
		if (temp > temp_list -> next -> content)
		{
			temp = temp_list -> content;
		}
		temp_list = temp_list -> next;
	}
	return (temp);
}

int	ft_min_number(t_stack *lst_a)
{
	int			temp;
	t_node_list	*temp_list;

	temp_list = lst_a -> head;
	temp = lst_a -> head -> content;
	while (temp_list -> next != NULL)
	{
		if (temp > temp_list -> content)
		{
			temp = temp_list -> content;
		}
		temp_list = temp_list -> next;
	}
	printf("TEMP>>>>> %i\n", temp);
	return (temp);
}