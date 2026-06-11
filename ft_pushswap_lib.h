/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_lib.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:24:41 by patperez          #+#    #+#             */
/*   Updated: 2026/06/11 10:34:01 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAPLIB_H
# define PUSHSWAPLIB_H
# include <unistd.h>
# include <stdlib.h>

/*
typedef struct	s_list
{
	void	*content;
	struct	s_list *next;
} t_list;
*/

typedef struct	node
{
	struct	node *next;
	void	*content;
} node_list;
node_list	*ft_lstnew(void *content);
node_list	*ft_lstlast(node_list *stack);
void	ft_lstadd_back(node_list **stack, node_list *new_node);
void	ft_lstadd_front(node_list **stack, node_list *new_node);

#endif

