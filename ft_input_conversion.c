/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:58:07 by patperez          #+#    #+#             */
/*   Updated: 2026/07/06 13:08:43 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	ft_is_validint(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '-')
		i++;
	while (input[i] != '\0')
	{
		if (ft_isdigit(input[i]) != 1)
			return (0); // return error message?
		i++;
	}
	if (ft_atoi(input) > 2147483647 || ft_atoi(input) < -2147483648)
		return (0); // return error message?
	return (1);
}

int	ft_isrepeat(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (input[i] != '\0')
	{
		while (input[i] != input[j])
		{
			if (input[i] == input[j])
				return (0) // return error message?
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
}
