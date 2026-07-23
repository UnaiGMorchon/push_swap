/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:44:50 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 12:49:59 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)-> next = new;
	else
		*lst = new;
}

/*int	main(void)
{
	t_list	*header;

	header = NULL;
	ft_lstadd_front(&header, ft_lstnew("position 1"));
	ft_lstadd_front(&header, ft_lstnew("position 2"));
	printf("First node: %s\n",(char *)header -> content);
	printf("Second node: %s\n", (char *)header -> next -> content);
	ft_lstadd_back(&header, ft_lstnew("position 3"));
	while (header)
		{
			printf("List: %s\n", (char *)header -> content);
			header = header -> next;
		}
	return (0);
}*/
