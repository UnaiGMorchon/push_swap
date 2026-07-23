/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 10:56:20 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 12:50:24 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*static void	function(void *content)
{
	printf("Printf %s", (char *)content);
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

/*int	main(void)
{
	t_list	*header;

	header = NULL;
	ft_lstadd_front(&header, ft_lstnew("position 1\n"));
	ft_lstadd_front(&header, ft_lstnew("position 2\n"));
	ft_lstadd_back(&header, ft_lstnew("position 3\n"));
	ft_lstiter(header, function);
	return (0);
}*/
