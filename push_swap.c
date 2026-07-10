/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/10 13:24:57 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	push_swap(int argc, char **argv)
{
	char	**args;
	t_stack	*aux;
	int		count;
	t_node_list	*tmp;

	args = NULL;
	if (argc < 2)
		return (0);
	args = new_args(argc, argv, args);
	if ((ft_is_validint(args)) == 0 || (ft_isrepeat(args)) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	aux = input_conversion(args);
	count = 0;
	tmp = aux ->head;
	while (count < aux->size)
	{
		//printf("%d\n", tmp->content);
		tmp = tmp->next;
		count++;
	}
	// calcular desorden
	// parseo flags bench
	return (1);
}
