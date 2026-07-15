/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:11:07 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/25 15:02:04 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	counter;

	if (!s)
		s = "(null)";
	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		counter += write(1, &s[i], 1);
		i++;
	}
	return (counter);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*s;

	s = "hello";
	ft_putstr_fd(s, 1);
	//printf ("%s\n", s);
}
*/