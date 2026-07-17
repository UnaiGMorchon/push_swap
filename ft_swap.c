/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:57:52 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/17 15:58:46 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declare 'temp' to hold the integer content during the swap.
	2. Declare 'temp_index' to hold the node's index during the swap.
	3. Security check: if stack A does not exist or has less than 2 nodes, stop.
	4. Save the content of the first node (head) into the 'temp' variable.
	5. Save the index of the first node (head) into the 'temp_index' variable.
	6. Copy the content of the second node into the first node.
	7. Copy the index of the second node into the first node.
	8. Move the original first node's content from 'temp' into the second node.
	9. Move the original first node's index from 'temp_index' into second node.
	10. Write the operation string "sa\n" to the standard output.
*/

void	ft_sa(t_stack *lst_a, t_bench *bench)
{
	int	temp;
	int	temp_index;

	if (lst_a == NULL || lst_a-> size < 2)
		return ;
	temp = lst_a-> head-> content;
	temp_index = lst_a-> head-> index;
	lst_a -> head -> content = lst_a -> head-> next -> content;
	lst_a -> head -> index = lst_a -> head-> next -> index;
	lst_a-> head -> next-> content = temp;
	lst_a-> head -> next-> index = temp_index;
	bench -> sa += 1;
	bench -> total += 1;
	write(1, "sa\n", 3);
}

/*
	1. Declare 'temp' to hold the integer content during the swap.
	2. Declare 'temp_index' to hold the node's index during the swap.
	3. Security check: if stack B does not exist or has less than 2 nodes, stop.
	4. Save the content of the first node (head) into the 'temp' variable.
	5. Save the index of the first node (head) into the 'temp_index' variable.
	6. Copy the content of the second node into the first node.
	7. Copy the index of the second node into the first node.
	8. Move the original first node's content from 'temp' into the second node.
	9. Move the original first node's index from 'temp_index' into second node
	10. Write the operation string "sb\n" to the standard output.
*/

void	ft_sb(t_stack *lst_b, t_bench *bench)
{
	int	temp;
	int	temp_index;

	if (lst_b == NULL || lst_b -> size < 2)
		return ;
	temp = lst_b-> head -> content;
	temp_index = lst_b-> head-> index;
	lst_b ->head-> content = lst_b ->head -> next-> content;
	lst_b -> head -> index = lst_b -> head-> next -> index;
	lst_b->head->next->content = temp;
	lst_b-> head -> next-> index = temp_index;
	bench -> sb += 1;
	bench -> total += 1;
	write(1, "sb\n", 3);
}

/*
	1. Security check: verify both stacks exist and both have at least 2 nodes.
	2. Call ft_sa to swap the top two elements of stack A.
	3. Call ft_sb to swap the top two elements of stack B.
	4. Write the combined operation string "ss\n" to the standard output.
*/

void	ft_ss(t_stack *lst_a, t_stack *lst_b, t_bench *bench)
{
	if (!lst_a || lst_a->size < 2 || !lst_b || lst_b->size < 2)
	{
		ft_sa(lst_a, bench);
		ft_sb(lst_b, bench);
		bench -> ss += 1;
		bench -> sa -= 1;
		bench -> sb -= 1;
		bench -> total -= 1;
		write(1, "ss\n", 3);
	}
}

