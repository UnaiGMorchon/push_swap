/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:02:29 by patperez          #+#    #+#             */
/*   Updated: 2026/05/12 16:28:12 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	new_l;
	int		i;

	i = 0;
	new_l = '\n';
	while (s && s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &new_l, 1);
}

/*int	main(void)
{
	ft_putendl_fd("Write this", 1);
	return (0);
}*/
