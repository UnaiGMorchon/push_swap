/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:42:49 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:23:50 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	ft_aux_trimmer(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	j = ft_strlen(s1) - 1;
	while (ft_aux_trimmer(set, s1[i]))
		i++;
	while (ft_aux_trimmer(set, s1[j]))
		j--;
	return (ft_substr(s1, i, (j + 1 - i)));
}

/*int	main(void)
{
	char	str[] = "fwtwtfSpiritedwtfAwaywftwtf";
	char	set[] = "wtf";

	printf("Trimmed string: %s", ft_strtrim(str, set));
	return (0);
}*/
