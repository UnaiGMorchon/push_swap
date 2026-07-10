/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/09 15:18:28 by patperez         ###   ########.fr       */
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

int	push_swap(int argc, char **argv)
{
	char	**args;
	t_bench	*bench;

	args = NULL;
	bench = malloc(sizeof(t_bench));
	bench = initialise_bench(bench);
	if (argc < 2)
		return (0);

	/* argument parsing */
	args = new_args(argc, argv, args);
	ft_is_validint(args);

	/* calculate disorder */
	/* parse flags (if entered) ?? */
	/* select strategy (if not entered via console) */
	/* print bench (it called via console) */
	return (0);
}
