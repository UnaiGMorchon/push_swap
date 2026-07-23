/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:25:17 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:21:05 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	counter;

	counter = 0;
	if (size > 0)
	{
		while (counter < size - 1 && src[counter] != '\0')
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[counter] = '\0';
	}
	return (ft_strlen(src));
}

/*int	main(void)
{
	char	dest_str[] = "Destination string";
	char	src_str[] = "";
	size_t	result;

	result = ft_strlcpy(dest_str, src_str, 9);
	printf("Length: %zu", result);
	printf("\n mjdañ %s", dest_str);
	return (0);
}*/
