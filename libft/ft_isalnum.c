/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:38:47 by patperez          #+#    #+#             */
/*   Updated: 2026/05/12 16:26:24 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	ft_isalnum('a');
	if (ft_isalnum('3'))
		write(1, "a", 1);
	else
		write(1, "N", 1);
	return (0);
}*/
