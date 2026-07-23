/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/07/23 10:35:39 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_bubble_sort(t_stack *lst, t_bench *bench)
{
	int	swapped;
	int	i;

	ft_get_index(lst);
	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < lst -> size - 1)
		{
			if (lst-> head-> index > lst-> head -> next -> index)
			{
				ft_sa(lst, bench);
				swapped = 1;
			}
			ft_ra(lst, bench);
			i ++;
		}
		ft_ra(lst, bench);
	}
	ft_clearstack(lst);
}
