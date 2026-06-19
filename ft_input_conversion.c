/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:58:07 by patperez          #+#    #+#             */
/*   Updated: 2026/06/19 10:03:35 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	input_conversion(input array)
{
	int	i;
	t_node_list	lst;

	i = 0;
	while (input array)
	{
		ft_lstadd_back(lst, input array[i]);
		i++;
	}
}
