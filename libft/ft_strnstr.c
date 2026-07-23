/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:25:45 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:22:16 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*biggum;
	size_t	count_big;
	size_t	count_lil;

	biggum = (char *)big;
	count_big = 0;
	count_lil = 0;
	if (little[count_lil] == 0)
		return (biggum);
	while (biggum[count_big] && count_big < len)
	{
		while (biggum[count_big + count_lil] == little[count_lil]
			&& biggum[count_big + count_lil]
			&& count_big + count_lil < len)
		{
			count_lil++;
			if (little[count_lil] == 0)
				return (biggum + count_big);
		}
		count_big++;
		count_lil = 0;
	}
	return (0);
}

/*int	main(void)
{
	char	big[] = "This guy are sick";
	char	little[] = "guy";

	printf("Search result: %p", ft_strnstr(big, little, 10));
	return (0);
}*/
