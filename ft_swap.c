/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:57:52 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/24 07:47:51 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

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
	bench -> con += 1;
	//write(1, "sa\n", 3);
}

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
	bench -> con += 1;
	//write(1, "sb\n", 3);
}

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
		bench -> con += 1;
		//write(1, "ss\n", 3);
	}
}
