/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:51:52 by patperez          #+#    #+#             */
/*   Updated: 2026/07/17 10:37:55 by ugarcia-         ###   ########.fr       */
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

/*
	1. Declare 'temp' to store the maximum integer content found.
	2. Declare a pointer 'temp_list' to iterate through stack A nodes.
	3. Set 'temp_list' to the head node of stack A to begin processing.
	4. Initialize 'temp' with the content of the first node.
	5.Loop through the stack nodes using stack size to avoid infinite circ loops.
	6. If the current node content is greater than the saved 'temp', update it.
	7. Store the higher content value into the 'temp' variable.
	8. Move 'temp_list' forward to the next node in the circular list.
	9. Return the maximum integer value found in the stack.
*/
/* 
int	ft_max_number(t_stack *lst_a)
{
	int			temp;
	t_node_list	*temp_list;

	temp_list = lst_a -> head;
	temp = lst_a -> head -> content;
	while (temp_list -> next != NULL)
	{
		if (temp > temp_list -> next -> content)
		{
			temp = temp_list -> content;
		}
		temp_list = temp_list -> next;
	}
	return (temp);
} */

/*
	1. Declare 'temp' to store the minimum integer content found.
	2. Declare a pointer 'temp_list' to iterate through stack A nodes.
	3. Set 'temp_list' to the head node of stack A to begin processing.
	4. Initialize 'temp' with the content of the first node.
	5.Loop through the stack nodes using stack size to avoid infinite circ loops.
	6. If the current node content is lower than the saved 'temp', update it.
	7. Store the lower content value into the 'temp' variable.
	8. Move 'temp_list' forward to the next node in the circular list.
	9. Return the minimum integer value found in the stack.
*/

int	ft_min_number(t_stack *lst_a)
{
	int			temp;
	t_node_list	*temp_list;

	temp_list = lst_a -> head;
	temp = lst_a -> head -> content;
	while (temp_list -> next != NULL)
	{
		if (temp > temp_list -> content)
		{
			temp = temp_list -> content;
		}
		temp_list = temp_list -> next;
	}
	return (temp);
}