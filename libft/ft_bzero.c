/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:38:17 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 15:04:08 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*convert;

	convert = s;
	while (n > 0)
	{
		*convert = '\0';
		convert++;
		n--;
	}
}

/*int	main(void)
{
	char	str[] = "This is a string";

	ft_bzero(str, 7);
	printf("%s", str);
	return (0);
}*/
