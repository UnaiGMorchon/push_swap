/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/07/23 10:36:32 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

t_node_list	*ft_max_index(t_stack *lst_b)
{
	t_node_list	*tmp;
	t_node_list	*max_node;
	int			nodes;

	tmp = lst_b -> head;
	max_node = lst_b ->head;
	nodes = 0;
	while (nodes < lst_b -> size)
	{
		if (tmp -> index > max_node -> index)
			max_node = tmp;
		tmp = tmp -> next;
		nodes++;
	}
	return (max_node);
}

void	ft_rotate_decide(t_stack *lst_b, t_bench *bench)
{
	t_node_list	*tmp;
	t_node_list	*tmp_max_index;
	int			physical_node_position;

	tmp_max_index = ft_max_index(lst_b);
	while (lst_b -> head != tmp_max_index)
	{
		physical_node_position = 0;
		tmp = lst_b -> head;
		while (tmp != tmp_max_index)
		{
			tmp = tmp -> next;
			physical_node_position++;
		}
		if (physical_node_position <= lst_b -> size / 2)
		{
			ft_rb(lst_b, bench);
		}
		else
		{
			ft_rrb(lst_b, bench);
		}
	}
}

int	ft_exist_bucket(t_stack *lst_a, int number_limit)
{
	t_node_list	*tmp;
	int			nodes;

	tmp = lst_a -> head;
	nodes = 0;
	while (nodes < lst_a -> size)
	{
		if (tmp -> index < number_limit)
		{
			return (1);
		}
		tmp = tmp -> next;
		nodes++;
	}
	return (0);
}

void	ft_get_index(t_stack *lst_a)
{
	int			index_count;
	t_node_list	*current;
	t_node_list	*current_aux;
	int			i;
	int			j;

	current = lst_a -> head;
	i = 0;
	while (i++ < lst_a->size)
	{
		index_count = 0;
		current_aux = lst_a->head;
		j = 0;
		while (j++ < lst_a->size)
		{
			if (current_aux -> content < current -> content)
			{
				index_count += 1;
			}
			current_aux = current_aux -> next;
		}
		current -> index = index_count;
		current = current ->next;
	}
}

void	ft_bucket(t_stack *lst_a, t_bench *bench)
{
	int		number_limit;
	int		end_bucket;
	t_stack	*lst_b;

	lst_b = ft_newstack();
	ft_get_index(lst_a);
	number_limit = ft_sqroot(lst_a -> size);
	end_bucket = number_limit;
	while (lst_a -> size)
	{
		if (lst_a -> head -> index < number_limit)
			ft_pb(lst_b, lst_a, bench);
		else if (ft_exist_bucket(lst_a, number_limit))
			ft_ra(lst_a, bench);
		else
			number_limit += end_bucket;
	}
	while (lst_b -> size)
	{
		ft_rotate_decide(lst_b, bench);
		ft_pa(lst_a, lst_b, bench);
	}
	ft_clearstack(lst_b);
	ft_clearstack(lst_a);
}
