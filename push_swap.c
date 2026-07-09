/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/09 15:18:54 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

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

int	main(int argc, char **argv)
{
	char	**args;

	args = NULL;
	if (argc < 2)
		return (0);
	args = new_args(argc, argv, args);
	ft_is_validint(args);
	ft_isrepeat(argv);
	return (0);
}
