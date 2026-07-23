/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:12:44 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 12:50:45 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int	main(void)
{
	t_list *header;

	header = NULL;
	ft_lstadd_front(&header, ft_lstnew("position 1"));
	ft_lstadd_front(&header, ft_lstnew("position 2"));
	printf("First node: %s\n",(char *)header -> content);
	printf("Second node: %s", (char *)header -> next -> content);
	return (0);
}*/
