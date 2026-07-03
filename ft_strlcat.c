/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 09:07:15 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/03 09:10:01 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	j = 0;
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dest;
	j = 0;

	if (size <= len_dest)
		return (size + len_src);
	while (src[j] != '\0' && j < size - len_dest - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dest + len_src);
}
