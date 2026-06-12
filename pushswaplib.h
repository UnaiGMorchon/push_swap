/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaplib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:24:41 by patperez          #+#    #+#             */
/*   Updated: 2026/06/12 09:05:52 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAPLIB_H
# define PUSHSWAPLIB_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct node
{
	struct node	*next;
	int			content;
}			t_node_list;

t_node_list	*ft_lstnew(int content);
t_node_list	*ft_lstlast(t_node_list *lst);
void		ft_lstadd_back(t_node_list **lst, t_node_list *new_node);
void		ft_lstadd_front(t_node_list **lst, t_node_list *new_node);

#endif
