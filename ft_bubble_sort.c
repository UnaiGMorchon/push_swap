/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/07/17 10:02:23 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declare 'swapped' as a boolean-like flag to check if elements were moved.
	2. Declare an integer 'i' to count the steps in the current sorting pass.
	3. Security check: if the stack or its head is NULL, stop immediately.
	4. Initialize the 'swapped' flag to 1 to force the while loop to start.
	5.Run main sorting loop as long as at least one swap happened previous pass
	6. Reset the step counter 'i' to 0 at the beginning of each pass.
	7. Reset the 'swapped' flag to 0, assuming the list might already be sorted.
	8. Run an inner loop to check pairs up to the total stack size minus one.
	9.Compare the content of the current head node with the content of next node
	10. If the current node is larger, call ft_sa to swap the top two elements.
	11. Set the 'swapped' flag to 1 because a change was made to the list.
	12. Call ft_ra to rotate the stack, shifting the next pair to the top.
	13. Increment the step counter 'i' by 1 to move forward.
	14.Call ft_ra one extra time after inner loop to fix final alignment of stack
*/

void	ft_bubble_sort(t_stack *lst, t_bench *bench)
{
	int	swapped;
	int	i;

	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < lst -> size - 1)
		{
			if (lst-> head-> content > lst-> head -> next -> content)
			{
				ft_sa(lst, bench);
				swapped = 1;
			}
			ft_ra(lst, bench);
			i ++;
		}
		ft_ra(lst, bench);
	}
	ft_lstclear(lst);
}
