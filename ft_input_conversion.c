/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:58:07 by patperez          #+#    #+#             */
/*   Updated: 2026/07/21 12:36:49 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

long int	ft_is_validint(char **args)
{
	int			i;
	int			j;
	long int	result;

	j = -1;
	while (args[++j])
	{
		i = 0;
		if (args[j][0] == '-')
			i++;
		while (args[j][i])
		{
			if (!ft_isdigit(args[j][i++]))
			{
				return (0);
			}
		}
		result = ft_atol(args[j]);
		if (result > 2147483647 || result < -2147483648)
		{
			return (0);
		}
	}
	return (1);
}

int	ft_isrepeat(char **args)
{
	int			i;
	int			j;
	long int	result;
	long int	tmp;

	i = 0;
	while (args[i])
	{
		j = 0;
		result = ft_atol(args[i]);
		while (j < i)
		{
			tmp = ft_atol(args[j]);
			if (result == tmp)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*ft_input_conversion(char **args, t_bench *bench, t_isflag *flag_bench)
{
	int			i;
	t_stack		*stack_a;

	i = 0;
	stack_a = ft_newstack();
	if (!stack_a)
		return (NULL);
	while (args[i])
	{
		ft_stackadd_back(stack_a, ft_newnode(ft_atol(args[i])));
		i++;
	}
	bench -> disorder = ft_disorder_metric(stack_a);
	(void)flag_bench;
	if (bench -> disorder == 0)
	{
		if (flag_bench -> bench)
			ft_print_bench(bench);
		free(bench);
		free(flag_bench);
		ft_clearstack(stack_a);
		ft_free_split(args);
		exit(0);
	}
	return (stack_a);
}

t_stack	*ft_valid_and_convert(char **args, t_bench *bench, t_isflag *flag_bench)
{
	if (ft_is_validint(args) == 0 || ft_isrepeat(args) == 0)
	{
		free(bench);
		free(flag_bench);
		ft_free_split(args);
		exit(write(2, "Error\n", 6));
	}
	return (ft_input_conversion(args, bench, flag_bench));
}

void	ft_flag_search_parsing(char **args, t_isflag *flag_bench,
			t_bench *bench)
{
	t_stack	*converted_stack;

	converted_stack = ft_valid_and_convert(args, bench, flag_bench);
	if (ft_strncmp(flag_bench -> flag, "--simple", 8) == 0)
	{
		bench -> strategy = "Simple / O(n2)";
		ft_bubble_sort(converted_stack, bench);
	}
	else if (ft_strncmp(flag_bench -> flag, "--medium", 8) == 0)
	{
		bench -> strategy = "Medium / O(n√n)";
		ft_bucket(converted_stack, bench);
	}
	else if (ft_strncmp(flag_bench -> flag, "--complex", 9) == 0)
	{
		bench -> strategy = "Complex / O(n log n)";
		ft_get_index(converted_stack);
		ft_radix(converted_stack, bench);
		ft_clearstack(converted_stack);
	}
	else if (ft_strncmp(flag_bench -> flag, "--adaptive", 10) == 0
		|| !flag_bench -> flag)
	{
		ft_adaptive_algo(converted_stack, bench);
	}
}
