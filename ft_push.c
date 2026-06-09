/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:35:09 by patperez          #+#    #+#             */
/*   Updated: 2026/06/09 15:39:24 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_lib.h"

/* take first element atop b and put it atop a. nothing done if b empty */
void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_b == NULL)
		return ;
	stack_b -> next = *stack_a -> content;
	stack_a -> content = *stack_b;
	stack_b = stack_b -> next;
}

int	main(void)
{
	t_list	*stack_a;
	t_list	*stack_b;

	return (0);
}
