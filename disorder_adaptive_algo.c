/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_adaptive_algo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:09:11 by patperez          #+#    #+#             */
/*   Updated: 2026/07/20 10:40:52 by ugarcia-         ###   ########.fr       */
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
		tmp = lst -> head;
		j = i + 1;
		while (j < lst -> size - 1)
		{
			total_pairs++;
			if (tmp -> content > tmp -> next -> content)
				mistakes++;
			tmp = tmp -> next;
			j++;
		}
		tmp = tmp -> next;
		i++;
	}
	return (mistakes / total_pairs);
}

static char	ft_bench_help(t_bench *bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench -> sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench -> sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench -> ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench -> pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench -> pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(bench -> ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench -> rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench -> rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench -> rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench -> rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench -> rrr, 2);
	return (0);
}


char	print_bench(t_bench *bench)
{
	int	num;
	int	dec;
	int	total;

	total = (int)(bench -> disorder * 10000.0f);
	num = total / 100;
	dec = total % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(num, 2);
	write(1, ".", 1);
	if (dec < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(dec, 2);
	write(1, "%", 1);
	write(2, "\n", 1);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(bench -> strategy, 2);
	write(2, "\n", 1);
	ft_putstr_fd("[bench] total: ", 2);
	ft_putnbr_fd(bench -> total, 2);
	write(2, "\n", 1);
	ft_bench_help(bench);
	return (0);
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
		ft_radix(lst, bench);
	}
}
