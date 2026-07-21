/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_adaptive_algo.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:09:11 by patperez          #+#    #+#             */
/*   Updated: 2026/07/21 13:16:03 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

t_bench	*ft_initialise_bench(void)
{
	t_bench	*bench;

	bench = malloc(sizeof(t_bench));
	bench -> disorder = 0.0;
	bench -> strategy = NULL;
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

t_isflag	*ft_initialise_flag_bench(void)
{
	t_isflag	*flag_bench;

	flag_bench = malloc(sizeof(t_isflag));
	flag_bench -> flag = NULL;
	flag_bench -> bench = NULL;
	return (flag_bench);
}

float	ft_disorder_metric(t_stack *lst)
{
	t_node_list	*tmp;
	float		mistakes;
	float		total_pairs;
	int			i;
	int			j;

	mistakes = 0.00f;
	total_pairs = 0.00f;
	i = 0;
	while (i < lst -> size - 1)
	{
		tmp = lst -> head -> next;
		j = i + 1;
		while (j++ < lst -> size)
		{
			total_pairs += 1;
			if (lst -> head -> content > tmp -> content)
				mistakes += 1;
			tmp = tmp -> next;
		}
		lst -> head = lst -> head -> next;
		i++;
	}
	lst -> head = lst -> head -> next;
	return (mistakes / total_pairs);
}

void	ft_adaptive_algo(t_stack *lst, t_bench *bench)
{
	if (lst -> size <= 5)
	{
		bench -> strategy = "Adaptive / O(n2)";
		ft_get_index(lst);
		ft_shortlist_sort(lst, bench);
	}
	else if (bench -> disorder < 0.2)
	{
		bench -> strategy = "Adaptive / O(n2)";
		ft_bubble_sort(lst, bench);
	}
	else if (bench -> disorder >= 0.2 && bench -> disorder < 0.5)
	{
		bench -> strategy = "Adaptive / O(n√n)";
		ft_bucket(lst, bench);
	}
	else if (bench -> disorder >= 0.5)
	{
		bench -> strategy = "Adaptive / O(n log n)";
		ft_get_index(lst);
		ft_radix(lst, bench);
	}
}
