/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_adaptive_algo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:09:11 by patperez          #+#    #+#             */
/*   Updated: 2026/07/16 08:34:07 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

t_bench	*initialise_bench(void)
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

t_isflag	*initialise_flag_bench(void)
{
	t_isflag	*flag_bench;

	flag_bench = malloc(sizeof(t_isflag));
	flag_bench -> flag = NULL;
	flag_bench -> bench = NULL;
	return (flag_bench);
}

float	disorder_metric(t_stack *lst)
{
	t_node_list	*tmp;
	float		mistakes;
	float		total_pairs;
	int			i;
	int			j;

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
	//ft_printf("[bench] disorder: %f\n", bench -> disorder;
	ft_printf("[bench] strategy: %s\n", bench -> strategy);
	ft_printf("[bench] total: %d\n", bench -> total);
	ft_printf("sa: %d\n", bench -> sa);
	ft_printf("sb: %d\n", bench -> sb);
	ft_printf("ss: %d\n", bench -> ss);
	ft_printf("pa: %d\n", bench -> pa);
	ft_printf("pb: %d\n", bench -> pb);
	ft_printf("ra: %d\n", bench -> ra);
	ft_printf("rb: %d\n", bench -> rb);
	ft_printf("rr: %d\n", bench -> rr);
	ft_printf("rra: %d\n", bench -> rra);
	ft_printf("rrb: %d\n", bench -> rrb);
	ft_printf("rrr: %d\n", bench -> rrr);

	write(2, &bench->rrr, 1);
	return (0);
}

void	ft_adaptive_algo(t_stack *lst, t_bench *bench)
{
	float	disorder;

	disorder = disorder_metric(lst);
	bench -> disorder = disorder * 100.0f; // ???
	disorder = disorder_metric(lst);
	if (disorder > 0 && disorder < 0.2)
	{
		bench -> strategy = "Adaptive / O(n2)";
		ft_bubble_sort(lst, bench);
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		bench -> strategy = "Adaptive / O(n√n)";
		ft_bucket(lst, bench);
	}
	else if (disorder >= 0.5)
	{
		bench -> strategy = "Adaptive / O(n log n)";
		ft_radix(lst, bench);
	}
}
