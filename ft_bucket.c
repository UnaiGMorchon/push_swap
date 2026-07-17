/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/07/17 09:51:11 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declare 'tmp' to iterate through the nodes of stack B.
	2. Declare 'max_node' to store the node pointer with the highest index.
	3. Declare 'nodes' as a loop counter to track processed elements.
	4. Initialize 'tmp' and 'max_node' to point to the head of stack B.
	5. Initialize the loop counter 'nodes' to 0.
	6.Loop through stack B exactly as many times as its size avoid infinite loops
	7.Compare the index of the current node 'tmp' with the current maximum index
	8. If the current node's index is greater, update 'max_node' to point to it.
	9. Move the 'tmp' pointer forward to the next node in the circular list.
	10. Increment the 'nodes' counter by 1.
	11. Return the pointer to the node that contains the maximum index.
*/

t_node_list	*ft_max_index(t_stack *lst_b)
{
	t_node_list	*tmp;
	t_node_list	*max_node;
	int			nodes;

	tmp = lst_b -> head;
	max_node = lst_b ->head;
	nodes = 0;
	while (nodes < lst_b -> size)
	{
		if (tmp -> index > max_node -> index)
			max_node = tmp;
		tmp = tmp -> next;
		nodes++;
	}
	return (max_node);
}

/*
	1. Declare 'tmp' to find the physical index of the target node.
	2. Declare 'tmp_max_index' to hold the address of the node with the max index
	3. Declare 'physical_node_position' to count its distance from the head.
	4. Find and save the address of the node with the highest index in stack B.
	5. Keep looping until the node with the maximum index reaches the top (head).
	6.Reset the position tracker variable to 0 at each rotation calculation step
	7. Set 'tmp' to the head node to start measuring distance.
	8.Run an inner loop to count steps from the head until reaching target node
	9. Move 'tmp' forward to the next node.
	10. Increment the position tracker counter by 1.
	11.Check if the target node is closer to the top via the upper half of stack
	12. Call ft_rb to rotate up since the node is in the first half of the stack.
	13. Call ft_rrb to reverse rotate down since the node is in the second half.
*/

void	ft_rotate_decide(t_stack *lst_b, t_bench *bench)
{
	t_node_list	*tmp;
	t_node_list	*tmp_max_index;
	int			physical_node_position;

	tmp_max_index = ft_max_index(lst_b);
	while (lst_b -> head != tmp_max_index)
	{
		physical_node_position = 0;
		tmp = lst_b -> head;
		while (tmp != tmp_max_index)
		{
			tmp = tmp -> next;
			physical_node_position++;
		}
		if (physical_node_position <= lst_b -> size / 2)
		{
			ft_rb(lst_b, bench);
		}
		else
		{
			ft_rrb(lst_b, bench);
		}
	}
}

/*
	1. Declare 'tmp' to iterate through the nodes of stack A.
	2. Declare 'nodes' as a loop counter to prevent infinite circular iterations.
	3. Point 'tmp' to the head node of stack A to start scanning.
	4. Initialize the loop iteration counter to 0.
	5. Loop through the stack nodes based on its total size.
	6.Check if the current node's index is lower than the specified bucket limit
	7.Return 1 immediately if a matching node is found inside the current bucket
	8. Move 'tmp' forward to the next node in the circular list.
	9. Increment the 'nodes' tracker counter by 1.
	10. Return 0 if the loop finishes and no node matches the bucket constraint.
*/

int	ft_exist_bucket(t_stack *lst_a, int number_limit)
{
	t_node_list	*tmp;
	int			nodes;

	tmp = lst_a -> head;
	nodes = 0;
	while (nodes < lst_a -> size)
	{
		if (tmp -> index < number_limit)
		{
			return (1);
		}
		tmp = tmp -> next;
		nodes++;
	}
	return (0);
}

/*
	1.Declare 'index_count' to track how many values are smaller than current one
	2. Declare 'current' pointer to select the node being evaluated.
	3.Declare 'current_aux' pointer to compare all other nodes against 'current'.
	4. Declare 'i' as the main loop iteration counter.
	5. Declare 'j' as the secondary loop iteration counter.
	6. Set 'current' to the head node to start calculating indices.
	7. Initialize 'i' counter to 0.
	8. Loop through all nodes using 'i' to assign indices to every element.
	9.Reset the smaller elements tracker 'index_count' to 0 for the current node.
	10. Point the secondary iterator 'current_aux' back to the head of stack A.
	11. Reset the secondary iteration counter 'j' to 0.
	12.Compare 'current' with every single node in stack using a secondary loop
	13.If 'current_aux'holds a smaller value than 'current',increment index_count
	14. Add 1 to the relative index position value.
	15. Move 'current_aux' forward to compare the next node in the list.
	16.Save the final calculated relative ranking position into the node's index.
	17. Move 'current' forward to process the next node in stack A.
*/

void	ft_get_index(t_stack *lst_a)
{
	int			index_count;
	t_node_list	*current;
	t_node_list	*current_aux;
	int			i;
	int			j;

	current = lst_a -> head;
	i = 0;
	while (i++ < lst_a->size)
	{
		index_count = 0;
		current_aux = lst_a->head;
		j = 0;
		while (j++ < lst_a->size)
		{
			if (current_aux -> content < current -> content)
			{
				index_count += 1;
			}
			current_aux = current_aux -> next;
		}
		current -> index = index_count;
		current = current ->next;
	}
}

/*
	1.Declare 'number_limit' to define upper index threshold of current bucket
	2.Declare 'end_bucket' to save the fixed size increment step for the buckets
	3. Security check: if stack A does not exist, is empty, or has 1 node, stop.
	4. Calculate the base bucket partition size using the sqroot helper function.
	5.Save the partition size step into 'end_bucket'for future threshold upgrades
	6. Loop until all nodes from stack A are emptied and pushed to stack B.
	7.If the top element of A fits in the current bucket,push it immediately to B
	8. Else if another node in A fits the bucket, rotate A to find it.
	9. Else increase the limit to open up the next bucket range of numbers.
	10.Loop until stack B becomes completely empty to restore elements back to A
	11. Find the maximum element in B and rotate it to the top position.
	12. Push the sorted element back to the top of stack A.
*/

void	ft_bucket(t_stack *lst_a, t_bench *bench)
{
	int		number_limit;
	int		end_bucket;
	t_stack	*lst_b;

	lst_b = ft_newstack();
	ft_get_index(lst_a);
	number_limit = ft_sqroot(lst_a -> size);
	end_bucket = number_limit;
	while (lst_a -> size)
	{
		if (lst_a -> head -> index < number_limit)
			ft_pb(lst_b, lst_a, bench);
		else if (ft_exist_bucket(lst_a, number_limit))
			ft_ra(lst_a, bench);
		else
			number_limit += end_bucket;
	}
	while (lst_b -> size)
	{
		ft_rotate_decide(lst_b, bench);
		ft_pa(lst_a, lst_b, bench);
	}
	ft_lstclear(lst_b);
	ft_lstclear(lst_a);
}