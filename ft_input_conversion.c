/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:58:07 by patperez          #+#    #+#             */
/*   Updated: 2026/07/09 12:07:47 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

long int	ft_is_validint(char **argv)
{
	int			i;
	long int	result;

	i = 0;
	printf("INPUT %s\n", *argv); // *argv es exactamente lo mismo que argv[0]
	if ((*argv)[i] == '-')
		i++;
	while ((*argv)[i]) // while (*argv[i]) se va a mover por los diferentes argumentos de la línea de comandos, no por los caracteres de un solo argumento. Para moverte por los caracteres de una sola cadena, necesitas escribirlo como (*argv)[i] o usar argv[0][i].
	{
		if (ft_split(*argv, ' '))
		{
			printf("ERROR: NOT hecho split\n");
			return (0); // return error message?
			if (!ft_isdigit((*argv)[i]))
			{
				printf("ERROR: NOT A DIGIT\n");
				return (0); // return error message?
			}
		}
		i++;
	}
	result = ft_atoi(*argv);
	if (result > 2147483647 || result < -2147483648)
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
