/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaplib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:24:41 by patperez          #+#    #+#             */
/*   Updated: 2026/06/12 15:04:07 by patperez         ###   ########.fr       */
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
	int				content;
	struct node		*next;
}					t_node_list;

void		ft_sa(t_node_list **lst_a);
void		ft_sb(t_node_list **lst_b);
void		ft_ss(t_node_list **lst_a, t_node_list **lst_b);
void	ft_pa(t_node_list **lst_a, t_node_list **lst_b);
void    ft_pb(t_node_list **lst_b, t_node_list **lst_a);
void    ft_reva(t_node_list **lst_a);
t_node_list	*ft_lstlast(t_node_list *lst);
t_node_list	*ft_lstnew(int content);
t_node_list	*ft_lstlast(t_node_list *lst);
void		ft_lstadd_back(t_node_list **lst, t_node_list *new_node);
void		ft_lstadd_front(t_node_list **lst, t_node_list *new_node);
t_node_list	*ft_lstfind(t_node_list **lst);

#endif
