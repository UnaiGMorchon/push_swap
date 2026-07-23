/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:37:58 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:20:45 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	counter;
	size_t	to_conc;
	size_t	dlen;
	size_t	slen;

	counter = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	to_conc = size - dlen - 1;
	if (dlen >= size)
		return (size + slen);
	while (src[counter] && to_conc)
	{
		dst[dlen + counter] = src[counter];
		counter++;
		to_conc--;
	}
	dst[dlen + counter] = '\0';
	return (dlen + slen);
}

/*int	main(void)
{
	char	src_str[] = "Source string";
	char	dest_str[] = "Destination string";
	size_t	result;

	result = ft_strlcat(dest_str, src_str, 22);
	printf("Length: %zu", result);
	printf("\n%s", dest_str);
	return (0);
}*/
