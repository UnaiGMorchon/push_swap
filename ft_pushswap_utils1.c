/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:20:17 by patperez          #+#    #+#             */
/*   Updated: 2026/07/23 10:37:52 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

t_node_list	*ft_newnode(int content)
{
	t_node_list	*new_node;

	new_node = malloc(sizeof(t_node_list));
	if (!new_node)
		return (NULL);
	new_node -> next = NULL;
	new_node -> prev = NULL;
	new_node -> index = 0;
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

void	ft_stackadd_front(t_stack *stack, t_node_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack -> tail == NULL)
	{
		stack -> head = new_node;
		stack -> tail = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node -> next = stack -> head;
		new_node -> prev = stack -> tail;
		stack -> head -> prev = new_node;
		stack -> tail -> next = new_node;
		stack -> head = new_node;
	}
	stack -> size += 1;
}

void	ft_stackadd_back(t_stack *stack, t_node_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack -> head == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node -> prev = stack -> tail;
		new_node->next = stack->head;
		stack-> tail-> next = new_node;
		stack->head->prev = new_node;
		stack -> tail = new_node;
	}
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	stack -> size += 1;
}

void	ft_clearstack(t_stack *lst)
{
	t_node_list	*buffer;
	t_node_list	*tmp;

	buffer = NULL;
	if (!lst)
		return ;
	tmp = lst -> head;
	while (lst->size)
	{
		buffer = tmp-> next;
		free(tmp);
		tmp = buffer;
		lst->size -= 1;
	}
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
	free(lst);
}
