/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:41:53 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:13:48 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*thing;

	thing = s;
	while (n > 0)
	{
		*thing = (unsigned char) c;
		thing++;
		n--;
	}
	return (s);
}

/*int	main(void)
{
	char	str[] = "This is a string";

	ft_memset(str, '#', 7);
	printf("%s", str);
	return (0);
}*/
