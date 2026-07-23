/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:23:07 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:21:47 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		if ((unsigned char)s1[counter]
			> (unsigned char)s2[counter])
			return (1);
		else if ((unsigned char)s1[counter]
			< (unsigned char)s2[counter])
			return (-1);
		counter++;
	}
	return (0);
}

/*int	main(void)
{
	char	str_1[] = "Ramen";
	char	str_2[] = "Ramen";
	printf("Compare: %d", ft_strncmp(str_1, str_2, 4));
	return (0);
}*/
