/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_adaptive_algo.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:09:11 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:35:00 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declare a pointer 'bench' to hold the structure for tracking metrics/operations.
	2. Allocate memory dynamically for the 't_bench' structure using malloc.
	3. Initialize the disorder metric float field to 0.0.
	4. Set the initial strategy name pointer to NULL.
	5. Set the total operations counter to 0.
	6. Reset all individual operation counters (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr) to 0.
	7. Return the pointer to the newly allocated and initialized bench structure.
*/

t_bench	*ft_initialise_bench(void)
{
	t_bench	*bench;

	bench = malloc(sizeof(t_bench));
	bench -> disorder = 0.0;
	bench -> strategy = NULL;
	bench -> total = 0;
	bench -> sa = 0;
	bench -> sb = 0;
	bench -> ss = 0;
	bench -> pa = 0;
	bench -> pb = 0;
	bench -> ra = 0;
	bench -> rb = 0;
	bench -> rr = 0;
	bench -> rra = 0;
	bench -> rrb = 0;
	bench -> rrr = 0;
	return (bench);
}

/*
	1. Declare a pointer 'flag_bench' to hold the wrapper structure for flags and metrics.
	2. Allocate memory dynamically for the 't_isflag' structure using malloc.
	3. Initialize the 'flag' pointer field to NULL.
	4. Initialize the 'bench' pointer field to NULL.
	5. Return the pointer to the newly allocated flag/bench structure.
*/

t_isflag	*ft_initialise_flag_bench(void)
{
	t_isflag	*flag_bench;

	flag_bench = malloc(sizeof(t_isflag));
	flag_bench -> flag = NULL;
	flag_bench -> bench = NULL;
	return (flag_bench);
}
/*
	1. Declare a temporary pointer 'tmp' to traverse nodes ahead of the current head.
	2. Declare 'mistakes' as a float to count pair inversions (out-of-order elements).
	3. Declare 'total_pairs' as a float to count total unique pairs compared.
	4. Declare loop counters 'i' and 'j' for nested iteration over the stack.
	5. Initialize mistake and total pair counters to 0.00f.
	6. Run an outer loop 'i' to evaluate each element as the primary element for comparison.
	7. Set 'tmp' to point to the node immediately following the current head node.
	8. Run an inner loop 'j' to compare the head node against all remaining nodes after it.
	9. Increment the 'total_pairs' count for every pair evaluated.
	10. Check if current head value is greater than 'tmp' value; if true, increment 'mistakes'.
	11. Move 'tmp' to the next node in the list for the inner comparison loop.
	12. Shift 'head' to the next node to advance the primary comparison point.
	13. Restore/advance the head reference after finishing the loops to keep list state.
	14. Return the disorder ratio by dividing total mistakes by total pair comparisons.
*/

float	ft_disorder_metric(t_stack *lst)
{
	t_node_list	*tmp;
	float		mistakes;
	float		total_pairs;
	int			i;
	int			j;

	mistakes = 0.00f;
	total_pairs = 0.00f;
	i = 0;
	while (i < lst -> size - 1)
	{
		tmp = lst -> head -> next;
		j = i + 1;
		while (j++ < lst -> size)
		{
			total_pairs += 1;
			if (lst -> head -> content > tmp -> content)
				mistakes += 1;
			tmp = tmp -> next;
		}
		lst -> head = lst -> head -> next;
		i++;
	}
	lst -> head = lst -> head -> next;
	return (mistakes / total_pairs);
}

/*
	1. Check if the stack size is 5 or smaller.
	2. Set strategy string to "Adaptive / O(n2)", index elements, and call 'ft_shortlist_sort'.
	3. Else, check if the calculated disorder metric is low (less than 0.2).
	4. Set strategy string to "Adaptive / O(n2)" and call 'ft_bubble_sort' for nearly sorted data.
	5. Else, check if disorder is moderate (between 0.2 inclusive and 0.5 exclusive).
	6. Set strategy string to "Adaptive / O(n√n)" and call 'ft_bucket' algorithm.
	7. Else, if disorder is high (greater than or equal to 0.5).
	8. Set strategy string to "Adaptive / O(n log n)", index elements, and call 'ft_radix'.
*/

void	ft_adaptive_algo(t_stack *lst, t_bench *bench)
{
	if (lst -> size <= 5)
	{
		bench -> strategy = "Adaptive / O(n2)";
		ft_get_index(lst);
		ft_shortlist_sort(lst, bench);
	}
	else if (bench -> disorder < 0.2)
	{
		bench -> strategy = "Adaptive / O(n2)";
		ft_bubble_sort(lst, bench);
	}
	else if (bench -> disorder >= 0.2 && bench -> disorder < 0.5)
	{
		bench -> strategy = "Adaptive / O(n√n)";
		ft_bucket(lst, bench);
	}
	else if (bench -> disorder >= 0.5)
	{
		bench -> strategy = "Adaptive / O(n log n)";
		ft_get_index(lst);
		ft_radix(lst, bench);
	}
}
