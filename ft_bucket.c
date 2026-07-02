/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/07/02 12:23:35 by ugarcia-         ###   ########.fr       */
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

void	ft_rotate_decide(t_stack *lst_b)
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
			ft_rb(lst_b);
		}
		else
		{
			ft_rrb(lst_b);
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
	while (i < lst_a->size)
	{
		index_count = 0;
		current_aux = lst_a->head;
		j = 0;
		while (j < lst_a->size)
		{
			if (current_aux -> content < current -> content)
			{
				index_count += 1;
			}
			current_aux = current_aux -> next;
			j++;
		}
		current -> index = index_count;
		current = current ->next;
		i++;
	}
}

void	ft_bucket(t_stack *lst_a, t_stack *lst_b)
{
	int	number_limit;
	int	exist_bucket;
	int	end_bucket;

	if (lst_a == NULL || lst_a -> head == NULL || lst_a -> size <= 1)
		return ;
	number_limit = sqroot(lst_a -> size);
	end_bucket = number_limit;
	while (lst_a -> size)
	{
		if (lst_a -> head -> index < number_limit)
			ft_pb(lst_b, lst_a);
		else
		{
			exist_bucket = ft_exist_bucket(lst_a, number_limit);
			if (exist_bucket)
				ft_ra(lst_a);
			else
				number_limit += end_bucket;
		}
	}
	while (lst_b -> size)
	{
		ft_rotate_decide(lst_b);
		ft_pa(lst_a, lst_b);
	}
}

/* static void	ft_print_list(t_stack *stack, int size)
{
	int			counter;
	t_node_list	*lst_tmp;

	counter = 0;
	lst_tmp = stack->head;
	while (counter < size)
	{
		printf(
			"Node %d\n"
			"  addr       : %p\n"
			"  content    : %d\n"
			"  prev       : %p\n"
			"  next       : %p\n"
			"  index      : %d\n\n",
			counter,
			(void *)lst_tmp,
			lst_tmp->content,
			(void *)lst_tmp->prev,
			(void *)lst_tmp->next,
			lst_tmp->index
			);
		lst_tmp = lst_tmp->next;
		counter++;
	}
}

int	main(void)
{
	t_stack	*lst_a;
	t_stack	*lst_b;

	lst_a = ft_newstack();
	lst_b = ft_newstack();
	// STACK_A
	ft_lstadd_back(lst_a, ft_lstnew(12));
	ft_lstadd_back(lst_a, ft_lstnew(15));
	ft_lstadd_back(lst_a, ft_lstnew(1));
	ft_lstadd_back(lst_a, ft_lstnew(13));
	ft_lstadd_back(lst_a, ft_lstnew(16));
	ft_lstadd_back(lst_a, ft_lstnew(18));
	ft_lstadd_back(lst_a, ft_lstnew(2));
	ft_lstadd_back(lst_a, ft_lstnew(9));
	// STACK_B
	ft_get_index(lst_a);
	printf("---------------STACK A-----------\n");
	ft_print_list(lst_a, lst_a -> size);

	ft_bucket(lst_a, lst_b);

	printf("---------------sorted B--------------- \n");
	ft_print_list(lst_b, lst_b -> size);
	printf("---------------%d lista tamaño B-----------\n", lst_b-> size);
	printf("---------------%d lista tamaño A-----------\n", lst_a-> size);

	printf("---------------resultado A-----------\n");
	ft_print_list(lst_a, lst_a -> size);

	ft_lstclear(lst_a);
	return (0);
}
 */