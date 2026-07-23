/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 10:24:06 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 12:50:14 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*static void	del(void *content)
{
	free(content);
}*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buffer;

	buffer = NULL;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		buffer = (*lst)-> next;
		del((*lst)-> content);
		free(*lst);
		*lst = buffer;
	}
	free(*lst);
}

/*int	main(void)
{
	t_list	*header;

	header = ft_lstnew(ft_strdup("position 1"));
	ft_lstadd_front(&header, ft_lstnew(ft_strdup("position 2")));
	ft_lstclear(&header, del);
	return (0);
}*/
