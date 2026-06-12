/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:54:15 by patperez          #+#    #+#             */
/*   Updated: 2026/06/12 09:22:34 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"
#include <stdio.h>

void	ft_ra(node_list **stack_a)
{

}

int	main(void)
{
	node_list   *stack_a;
	node_list   *stack_b;
	node_list   *node_a;
	node_list   *node_b;

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

    ft_ra(&stack_a);
	printf("First A node: %d\n", stack_a -> content);
	printf("Second A node: %d\n", stack_a -> next -> content);
	printf("First B node: %d\n", stack_b -> content);

	return (0);
}
