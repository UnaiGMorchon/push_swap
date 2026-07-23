/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:05:44 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:19:09 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*ptr;

	ptr = malloc(ft_strlen(src) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, src, ft_strlen(src) + 1);
	return (ptr);
}

/*int	main(void)
{
	char	*dest;

	dest = ft_strdup("Sashimi");
	printf("%s", dest);
	free(dest);
	return (0);
}*/
