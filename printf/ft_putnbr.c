/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:31:04 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/25 15:00:45 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	char	c;
	int		counter;

	nb = n;
	counter = 0;
	if (nb < 0)
	{
		counter += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		counter += ft_putnbr(nb / 10);
	}
	c = (nb % 10) + '0';
	counter += write(1, &c, 1);
	return (counter);
}
/*
#include <stdio.h>

int	main(void)
{
	write(1, "Test 1 : ", 9);
	ft_putnbr_fd(50, 1);
	write(1, "\n", 1);
	write(1, "Test 2 : ", 9);
	ft_putnbr_fd(2147483647, 1);
	write(1, "\n", 1);
	write(1, "Test 3 : ", 9);
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);
	write(1, "Test 4 : ", 9);
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);
	return (0);
}*/