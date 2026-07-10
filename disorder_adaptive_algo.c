/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_adaptive_algo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:09:11 by patperez          #+#    #+#             */
/*   Updated: 2026/07/10 13:25:17 by patperez         ###   ########.fr       */
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

void	ft_adaptive_algo(t_stack *lst)
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
}
