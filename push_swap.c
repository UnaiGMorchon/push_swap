/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/15 16:14:13 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	ft_is_bench(char *str)
{
	if (ft_strncmp(str, "--bench", 7) == 0)
		return (1);
	return (0);
}

int	ft_is_flag(char *str)
{
	if (ft_strncmp(str, "--simple", 8) == 0)
		return (1);
	if (ft_strncmp(str, "--medium", 8) == 0)
		return (1);
	if (ft_strncmp(str, "--complex", 10) == 0)
		return (1);
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (1);
	return (0);
}

void	separate_flags(char **argv, t_isflag *flag_bench, int *i)
{
	if (ft_is_bench(argv[*i]) == 1)
	{
		flag_bench -> bench = argv[*i];
		*i += 1;
	}
	if (ft_is_flag(argv[*i]) == 1)
	{
		flag_bench -> flag = argv[*i];
		*i += 1;
	}
	else
	{
		flag_bench -> flag = "--adaptive";
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	args_count(int *i, int argc)
{
	int	counter;

	counter = 0;
	while (counter < (argc - *i))
	{
		counter++;
	}
	return (counter);
}

char	**new_args(int argc, char **argv, int *i)
{
	int		j;
	int		param;
	char	**args;

	j = 0;
	param = args_count(i, argc);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = (char **)malloc(sizeof(char*) * (param + 1));
		if (args == NULL)
			return (NULL);
		while (argv[*i])
		{
			args[j] = ft_strdup(argv[*i]);
			*i += 1;
			j++;
		}
		args[j] = NULL;
	}
	return (args);
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
	t_stack	*stack_a;

	stack_a = ft_valid_and_convert(args, bench, flag_bench);
	if (ft_strncmp(flag_bench -> flag, "--simple", 8) == 0)
	{
		bench -> strategy = "Simple / O(n2)";
		ft_bubble_sort(stack_a, bench);
	}
	else if (ft_strncmp(flag_bench -> flag, "--medium", 8) == 0)
	{
		bench -> strategy = "Medium / O(n√n)";
		ft_bucket(stack_a, bench);
	}
	else if (ft_strncmp(flag_bench -> flag, "--complex", 9) == 0)
	{
		bench -> strategy = "Complex / O(n log n)";
		ft_radix(stack_a, bench);
	}
	else if (ft_strncmp(flag_bench -> flag, "--adaptive", 10) == 0 || !flag_bench->flag)
	{
		ft_adaptive_algo(stack_a, bench);
	}
	ft_lstclear(stack_a);
}

int	push_swap(int argc, char **argv)
{
	char		**args;
	t_bench		*bench;
	t_isflag	*flag_bench;
	int			i;
/* 	int			j; */

/* 	j = 0;
 */	i = 1;
	args = NULL;
	bench = initialise_bench();
	flag_bench = initialise_flag_bench();
	separate_flags(argv, flag_bench, &i);
	args = new_args(argc, argv, &i);
	ft_flag_search_parsing(args, flag_bench, bench); // this calls valid and convert, which returns stack_a
									// select strategy (if not entered via console)
	if (flag_bench -> bench || bench -> disorder == 0)
		print_bench(bench);
	free(flag_bench);
	free(bench);
	return (0);
}