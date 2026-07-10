/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:19:02 by patperez          #+#    #+#             */
/*   Updated: 2026/07/09 12:38:28 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	get_max_bits(t_stack *lst)
{
	t_node_list	*copy;
	int	i;
	int	bits;

	i = 0;
	bites = 0;
	copy = *lst -> head;
	while (copy -> next != head)
	{
		while (*copy[i])
		{
			bits++;
			i++;
		}
		if (bits > i)
			bits = i;
		i = 0;
		copy = copy -> next;
	}
	return (bits);
}

void	ft_radix(t_stack **lst_a, t_stack **lst_b, t_bench bench)
{
	t_node_list	*head_mark;
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	head_mark = *lst_a;
	size = ft_lstsize(lst_a);
	max_bits = get_max_bits(lst_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_mark = *lst_a;
			if (((head_a -> index >> i) & 1) == 1)
				ra(lst_a, bench);
			else
				pb(lst_b, lst_a, bench);
		}
		while (*lst_b)
			pa(lst_a, lst_b, bench);
		ft_lstclear(lst_b);
		i++;
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
	//ft_print_list(lst_a, lst_a -> size);

	ft_radix(lst_a, lst_b);

	printf("---------------sorted B--------------- \n");
	ft_print_list(lst_b, lst_b -> size);
	printf("---------------%d lista tamaño B-----------\n", lst_b-> size);
	printf("---------------%d lista tamaño A-----------\n", lst_a-> size);

	printf("---------------resultado A-----------\n");
	ft_print_list(lst_a, lst_a -> size);

	ft_lstclear(lst_a);
	return (0);
}
	return (0);
}
