/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:21:17 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/25 15:00:19 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_void(unsigned long int str)
{
	int		counter;

	counter = 0;
	if (str == 0)
	{
		return (write(1, "(nil)", 5));
	}
	counter += write(1, "0x", 2);
	counter += ft_putnbr_hexa_min(str);
	return (counter);
}
