/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:29:44 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/09 13:45:37 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *nptr)
{
	int			i;
	long int	num;
	int			sign;
	char		*number;

	number = (char *)nptr;
	i = 0;
	sign = 1;
	num = 0;
	while (number[i] == ' ' || (number[i] >= 9 && number[i] <= 13))
		i++;
	if (number[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (number[i] == '+')
		i++;
	while (number[i] >= '0' && number[i] <= '9')
	{
		num = (num * 10) + (number[i] - '0');
		i++;
	}
	return (num * sign);
}