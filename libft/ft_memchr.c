/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:48:48 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:10:55 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	charac;
	unsigned char	*source;
	size_t			counter;

	counter = 0;
	source = (unsigned char *)s;
	charac = (unsigned char)c;
	while (counter < n)
	{
		if (source[counter] == charac)
			return (&source[counter]);
		else
			counter++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "Find in this string";

	printf("Location: %p", ft_memchr(str, 't', 8));
	printf("\nCharacter: %s", (char *)ft_memchr(str, 't', 8));
	return (0);
}
*/
