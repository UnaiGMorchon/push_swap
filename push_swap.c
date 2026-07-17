/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/17 15:59:25 by patperez         ###   ########.fr       */
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

char	**new_args(int argc, char **argv, int *i)
{
	int		j;
	int		param;
	char	**args;

	j = 0;
	param = args_count(i, argc);
	if (param == 1)
	{
		args = ft_split(argv[*i], ' ');
		*i += 1;
		return (args);
	}
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
	return (args);
}

int	push_swap(int argc, char **argv)
{
	char		**args;
	t_bench		*bench;
	t_isflag	*flag_bench;
	int			i;

	i = 1;
	args = NULL;
	bench = initialise_bench();
	flag_bench = initialise_flag_bench();
	separate_flags(argv, flag_bench, &i);
	args = new_args(argc, argv, &i);
	ft_flag_search_parsing(args, flag_bench, bench);
	if (flag_bench -> bench && bench -> disorder == 0)
		print_bench(bench);
	free_split(args);
	free(flag_bench);
	free(bench);
	return (0);
}
