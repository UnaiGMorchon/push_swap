/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:11:02 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/25 15:00:23 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
/*
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'U';
	ft_putchar_fd(c, 1);
	printf ("%c\n", c);
}*/
