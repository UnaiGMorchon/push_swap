/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:42:06 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 12:50:39 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_box;

	new_box = malloc(sizeof(t_list));
	if (!new_box)
		return (NULL);
	new_box -> next = NULL;
	new_box -> content = content;
	return (new_box);
}

/*int	main(void)
{
	t_list	*str;

	str = ft_lstnew("weird");
	printf("Print this: %s", (char *)str -> content);
	return (0);
}*/
