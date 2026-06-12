/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaplib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:59:53 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/06/12 09:00:26 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAPLIB_H
# define PUSHSWAPLIB_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct node
{
	int				content;
	struct node		*next;
}					t_node_list;

void		ft_sa(t_node_list **lst_a);
void		ft_sb(t_node_list **lst_b);
void		ft_ss(t_node_list **lst_a, t_node_list **lst_b);
t_node_list	*ft_lstlast(t_node_list *lst);

#endif
