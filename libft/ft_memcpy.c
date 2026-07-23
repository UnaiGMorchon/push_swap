/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:37:46 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:11:48 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destin;
	const char	*source;
	size_t		pos_count;

	destin = (char *)dest;
	source = (const char *)src;
	pos_count = 0;
	if (destin == NULL && source == NULL)
		return (NULL);
	while (pos_count < n)
	{
		destin[pos_count] = source[pos_count];
		pos_count++;
	}
	return (dest);
}

/*int	main(void)
{
	char	str[] = "String after memcpy\n";
	char	dest_str[] = "Weird things";

	printf("%s\n", str);
	ft_memcpy(dest_str, str, 10);
	printf("%s\n", dest_str);
	return (0);
}*/
