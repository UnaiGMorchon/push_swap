/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/07/02 13:25:00 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
1. Declare 'swapped' as a boolean-like flag to check if elements were moved.
2. Declare an integer 'i' to count the steps in the current sorting pass.
3. Security check: if the stack or its head is NULL, stop immediately.
4. Initialize the 'swapped' flag to 1 to force the while loop to start.
5.Run the main sorting loop as long as at least one swap happened previous pass
6. Reset the step counter 'i' to 0 at the beginning of each pass.
7. Reset the 'swapped' flag to 0, assuming the list might already be sorted.
8. Run an inner loop to check pairs up to the total stack size minus one.
9.Compare the content of the current head node with the content of the next node
10. If the current node is larger, call ft_sa to swap the top two elements.
11. Set the 'swapped' flag to 1 because a change was made to the list.
12. Call ft_ra to rotate the stack, shifting the next pair to the top.
13. Increment the step counter 'i' by 1 to move forward.
14.Call ft_ra one extra time after the inner loop to fix final alignment of stack
*/

void	bubble_sort(t_stack *lst)
{
	int	swapped;
	int	i;

	if (lst == NULL || lst-> head == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < lst -> size - 1)
		{
			if (lst-> head-> content > lst-> head -> next -> content)
			{
				ft_sa(lst);
				swapped = 1;
			}
			ft_ra(lst);
			i ++;
		}
		ft_ra(lst);
	}
}

/* 
static void	ft_print_list(t_stack *stack, int size)
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
			"  prev       : %p\n"
			"  next       : %p\n\n",
			counter,
			(void *)lst_tmp,
			lst_tmp->content,
			(void *)lst_tmp->prev,
			(void *)lst_tmp->next
			);
		lst_tmp = lst_tmp->next;
		counter++;
	}
}

int	main(void)
{
	t_stack	*lst_a;

	lst_a = ft_newstack();
	// STACK_A
	ft_lstadd_back(lst_a, ft_lstnew(12));
	ft_lstadd_back(lst_a, ft_lstnew(15));
	ft_lstadd_back(lst_a, ft_lstnew(1));
	ft_lstadd_back(lst_a, ft_lstnew(13));
	ft_lstadd_back(lst_a, ft_lstnew(16));
	ft_lstadd_back(lst_a, ft_lstnew(18));
	ft_lstadd_back(lst_a, ft_lstnew(2));
	ft_lstadd_back(lst_a, ft_lstnew(9));
	// STACK_B

	printf("---------------STACK A-----------\n");
	ft_print_list(lst_a, lst_a -> size);

	bubble_sort(lst_a);
	printf("---------------sorted--------------- \n");
	ft_print_list(lst_a, lst_a -> size);
	printf("---------------%d lista tamaño A-----------\n", lst_a-> size);
	ft_lstclear(lst_a);
	return (0);
} */
