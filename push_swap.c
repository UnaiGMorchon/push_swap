/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/10 14:09:22 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
convertirlo a string separados por espacios, concatenar. (contar los que tenemos?)
trocear hacerle el split?. trocerar
validar que sea números, convertirlos a números isdigit? validar
sin duplicados, sin negativos, no se salgan de los limites, atoi? convertir
*/

char	**new_args(int argc, char **argv, char **args)
{
	int	i;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = (char**)malloc(sizeof(char*) * (argc));
		if (args == NULL)
			return (NULL);
 		while (argv[i])
		{
			args[i - 1] = ft_strdup(argv[i]);
			i++;
		}
	}
	return (args);
}

char	ft_valid_and_convert(char **args)
{
	if ((ft_is_validint(args)) == 0 || (ft_isrepeat(args)) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	input_conversion(args);
	return (args);
}

char	ft_flag_search_parsing(char **args)
{
	if (ft_strncmp(args[0], "--simple", 8) == 0 || ft_strncmp(args[1], "--simple", 8) == 0)
	{
		ft_valid_and_convert(args);
		return (ft_bubble_sort(lst, bench));
	}
	else if (ft_strncmp(args[0], "--medium", 8) == 0 || ft_strncmp(args[1], "--medium", 8) == 0)
	{
		ft_valid_and_convert(args);
		return (ft_bucket(lst_a, lst_b, bench));
	}
	else if (ft_strncmp(args[0], "--complex", 9) == 0 || ft_strncmp(args[1], "--complex", 9) == 0);
	{
		ft_valid_and_convert(args);
		return (ft_radix(lst_a, lst_b, bench));
	}
	else if (ft_strncmp(args[0], "--adaptive", 10) == 0 || ft_strncmp(args[1], "--adaptive", 10) == 0)
	{
		ft_valid_and_convert(args);
		return (ft_adaptive_algo(lst_a, bench)); // FINISH ADAPTIVE ALGO
	}
	return (0);
}

int	push_swap(int argc, char **argv)
{
	char	**args;
	t_bench	*bench;

	args = NULL;
	bench = initialise_bench(bench);

	/* argument parsing */
	args = new_args(argc, argv, args);
	// DISORDER
	ft_flag_search_parsing(args); // this calls valid and convert, which returns stack_a
									// select strategy (if not entered via console)

	/* print bench (it called via console) */
	return (0);
}
