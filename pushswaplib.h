/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaplib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:24:41 by patperez          #+#    #+#             */
/*   Updated: 2026/06/26 09:41:58 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAPLIB_H
# define PUSHSWAPLIB_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct list
{
	int				content;
	struct list		*prev;
	struct list		*next;
}					t_node_list;

typedef struct stack
{
	int				size;
	struct node		*head;
	struct node		*tail;
}					t_stack;

/* OPERATIONS */
void		ft_sa(t_node_list **lst_a);
void		ft_sb(t_node_list **lst_b);
void		ft_ss(t_node_list **lst_a, t_node_list **lst_b);
void		ft_pa(t_node_list **lst_a, t_node_list **lst_b);
void		ft_pb(t_node_list **lst_b, t_node_list **lst_a);
void		ft_ra(t_node_list **lst);
void		ft_rb(t_node_list **lst);
void		ft_rr(t_node_list **lst_a, t_node_list **lst_b);
void		ft_rra(t_node_list **lst_a);
void		ft_rrb(t_node_list **lst_b);
void		ft_rrr(t_node_list **lst_a, t_node_list **lst_b);

/* UTILS */
t_node_list	*ft_lstlast(t_node_list *lst);
t_node_list	*ft_lstnew(int content);
void		ft_lstadd_back(t_node_list **lst, t_node_list *new_node);
void		ft_lstadd_front(t_node_list **lst, t_node_list *new_node);
t_node_list	*ft_lstfind(t_node_list **lst);
void		ft_lstclear(t_node_list **lst);
int			ft_lstsize(t_node_list *lst);

/* ALGORITHMS */
void		bubble_sort(t_node_list **lst);

#endif