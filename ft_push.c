/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:35:09 by patperez          #+#    #+#             */
/*   Updated: 2026/06/10 13:53:18 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "pushswap_lib.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct  node
    {
        struct  node *next;
        void    *content;
    } node_list;

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

node_list   *ft_lstlast(node_list *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next != NULL)
        stack = stack -> next;
    return (stack);
}

void    ft_lstadd_back(node_list **stack, node_list *new_node)
{
    if (!stack || !new_node)
        return ;
    if (*stack)
		ft_lstlast(*stack) -> next = new_node;
    else
    	*stack = new_node;
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	size_t	i;
	char	*ptr;

	ptr = 0;
	i = 0;
	if (nmemb != 0 && size > (size_t) -1 / nmemb)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	while (i < total)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

/* take first element atop b and put it atop a. nothing done if b empty */
void	ft_pa(node_list **stack_a, node_list **stack_b)
{
	node_list	*temp;

	if (!stack_a || !stack_b)
		return ;
	if (*stack_b == NULL)
		return ;
	node_list	*new_a_head;
	new_a_head = (node_list *)ft_calloc(1, sizeof(node_list));
	if (new_a_head == NULL)
		return ;
	*temp = *stack_a;
	*stack_a = (*stack_b) -> content;
	*stack_a -> next = *temp;

	(*stack_b) -> next = *stack_a;
	(*stack_a) -> content = *stack_b;
	free(*stack_b);
	stack_b = NULL;
	*stack_b = (*stack_b) -> next;
}

/* take first element atop a and put it atop b. nothing done if a empty */
void	ft_pb(node_list **stack_a, node_list **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_b == NULL)
		return ;
	node_list *new_b_head;
	new_b_head = (node_list *)ft_calloc(1, sizeof(node_list));
	if (new_b_head == NULL)
		return ;
	(*stack_a) -> next = *stack_b;
	(*stack_b) -> content = *stack_a;
	free(*stack_a);
	stack_a = NULL;
	*stack_a = (*stack_a) -> next;
}

int	main(void)
{
	node_list	*stack_a;
	node_list	*stack_b;

	stack_a = ft_lstnew("A STACK POS 1");
	stack_b = ft_lstnew("B STACK POS 1");
	ft_lstadd_back(&stack_a, ft_lstnew("A POS 2"));
	ft_lstadd_back(&stack_a, ft_lstnew("A POS 3"));
	ft_lstadd_back(&stack_b, ft_lstnew("B POS 2"));
	
	printf("First node: %s\n",(char *)stack_a -> content);
	printf("Second node: %s\n", (char *)stack_a -> next -> content);
	while (stack_a != NULL)
	{
		printf("%s\n", (char *)stack_a -> content);
		stack_a = stack_a -> next;
	}

	ft_pa(&stack_a, &stack_b);

	return (0);
}
