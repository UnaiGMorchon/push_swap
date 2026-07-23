/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:36:11 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:08:19 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	ft_aux_digit_count(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digits++;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*convert;
	int		len;
	long	number;

	number = n;
	len = ft_aux_digit_count(n);
	convert = (char *)malloc((len + 1) * (sizeof(char)));
	if (convert == NULL)
		return (NULL);
	convert[len] = '\0';
	len--;
	convert[len] = '0';
	if (n < 0)
	{
		convert[0] = '-';
		number = -number;
	}
	while (number > 0)
	{
		convert[len--] = ((number % 10) + '0');
		number = number / 10;
	}
	return (convert);
}

/*int	main(void)
{
	printf("Print this: %s", ft_itoa(0));
	return (0);
}*/
