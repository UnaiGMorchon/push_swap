/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:36:28 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:17:06 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static size_t	ft_aux_length(const char *s, int start, char c)
{
	size_t	l;

	l = 0;
	while (s[start] && s[start] != c)
	{
		l++;
		start++;
	}
	return (l);
}

static int	ft_aux_count_words(const char *s, char c)
{
	int	count;
	int	words;

	count = 0;
	words = 0;
	while (s[count] != '\0')
	{
		if (s[count] != c && (count == 0 || s[count - 1] == c))
			words++;
		count++;
	}
	return (words);
}

static char	**ft_mop(char **array, int j)
{
	while (j > 0)
	{
		j--;
		free(array[j]);
	}
	free(array);
	return (NULL);
}

static char	**ft_substr_allocation(const char *s, char c, char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			array[j] = ft_substr(s, i, ft_aux_length(s, i, c));
			if (array[j] == NULL)
				return (ft_mop(array, j));
			i = i + ft_aux_length(s, i, c);
			j++;
		}
		else
			i++;
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	array = malloc(sizeof(char *) * (ft_aux_count_words(s, c) + 1));
	if (array == NULL)
		return (NULL);
	return (ft_substr_allocation(s, c, array));
}

/*int	main(void)
{
	char	str[] = "";
	char	lim = ' ';
	char	**split_value;
	int	i;

	i = 0;
	split_value = ft_split(str, lim);
	while (split_value[i] != NULL)
	{
		printf("%s", split_value[i]);
		free(split_value[i]);
		i++;
	}
	free(split_value);
	return (0);
}*/
