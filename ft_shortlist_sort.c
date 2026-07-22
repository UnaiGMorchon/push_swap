/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortlist_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:52:16 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:32:11 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declare an integer variable 'counter' to keep track of iterations for size 3 lists.
	2. Initialize 'counter' to 0 before starting sorting logic.
	3. If the stack size is exactly 2, compare the top two elements.
	4. If the first element's index is greater than the second, swap them using 'ft_sa'.
	5. If the stack size is 3, start an evaluation loop to fix stack order.
	6. Swap top elements with 'ft_sa' if current head is larger than the next element.
	7. Exit function early if elements are already in perfect ascending order.
	8. Otherwise, reverse rotate stack with 'ft_rra' to shift elements into position.
	9. Increment 'counter' to prevent infinite execution passes.
*/

static void	ft_shortlist_under_three(t_stack *lst, t_bench *bench)
{
	int	counter;

	counter = 0;
	if (lst -> size == 2)
	{
		if (lst -> head -> index > lst -> head -> next -> index)
			ft_sa(lst, bench);
	}
	if (lst -> size == 3)
	{
		while (counter < lst -> size)
		{
			if (lst -> head -> index > lst -> head -> next -> index)
				ft_sa(lst, bench);
			else if ((lst -> head -> index < lst -> head -> next -> index)
				&& (lst -> head -> next -> index < lst -> tail -> index)
				&& (lst -> head -> index < lst -> tail -> index))
				return ;
			else
				ft_rra(lst, bench);
			counter++;
		}
	}
}
/*
	1. Declare pointer 'lst_b' for auxiliary stack and integer 'min_index' to track targets.
	2. Allocate and initialize an empty stack 'lst_b'.
	3. Initialize target 'min_index' to 0 to search for smallest elements sequentially.
	4. Loop while primary stack size is greater than 3 elements.
	5. If the current head node matches 'min_index', push it to stack B using 'ft_pb' and increment target.
	6. Otherwise, rotate stack A with 'ft_ra' to scan the next element.
	7. Sort remaining 3 elements in stack A using 'ft_shortlist_under_three'.
	8. Ensure stack B is in descending order by calling 'ft_sb' if needed.
	9. Push all elements back from stack B to stack A using 'ft_pa'.
	10. Free memory allocated for auxiliary stack B.
*/

static void	ft_shortlist_under_five(t_stack *lst, t_bench *bench)
{
	t_stack		*lst_b;
	int			min_index;

	lst_b = ft_newstack();
	min_index = 0;
	while (lst -> size > 3)
	{
		if (lst -> head -> index == min_index)
		{
			ft_pb(lst_b, lst, bench);
			min_index++;
		}
		else
			ft_ra(lst, bench);
	}
	ft_shortlist_under_three(lst, bench);
	if (lst_b -> head -> index < lst_b -> head -> next -> index)
		ft_sb(lst_b, bench);
	while (lst_b -> size)
		ft_pa(lst, lst_b, bench);
	ft_clearstack(lst_b);
}
/*
	1. Check if stack size is 3 or smaller, and delegate to 'ft_shortlist_under_three'.
	2. Check if stack size is 4 or 5, and delegate to 'ft_shortlist_under_five'.
	3. Free memory associated with the main stack structure after sorting completes.
*/

void	ft_shortlist_sort(t_stack *lst, t_bench *bench)
{
	if (lst -> size <= 3)
		ft_shortlist_under_three(lst, bench);
	if (lst -> size == 4 || lst -> size == 5)
		ft_shortlist_under_five(lst, bench);
	ft_clearstack(lst);
}
