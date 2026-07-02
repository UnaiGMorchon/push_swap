/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaplib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:24:41 by patperez          #+#    #+#             */
/*   Updated: 2026/07/02 12:31:17 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAPLIB_H
# define PUSHSWAPLIB_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_list
{
	int					content;
	int					index;
	struct s_list		*prev;
	struct s_list		*next;
}					t_node_list;

typedef struct s_stack
{
	int				size;
	t_node_list		*head;
	t_node_list		*tail;
}					t_stack;

/* OPERATIONS */
void		ft_sa(t_stack *lst_a);//
void		ft_sb(t_stack *lst_b);//
void		ft_ss(t_stack*lst_a, t_stack *lst_b);//
void		ft_pa(t_stack *lst_a, t_stack *lst_b);//
void		ft_pb(t_stack *lst_b, t_stack *lst_a);//
void		ft_ra(t_stack *lst_a); //
void		ft_rb(t_stack *lst_b);//
void		ft_rr(t_stack *lst_a, t_stack *lst_b);//
void		ft_rra(t_stack *lst_a);//
void		ft_rrb(t_stack *lst_b);//
void		ft_rrr(t_stack *lst_a, t_stack *lst_b); //

/* UTILS */
t_node_list	*ft_lstnew(int content);
t_stack		*ft_newstack(void);
void		ft_lstadd_front(t_stack *stack, t_node_list *new_node);
void		ft_lstadd_back(t_stack *stack, t_node_list *new_node);
void		ft_lstclear(t_stack *lst);
int			ft_lstsize(t_node_list *lst);
void		ft_get_index(t_stack *lst_a);
double		sqroot(int x);

/* ALGORITHMS */
void		bubble_sort(t_stack *lst);
void		ft_bucket(t_stack *lst_a, t_stack *lst_b);

#endif