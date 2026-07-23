/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:53:40 by patperez          #+#    #+#             */
/*   Updated: 2026/05/14 13:54:31 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*static void	del(void *content)
{
	free(content);
}

static void	*function(void *content)
{
	char	*cast_cont;
	int	i;

	i = 0;
	cast_cont = (char *)content;
	while (cast_cont[i])
	{
		if (cast_cont[i] >= 97 && cast_cont[i] <= 122)
			cast_cont[i] = cast_cont[i] - 32;
		i++;
	}
	return (content);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*second_list;
	t_list	*copied_node;
	void	*tmp_content;

	second_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		tmp_content = f(lst-> content);
		copied_node = ft_lstnew(tmp_content);
		if (copied_node == NULL)
		{
			del(tmp_content);
			ft_lstclear(&second_list, del);
			return (NULL);
		}
		ft_lstadd_back(&second_list, copied_node);
		lst = lst -> next;
	}
	return (second_list);
}

/*int	main(void)
{
	t_list	*header;
	t_list	*another_header;

	header = NULL;
	ft_lstadd_front(&header, ft_lstnew(ft_strdup("position 1")));
	ft_lstadd_front(&header, ft_lstnew(ft_strdup("position 2")));
	ft_lstadd_front(&header, ft_lstnew(ft_strdup("position 3")));
	another_header = ft_lstmap(header, function, del);
	printf("Position: %s", (char *)another_header -> content);
	return (0);
}*/
