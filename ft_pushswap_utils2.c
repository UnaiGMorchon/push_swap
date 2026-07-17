/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:51:52 by patperez          #+#    #+#             */
/*   Updated: 2026/07/17 15:57:06 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	args_count(int *i, int argc)
{
	int	counter;

	counter = 0;
	while (counter < (argc - *i))
	{
		counter++;
	}
	return (counter);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/*
	1. Declare a double variable 'y' to store the square root approximation.
	2. Declare an integer 'p' to find the integer part of the square root.
	3. Declare an integer 'square' to hold the squared value of p.
	4. Declare an integer 'c' to count the Newton-Raphson iteration cycles.
	5. Initialize loop counters and calculation variables to 0.
	6.Loop to find the closest lower integer whose square is less than or equal x
	7. Increment 'p' to test the next integer value.
	8. Calculate the square of the next integer to check against 'x'.
	9. Cast the found integer 'p' into a double type and assign it to 'y'.
	10. Run a loop exactly 10 times to refine the approximation.
	11. Apply the Babylonian/Newton-Raphson formula to find a closer root.
	12.If the square of the approximation exactly matches x,return it immediately
	13. Increment the iteration cycle counter 'c' by 1.
	14. Return the calculated square root approximation value.
*/

double	ft_sqroot(int x)
{
	double	y;
	int		p;
	int		square;
	int		c;

	p = 0;
	square = 0;
	c = 0;
	while (x > square)
	{
		p++;
		square = (p + 1) * (p + 1);
	}
	y = (double)p;
	while (c < 10)
	{
		y = (x / y + y) / 2;
		if (y * y == x)
			return (y);
		c++;
	}
	return (y);
}

t_node_list	*ft_min_index(t_stack *lst)
{
	t_node_list	*tmp;
	t_node_list	*min_node;
	int			nodes;

	tmp = lst -> head;
	min_node = lst ->head;
	nodes = 0;
	while (nodes < lst -> size)
	{
		if (tmp -> index < min_node -> index)
			min_node = tmp;
		tmp = tmp -> next;
		nodes++;
	}
	return (min_node);
}
