/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:36:11 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:18:55 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		charac;
	int			counter;

	charac = (char)c;
	counter = 0;
	while (s[counter])
	{
		if (s[counter] == charac)
			return ((char *)&s[counter]);
		else
			counter++;
	}
	if (s[counter] == charac)
		return ((char *)&s[counter]);
	return (NULL);
}

/*int	main(void)
{
	char	str[] = "Find in this string";

	ft_strchr(str, 't');
	printf("Pointer found: %p", ft_strchr(str, 't'));
	printf("\nPointer found: %s", ft_strchr(str, 't'));
	return (0);
}*/
