/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_adaptive_algo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:09:11 by patperez          #+#    #+#             */
/*   Updated: 2026/07/09 09:44:14 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

float	disorder_metric(t_stack *lst)
{
	t_node_list	*tmp;
	float	mistakes;
	float	total_pairs;
	int		i;
	int 	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	if (lst == NULL || lst -> head == NULL)
		return (0);
	while (i < lst -> size - 1)
	{
		tmp = lst -> head -> next;
		j = i + 1;
		while (j < lst -> size - 1)
		{
			total_pairs++;
			if (lst -> head -> content > lst -> head -> next -> content)
				mistakes++;
			tmp = tmp -> next;
			j++;
		}
		lst -> head = lst -> head -> next;
		i++;
	}
	return (mistakes / total_pairs);
}

/*void	adaptive_algo(t_stack *lst)
{
	float	disorder;

	if (lst == NULL || lst -> head == NULL)
		return ;
	disorder = disorder_metric(lst);
	if (disorder < 0.2)
		call bubble
	else if (disorder >= 0.2 && disorder < 0.5)
		call bucket
	else if (disorder >= 0.5)
		call radix
	else if (disorder == 0)
		show nothing ?? empty bench ??
	if (bench selected)
		output benchmark info
}*/

#include <stdio.h>
int	main (void)
{
	t_stack	*lst_a;

	lst_a = ft_newstack();
	// STACK_A
	ft_lstadd_back(lst_a, ft_lstnew(12));
	ft_lstadd_back(lst_a, ft_lstnew(15));
	ft_lstadd_back(lst_a, ft_lstnew(1));
	ft_lstadd_back(lst_a, ft_lstnew(2));
	ft_lstadd_back(lst_a, ft_lstnew(16));
	ft_lstadd_back(lst_a, ft_lstnew(567));
	ft_lstadd_back(lst_a, ft_lstnew(13));
	ft_lstadd_back(lst_a, ft_lstnew(9));
	
	printf("Disorder: %f", disorder_metric(lst_a));
	return (0);
}
