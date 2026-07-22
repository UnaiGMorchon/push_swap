/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:19:02 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:31:03 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declare an integer variable 'bits' to count the maximum bit length needed.
	2. Initialize 'bits' counter to 0 before processing the size.
	3. Loop while 'size' is greater than 0 to calculate binary bit depth.
	4. Divide 'size' by 2 in each iteration to shift down bit by bit.
	5. Increment 'bits' counter to keep track of total binary digits required.
	6. Return the total number of bits required to represent the largest index value.
*/

static int	ft_get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while (size != 0)
	{
		size = size / 2;
		bits ++;
	}
	return (bits);
}
/*
	1. Declare pointer 'lst_b' for auxiliary stack, counter 'i', 'max_bits', and 'size'.
	2. Initialize empty stack 'lst_b' to hold elements during binary sorting passes.
	3. Reset current bit position counter 'i' to 0.
	4. Determine max bits needed based on highest index (stack size minus one).
	5. Loop through each bit position from 0 up to 'max_bits' - 1.
	6. Store current size of 'lst_a' to iterate through all elements in current pass.
	7. Loop through all elements currently in stack A.
	8. Check if the i-th bit of the current head node's index is equal to 1.
	9. If bit is 1, rotate stack A with 'ft_ra' to keep element in stack A.
	10. If bit is 0, push top element from stack A to stack B using 'ft_pb'.
	11. Push all elements from stack B back to stack A using 'ft_pa' to finish pass.
	12. Increment bit index 'i' to evaluate the next binary significance level.
	13. Free all memory associated with auxiliary stack B after sorting completes.
*/

void	ft_radix(t_stack *lst_a, t_bench *bench)
{
	t_stack		*lst_b;
	int			i;
	int			max_bits;
	int			size;

	lst_b = ft_newstack();
	i = 0;
	max_bits = ft_get_max_bits(lst_a->size - 1);
	while (i < max_bits)
	{
		size = lst_a -> size;
		while (size-- > 0)
		{
			if (((lst_a -> head -> index >> i) & 1) == 1)
				ft_ra(lst_a, bench);
			else
				ft_pb(lst_b, lst_a, bench);
		}
		while (lst_b-> size)
			ft_pa(lst_a, lst_b, bench);
		i++;
	}
	ft_clearstack(lst_b);
}
