/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:58:07 by patperez          #+#    #+#             */
/*   Updated: 2026/07/10 08:41:47 by ugarcia-         ###   ########.fr       */
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
		args = (char**)malloc(sizeof(char*) * (argc)); // falta free???
		if (args == NULL)
			return (NULL);
		while (argv[i])
		{
			args[i - 1] = ft_strdup(argv[i]);
			i++;
		}
		args[i - 1] = NULL;
	}
	return (args);
}

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
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
/* 
void	input_conversion(int input)
{
	int	i;
	t_node_list	*lst_a;

	i = 0;
	while (input)
	{
		ft_lstadd_front(lst_a, input[i]);
		i++;
	}
 }*/
