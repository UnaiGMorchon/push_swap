/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:42:04 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/12 09:01:06 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_ss(t_node_list **lst_a, t_node_list **lst_b)
{
	if ((lst_b == NULL || *lst_b == NULL || (*lst_b)->next == NULL)
		&& (lst_a == NULL || *lst_a == NULL || (*lst_a)->next == NULL))
	{
		ft_sa(*lst_a);
		ft_sb(*lst_b);
		write(1, "ss\n", 3);
	}
}
