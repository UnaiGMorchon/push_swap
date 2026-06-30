/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:54:15 by patperez          #+#    #+#             */
/*   Updated: 2026/06/30 09:09:34 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"
#include <stdio.h>

void	ft_rra(t_stack *lst_a)
{
	t_node_list	*tmp_newlast;

	tmp_newlast = lst_a -> head;
	if (!lst_a || lst_a == NULL)
		return ;
	tmp_newlast = lst_a -> tail-> prev;
	lst_a -> head = lst_a -> tail;
	lst_a -> tail = tmp_newlast;
}

void	ft_rrb(t_stack *lst_b)
{
	t_node_list	*tmp_newlast;

	tmp_newlast = lst_b -> head;
	if (!lst_b || lst_b == NULL)
		return ;
	tmp_newlast = lst_b -> tail-> prev;
	lst_b -> head = lst_b -> tail;
	lst_b -> tail = tmp_newlast;
}

void	ft_rrr(t_stack *lst_a, t_stack *lst_b)
{
	if ((!lst_a || lst_a == NULL) || (!lst_b || lst_b == NULL))
		return ;
	ft_rra(lst_a);
	ft_rrb(lst_b);
}


/* void	ft_print_list(t_stack *stack, int size)
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
			"  prev content: %d\n"
			"  prev       : %p\n"
			"  next content: %d\n"
			"  next       : %p\n\n",
			counter,
			(void *)lst_tmp,
			lst_tmp->content,
			lst_tmp->prev->content,
			(void *)lst_tmp->prev,
			lst_tmp->next->content,
			(void *)lst_tmp->next
			);
		lst_tmp = lst_tmp->next;
		counter++;
	}
}

int	main(void)
{
	//* STACK_A *
	t_stack	*lst_a;
 */
	//lst_a = NULL;
/* 	lst_a = ft_newstack();
	ft_lstadd_back(lst_a, ft_lstnew(12));
	ft_lstadd_back(lst_a, ft_lstnew(13));
	ft_lstadd_back(lst_a, ft_lstnew(14));
	ft_lstadd_back(lst_a, ft_lstnew(15));

	printf("list A: %d\n", lst_a -> size);
	ft_print_list(lst_a, lst_a -> size);

	ft_rra(lst_a);
	printf("list reverse A: %d\n", lst_a -> size);
	ft_print_list(lst_a, lst_a -> size);
 */
/* // * STACK_b *
	t_stack	*lst_b;

	//lst_a = NULL;
	lst_b = ft_newstack();
	ft_lstadd_back(lst_b, ft_lstnew(12));
	ft_lstadd_back(lst_b, ft_lstnew(13));
	ft_lstadd_back(lst_b, ft_lstnew(14));
	ft_lstadd_back(lst_b, ft_lstnew(15));

	printf("list B: %d\n", lst_b -> size);
	ft_print_list(lst_b, lst_b -> size);

	ft_rrb(lst_b);
	printf("list reverse B: %d\n", lst_b -> size);
	ft_print_list(lst_b, lst_b -> size);
 */
/* 	ft_lstclear(lst_a);
	//ft_lstclear(lst_b);
	return (0);
}
 */