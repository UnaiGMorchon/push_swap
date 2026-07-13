/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/13 12:42:43 by patperez         ###   ########.fr       */
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
		args = (char **)malloc(sizeof(char*) * (argc));
		if (args == NULL)
			return (NULL);
 		while (argv[i])
		{
			args[i - 1] = ft_strdup(argv[i]);
			i++;
		}
	}
	i = 0;
	return (args);
}

t_stack	*ft_valid_and_convert(char **args, t_bench *bench)
{
	if ((ft_is_validint(args)) == 0 || (ft_isrepeat(args)) == 0)
	{
		free(bench); //have to free upon error
		free(args);
		exit(write(1, "Error\n", 6));
	}
	return (input_conversion(args));
}

void	ft_flag_search_parsing(char **args, t_bench *bench)
{
	if (ft_strncmp(args[0], "--simple", 8) == 0 || ft_strncmp(args[1], "--simple", 8) == 0)
	{
		bench -> strategy = "Simple / O(n2)";
		ft_bubble_sort(ft_valid_and_convert(args, bench), bench);
	}
	else if (ft_strncmp(args[0], "--medium", 8) == 0 || ft_strncmp(args[1], "--medium", 8) == 0)
	{
		bench -> strategy = "Medium / O(n√n)";
		ft_bucket(ft_valid_and_convert(args, bench), bench);
	}
/*	else if (ft_strncmp(args[0], "--complex", 9) == 0 || ft_strncmp(args[1], "--complex", 9) == 0)
	{
		bench -> strategy = "Complex / O(n log n)";
		return (ft_radix(ft_valid_and_convert(args, bench)));
	}
	else if (ft_strncmp(args[0], "--adaptive", 10) == 0 || ft_strncmp(args[1], "--adaptive", 10) == 0)
	{
		bench -> strategy = "Adaptive";
		return (ft_adaptive_algo(ft_valid_and_convert(args, bench)));
	}*/
	else
		ft_bucket(ft_valid_and_convert(args, bench), bench);
}

int	push_swap(int argc, char **argv)
{
	char	**args;
	t_bench	*bench;

	t_stack	*aux;
	int		count;
	t_node_list	*tmp;

	args = NULL;
	bench = initialise_bench();

	/* argument parsing */
	args = new_args(argc, argv, args);
	// DISORDER
	ft_flag_search_parsing(args, bench); // this calls valid and convert, which returns stack_a
									// select strategy (if not entered via console)
	aux = input_conversion(args);
	count = 0;
	tmp = aux ->head;
	while (count < aux->size)
	{
		//printf("%d\n", tmp->content);
		tmp = tmp->next;
		count++;
	}

	/* print bench (it called via console) */
	free(args);
	return (0);
}
