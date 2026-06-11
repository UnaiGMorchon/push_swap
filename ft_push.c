/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:35:09 by patperez          #+#    #+#             */
/*   Updated: 2026/06/11 16:03:37 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "pushswap_lib.h"
#include <stdio.h>
#include <stdlib.h>

/*typedef struct  node
    {
        struct  node *next;
        int    content;
    } node_list;*/

node_list	*ft_lstnew(int content)
{
	node_list	*new_node;

	new_node = malloc(sizeof(node_list));
	if (!new_node)
		return (NULL);
	new_node -> next = NULL;
	new_node -> content = content;
	return (new_node);
}

node_list	*ft_lstlast(node_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack -> next;
	return (stack);
}

void	ft_lstadd_front(node_list **stack, node_list *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node -> next = *stack;
	*stack = new_node;
}

void	ft_lstadd_back(node_list **stack, node_list *new_node)
{
	node_list	*last;

	if (!stack || !new_node)
		return ;
	new_node -> next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last = ft_lstlast(*stack);
	last -> next = new_node;
}

/* take first element atop b and put it atop a. nothing done if b empty */
void	ft_pa(node_list **stack_a, node_list **stack_b)
{
	node_list	*tmp;

	if (!stack_a || !stack_b)
		return ;
	if (*stack_b == NULL)
		return ;
	tmp = (*stack_b)-> next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = tmp;
}

/* take first element atop a and put it atop b. nothing done if a empty */
void	ft_pb(node_list **stack_b, node_list **stack_a)
{
	node_list	*tmp;

	if (!stack_b || !stack_a)
		return ;
	if (*stack_a == NULL)
		return ;
	tmp = (*stack_a)-> next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = tmp;
}

int	main(void)
{
	node_list	*stack_a;
	node_list	*stack_b;
	node_list	*node_a;
	node_list	*node_b;

	stack_a = NULL;
	stack_b = NULL;
	node_a = ft_lstnew(1);
	node_b = ft_lstnew(2);
	/* STACK_A */
	ft_lstadd_back(&stack_a, node_a);
	ft_lstadd_back(&stack_a, ft_lstnew(12));
	ft_lstadd_back(&stack_a, ft_lstnew(13));
	/* STACK_B */
	ft_lstadd_back(&stack_b, node_b);
	ft_lstadd_back(&stack_b, ft_lstnew(22));
	
	/*while (stack_a)
	{
		printf("%d\n", stack_a -> content);
		stack_a = stack_a -> next;
	}
	while (stack_b)
    {
        printf("%d\n", stack_b -> content);
        stack_b = stack_b -> next;
    }
	printf("Salida\n\n");*/

	ft_pa(&stack_a, &stack_b);
	printf("First A node: %d\n", stack_a -> content);
	printf("Second A node: %d\n", stack_a -> next -> content);
	printf("First B node: %d\n", stack_b -> content);

	return (0);
}
