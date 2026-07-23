/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:56:59 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:03:27 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
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

/*int	main(void)
{
	char	str[] = "	387a4i";
	char	str2[] = "45:3";
	char	str3[] = "+-76!f";
	char	str4[] = "--54";
	char	str5[] = "-21474836448";

	printf("Print this bullshit: %d\n", ft_atoi(str));
	printf("Print this bullshit: %d\n", ft_atoi(str2));
	printf("Print this bullshit: %d\n", ft_atoi(str3));
	printf("Print this bullshit: %d\n", ft_atoi(str4));
	printf("Print this bullshit: %d\n", ft_atoi(str5));
	return (0);
}*/
