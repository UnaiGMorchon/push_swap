/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:07:25 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 12:50:31 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*int	main(void)
{
	t_list	*result;
	t_list	*header;

	header = ft_lstnew("position 1");
	header -> next = ft_lstnew("position 2");
	header -> next = ft_lstnew("position 3");
	result = ft_lstlast(header);
	printf("List count: %d", ft_lstsize(header));
	printf("Last position: %s", (char *)result -> content);
	return (0);
}*/
