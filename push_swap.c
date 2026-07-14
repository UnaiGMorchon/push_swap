/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/14 15:52:02 by ugarcia-         ###   ########.fr       */
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
	char	**args;

	j = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = (char **)malloc(sizeof(char*) * (argc));
		if (args == NULL)
			return (NULL);
		while (argv[*i])
		{
			args[j] = ft_strdup(argv[*i]);
			*i += 1;
			j++;
		}
	}
	return (args);
}

t_stack	*ft_valid_and_convert(char **args)
{
	printf("WE'RE IN VALID AND CONVERT");
	if ((ft_is_validint(args)) == 0 || (ft_isrepeat(args)) == 0)
	{
		free(args);
		exit(write(1, "Error\n", 6));
	}
	return (input_conversion(args));
}

void	ft_flag_search_parsing(char **args, t_isflag *flag_bench, t_bench *bench)
{
	if (ft_strncmp(flag_bench -> flag, "--simple", 8) == 0)
	{
		bench -> strategy = "Simple / O(n2)";
		ft_bubble_sort(ft_valid_and_convert(args), bench);
	}
	else if (ft_strncmp(flag_bench -> flag, "--medium", 8) == 0)
	{
		bench -> strategy = "Medium / O(n√n)";
		ft_bucket(ft_valid_and_convert(args), bench);
	}
	else if (ft_strncmp(flag_bench -> flag, "--complex", 9))
	{
		bench -> strategy = "Complex / O(n log n)";
		return (ft_radix(ft_valid_and_convert(args), bench));
	}
	/*else if (ft_strncmp(flag_bench -> flag, "--adaptive", 10))
	{
		bench -> strategy = "Adaptive";
		return (ft_adaptive_algo(ft_valid_and_convert(args), bench));
	}*/
	else
		ft_bucket(ft_valid_and_convert(args), bench);
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
	/* 
	while (args[j])
	{
		printf(" argumentos%s\n", args[j]);
		j++;
	}  */
	ft_flag_search_parsing(args, flag_bench, bench); // this calls valid and convert, which returns stack_a
									// select strategy (if not entered via console)
	
	input_conversion(args);

	/* print bench (it called via console) */
	free(args);
	return (0);
}