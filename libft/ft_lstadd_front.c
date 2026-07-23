/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:12:05 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 12:50:10 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list *header;

	header = NULL;
	ft_lstadd_front(&header, ft_lstnew("position 1"));
	ft_lstadd_front(&header, ft_lstnew("position 2"));
	printf("First node: %s\n",(char *)header -> content);
	printf("Second node: %s", (char *)header -> next -> content);
	return (0);
}
*/
