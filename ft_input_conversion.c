/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:58:07 by patperez          #+#    #+#             */
/*   Updated: 2026/07/09 15:24:58 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

long int	ft_is_validint(char **argv)
{
	int			i;
	int			j;
	long int	result;

	j = -1;
	while (argv[++j])
	{
		printf("INPUT %s\n", argv[j]); // *argv es exactamente lo mismo que argv[0]
		i = 0;
		if (argv[j][0] == '-')
			i++;
		while (argv[j][i]) // while (*argv[i]) se va a mover por los diferentes argumentos de la línea de comandos, no por los caracteres de un solo argumento. Para moverte por los caracteres de una sola cadena, necesitas escribirlo como (*argv)[i] o usar argv[0][i].
		{
			if (!ft_isdigit(argv[j][i++]))
			{
				return (0); // return error message?
			}
		}
		result = ft_atol(argv[j]);
		if (result > 2147483647 || result < -2147483648)
		{
			return (0); // return error message?
		}
	}
	return (1);
}

int	ft_isrepeat(char **args)
{
	int	i;
	int	j;

	j = -1;
	while (args[++j][i])
	{
		while (args[i] != args[j])
		{
			printf("repeat antes %s\n", args[j]);
			if (args[i] == args[j])
			printf("repeat despues %s\n", args[j]);
				return (0); // return error message?
			i++;
		}
		j++;
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
