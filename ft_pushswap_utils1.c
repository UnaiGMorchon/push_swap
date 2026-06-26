/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:20:17 by patperez          #+#    #+#             */
/*   Updated: 2026/06/26 14:06:11 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswaplib.h"

t_node_list	*ft_lstnew(int content)
{
	t_node_list	*new_node;

	new_node = malloc(sizeof(t_node_list));
	if (!new_node)
		return (NULL);
	new_node -> next = NULL;
	new_node -> prev = NULL;
	new_node -> content = content;
	return (new_node);
}

t_stack	*ft_newstack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack -> head = NULL;
	stack -> tail = NULL;
	stack -> size = 0;
	return (stack);
}

t_node_list	*ft_lstlast(t_node_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst -> next;
	return (lst);
}

t_node_list	*ft_lstfind(t_node_list **lst)
{
	t_node_list	*prev;

	if (!lst || (*lst)-> next == NULL)
		return (NULL);
	while ((*lst)-> next != NULL && (*lst)-> next -> next != NULL)
	{
		*lst = (*lst)-> next;
	}
	prev = *lst;
	return (prev);
}

void	ft_lstadd_front(t_stack *stack, t_node_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack -> tail == NULL)
	{
		stack -> head = new_node;
		stack -> tail = new_node;
	}
	new_node -> next = stack -> head;
	new_node -> prev = stack -> tail;
	stack-> head = new_node;
	stack -> size +=1;
}

void	ft_lstadd_back(t_stack *stack, t_node_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack -> head == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	stack-> tail-> next = new_node;
	new_node -> prev = stack -> tail;
	stack -> tail = new_node;
	stack -> size += 1;
}

