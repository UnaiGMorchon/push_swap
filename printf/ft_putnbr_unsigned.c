/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:31:31 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/25 15:00:39 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned long	number;
	int				counter;
	char			c;

	number = nb;
	counter = 0;
	if (number >= 10)
	{
		counter += ft_putnbr_unsigned(number / 10);
	}
	c = (number % 10) + '0';
	counter += write(1, &c, 1);
	return (counter);
}
