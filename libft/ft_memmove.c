/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:58:04 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:13:17 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

static void	ft_aux_tofill(char *destin, const char *source, size_t n)
{
	size_t	counter;

	if (destin > source)
	{
		counter = n;
		while (counter > 0)
		{
			counter--;
			destin[counter] = source[counter];
		}
	}
	else
	{
		counter = 0;
		while (counter < n)
		{
			destin[counter] = source[counter];
			counter++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destin;
	const char	*source;

	destin = (char *)dest;
	source = (const char *)src;
	if (destin == source || n == 0)
		return (destin);
	ft_aux_tofill(destin, source, n);
	return (dest);
}

/*int	main(void)
{
	char	str[] = "String after memmove";
	char	dest_str[] = "First string";

	printf("%s", dest_str);
	ft_memmove(dest_str, str, 7);
	printf("%s", dest_str);
	return (0);
}*/
