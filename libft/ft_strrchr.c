/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:02:06 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:22:37 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;
	while (counter)
	{
		if (s[counter] == (unsigned char)c)
			return ((char *)&s[counter]);
		else
			counter--;
	}
	if (s[counter] == (unsigned char)c)
		return ((char *)&s[counter]);
	return (NULL);
}

/*int	main(void)
{
	char	str[] = "This string";

	printf("Pointer found: %p", ft_strrchr(str, 's'));
	printf("\nPointer found: %s", ft_strrchr(str, 's'));
	return (0);
}*/
