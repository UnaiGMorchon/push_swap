/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_may.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:18:52 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/25 15:00:27 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa_may(unsigned long int nb)
{
	unsigned long int	number;
	int					counter;
	char				c;

	number = nb;
	counter = 0;
	if (nb >= 16)
	{
		counter += ft_putnbr_hexa_may(number / 16);
	}
	c = (number % 16);
	if (c <= 9)
		c = c + '0';
	if (c >= 10 && c <= 15)
		c = (c - 10) + 'A';
	counter += write(1, &c, 1);
	return (counter);
}
/*
#include <unistd.h>

int	main(void)
{
	write(1, "Test 1 : ", 9);
	ft_putnbr_hexa_may_fd(8, 1);
	write(1, "\n", 1);
	return (0);
}*/