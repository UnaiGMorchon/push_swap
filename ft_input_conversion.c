/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:58:07 by patperez          #+#    #+#             */
/*   Updated: 2026/07/17 11:11:59 by patperez         ###   ########.fr       */
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
	long int	temp;

	i = 0;
	while (args[i])
	{
		j = 0;
		result = ft_atol(args[i]);
		while (j < i)
		{
			temp = ft_atol(args[j]);
			if (result == temp)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*input_conversion(char **args)
{
	int			i;
	t_stack		*stack_a;

	i = 0;
	stack_a = ft_newstack();
	if (!stack_a)
		return (NULL);
	while (args[i])
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atol(args[i])));
		i++;
	}
	return (stack_a);
}

t_stack	*ft_valid_and_convert(char **args, t_bench *bench, t_isflag *flag_bench)
{
	if (ft_is_validint(args) == 0 || ft_isrepeat(args) == 0)
	{
		free(bench);
		free(flag_bench);
		free_split(args);
		exit(write(2, "Error\n", 6));
	}
	return (input_conversion(args));
}

void	ft_flag_search_parsing(char **args, t_isflag *flag_bench, t_bench *bench)
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
		ft_radix(converted_stack, bench);
		ft_lstclear(converted_stack);
	}
	else if (ft_strncmp(flag_bench -> flag, "--adaptive", 10) == 0 || !flag_bench -> flag)
	{
		ft_adaptive_algo(converted_stack, bench);
	}
}
