/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:51:52 by patperez          #+#    #+#             */
/*   Updated: 2026/07/09 09:13:41 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declare 'buffer' to save the next node pointer before freeing current one
	2. Declare 'tmp' to iterate through the stack nodes.
	3. Initialize 'buffer' to NULL as a defensive programming mechanism.
	4. Security check: if the stack pointer does not exist, exit the function.
	5. Point 'tmp' to the first node (head) of the stack to begin the loop.
	6. Loop through the stack until all nodes are processed based on stack size.
	7. Save the next node's address into 'buffer' to prevent memory loss.
	8. Free the memory allocated for the current node pointed by 'tmp'.
	9. Move 'tmp' to the next node saved in the buffer.
	10.Decrement the stack size counter for every node that is successfully freed
	11. Once the loop ends, set the stack's head pointer to NULL.
	12. Set the stack's tail pointer to NULL.
	13. Ensure the stack size counter is explicitly set to 0.
	14. Free the memory allocated for the main stack control structure.
*/

void	ft_lstclear(t_stack *lst)
{
	t_node_list	*buffer;
	t_node_list	*tmp;

	buffer = NULL;
	if (!lst)
		return ;
	tmp = lst -> head;
	while (lst->size)
	{
		buffer = tmp-> next;
		free(tmp);
		tmp = buffer;
		lst->size -= 1;
	}
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
	free(lst);
}

/*
	1. Declare an integer variable 'i' to act as the node counter.
	2. Initialize the node counter 'i' to 0.
	3. Loop through the nodes as long as the current node pointer is not NULL.
	4. Move the 'lst' pointer to the next node in the linked list.
	5. Increment the node counter 'i' by 1 for each iteration.
	6. Return the total count of nodes found in the list.
*/

int	ft_lstsize(t_node_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
/* 
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
 */