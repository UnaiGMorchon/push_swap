/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:35:09 by patperez          #+#    #+#             */
/*   Updated: 2026/06/10 09:46:30 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_lib.h"

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
void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_b == NULL)
		return ;
	struct node_type *new_a_head;
	new_a_head = (struct node_type *)calloc(1, sizeof(struct node_type));
	if (new_a_head == NULL)
		return ;
	stack_b -> next = *stack_a;
	stack_a -> content = *stack_b;
	free(*stack_b);
	stack_b = NULL;
	stack_b = stack_b -> next;
}

/* take first element atop a and put it atop b. nothing done if a empty */
void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_b == NULL)
		return ;
	struct node_type *new_b_head;
	new_b_head = (struct node_type *)calloc(1, sizeof(struct node_type));
	if (new_b_head == NULL)
		return ;
	stack_a -> next = *stack_b;
	stack_b -> content = *stack_a
	free(*stack_a);
	stack_a = NULL;
	stack_a = stack_a -> next;
}

int	main(void)
{
	t_list	*stack_a;
	t_list	*stack_b;

	node_type *current = head;
	while (current != NULL)
	{
		printf("%d\n", current -> content);
		current = current -> next;
	}

	return (0);
}
