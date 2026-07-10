/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_adaptive_algo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:09:11 by patperez          #+#    #+#             */
/*   Updated: 2026/07/10 09:13:57 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

t_bench	*initialise_bench(t_bench *bench)
{
	bench -> disorder = 0.0;
	bench -> strategy = '\0';
	bench -> total = 0;
	bench -> sa = 0;
	bench -> sb = 0;
	bench -> ss = 0;
	bench -> pa = 0;
	bench -> pb = 0;
	bench -> ra = 0;
	bench -> rb = 0;
	bench -> rr = 0;
	bench -> rra = 0;
	bench -> rrb = 0;
	bench -> rrr = 0;
	return (bench);
}

float	disorder_metric(t_stack *lst)
{
	t_node_list	*tmp;
	float	mistakes;
	float	total_pairs;
	int		i;
	int 	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	if (lst == NULL || lst -> head == NULL)
		return (0);
	while (i < lst -> size - 1)
	{
		tmp = lst -> head -> next;
		j = i + 1;
		while (j < lst -> size - 1)
		{
			total_pairs++;
			if (lst -> head -> content > lst -> head -> next -> content)
				mistakes++;
			tmp = tmp -> next;
			j++;
		}
		lst -> head = lst -> head -> next;
		i++;
	}
	return (mistakes / total_pairs);
}

char	print_bench(t_bench *bench)
{
	//disorder = disorder_metric(lst) * 100;
	printf("BENCH PRINT TEST %d", bench -> sa);
	return (0);
}

/*void	adaptive_algo(t_stack *lst)
{
	float	disorder;

	disorder = disorder_metric(lst_a) * 100;
	if (lst == NULL || lst -> head == NULL)
		return ;
	disorder = disorder_metric(lst);
	if (disorder < 0.2)
		call bubble
	else if (disorder >= 0.2 && disorder < 0.5)
		call bucket
	else if (disorder >= 0.5)
		call radix
	else if (disorder == 0)
		show nothing ?? empty bench ??
	if (bench selected)
		output benchmark info
}*/

/*#include <stdio.h>
int	main (void)
{
	t_stack	*lst_a;

	lst_a = ft_newstack();
	// STACK_A
	ft_lstadd_back(lst_a, ft_lstnew(12));
	ft_lstadd_back(lst_a, ft_lstnew(15));
	ft_lstadd_back(lst_a, ft_lstnew(1));
	ft_lstadd_back(lst_a, ft_lstnew(2));
	ft_lstadd_back(lst_a, ft_lstnew(16));
	ft_lstadd_back(lst_a, ft_lstnew(567));
	ft_lstadd_back(lst_a, ft_lstnew(13));
	ft_lstadd_back(lst_a, ft_lstnew(9));
	
	printf("Disorder: %f", disorder_metric(lst_a));
	printf("[bench]: %d", print_bench(lst_a -> bench));
	return (0);
}*/
