/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:20:17 by patperez          #+#    #+#             */
/*   Updated: 2026/06/10 12:38:34 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include "pushswap_lib.h"

node_list   *ft_lstnew(void *content)
{
    node_list   *new_node;

    new_node = malloc(sizeof(node_list));
    if (!new_node)
        return (NULL);
    new_node -> next = NULL;
    new_node -> content = content;
    return (new_node);
}

void    ft_lstadd_back(node_list **stack, node_list *new_node)
{
    if (!stack || !new_node)
        return ;
    if (*stack)

    new_node -> next = *stack;
    *stack = new_node;
}

node_list	*ft_lstlast(node_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack -> next;
	return (stack);
}
