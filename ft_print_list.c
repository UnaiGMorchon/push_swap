/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:17:46 by patperez          #+#    #+#             */
/*   Updated: 2026/07/17 13:19:52 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_list(t_stack *stack, int size)
{
	int			counter;
	t_node_list	*lst_tmp;

	counter = 0;
	lst_tmp = stack->head;

	while (counter < size)
	{
		printf(
		"Node %d\n"
			"  addr       : %p\n"
			"  content    : %d\n"
			"  index    : %d\n"
			"  prev       : %p\n"
			"  next       : %p\n\n",
			counter,
			(void *)lst_tmp,
			lst_tmp->content,
			lst_tmp->index,
			(void *)lst_tmp->prev,
			(void *)lst_tmp->next
		);
		lst_tmp = lst_tmp->next;
		counter++;
	}
}
