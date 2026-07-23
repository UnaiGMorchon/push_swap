/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:27:23 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:11:38 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
		n--;
	}
	return (0);
}

/*int	main(void)
{
	char	str_1[] = "One string";
	char	str_2[] = "One string";

	printf("Comparison: %d", ft_memcmp(str_1, str_2, 7));
	return (0);
}*/
