/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:39:16 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:24:56 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	total;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	total = ft_strlen(s);
	if (start >= total)
		return (ft_calloc(1, sizeof(char)));
	if (len > total - start)
		len = total - start;
	new_string = malloc(len + 1);
	if (new_string == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		new_string[i] = s[start + i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

/*int	main(void)
{
	char	str[] = "Original string";

	printf("Substring: %s", ft_substr(str, 12, 4));
	return (0);
}*/
