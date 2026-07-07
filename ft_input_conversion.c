/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:58:07 by patperez          #+#    #+#             */
/*   Updated: 2026/07/07 09:12:29 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	ft_is_validint(char **argv)
{
	int	i;

	i = 0;
	printf("INPUT %s\n", *argv);
	if (*argv[i] == '-')
		i++;
	while (*argv[i])
	{
		if (!ft_isdigit(*argv[i]))
		{
			printf("ERROR: NOT A DIGIT\n");
			return (0); // return error message?
		}
		i++;
	}
	if (ft_atoi(*argv) > -2147483648 && ft_atoi(*argv) > 2147483647)
	{
		printf("ERROR: OVERFLOW\n");
		return (0); // return error message?
	}
	return (1);
}

/*int	ft_isrepeat(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (argv[i] != '\0')
	{
		while (argv[i] != argv[j])
		{
			if (argv[i] == argv[j])
				return (0); // return error message?
			j++;
		}
		i++;
	}
	return (1);
}

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
