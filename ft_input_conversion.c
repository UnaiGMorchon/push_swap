/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:58:07 by patperez          #+#    #+#             */
/*   Updated: 2026/07/15 09:09:19 by ugarcia-         ###   ########.fr       */
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
			{
				return (0);
			}
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
	t_node_list	*new;

	i = 0;
	stack_a = ft_newstack();
	if (!stack_a)
		return (NULL);
	while (args[i])
	{
		new = ft_lstnew(ft_atol(args[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (stack_a);
}


