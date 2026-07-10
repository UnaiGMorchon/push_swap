/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaplib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:24:41 by patperez          #+#    #+#             */
/*   Updated: 2026/07/10 15:31:26 by patperez         ###   ########.fr       */
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

typedef struct s_bench
{
	float	disorder;
	char	strategy;
	int		total;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}					t_bench;

/* OPERATIONS */
void		ft_sa(t_stack *lst_a, t_bench *bench);
void		ft_sb(t_stack *lst_b, t_bench *bench);
void		ft_ss(t_stack*lst_a, t_stack *lst_b, t_bench *bench);
void		ft_pa(t_stack *lst_a, t_stack *lst_b, t_bench *bench);
void		ft_pb(t_stack *lst_b, t_stack *lst_a, t_bench *bench);
void		ft_ra(t_stack *lst_a, t_bench *bench);
void		ft_rb(t_stack *lst_b, t_bench *bench);
void		ft_rr(t_stack *lst_a, t_stack *lst_b, t_bench *bench);
void		ft_rra(t_stack *lst_a, t_bench *bench);
void		ft_rrb(t_stack *lst_b, t_bench *bench);
void		ft_rrr(t_stack *lst_a, t_stack *lst_b, t_bench *bench);

/* PROGRAM */
int	push_swap(int argc, char **argv);

/* UTILS */
t_node_list	*ft_lstnew(int content);
t_stack		*ft_newstack(void);
void		ft_lstadd_front(t_stack *stack, t_node_list *new_node);
void		ft_lstadd_back(t_stack *stack, t_node_list *new_node);
void		ft_lstclear(t_stack *lst);
int			ft_lstsize(t_node_list *lst);
void		ft_get_index(t_stack *lst_a);
double		ft_sqroot(int x);
long int	ft_is_validint(char **args);
int			ft_isrepeat(char **args);
t_stack		*input_conversion(char **args);
char		*ft_strdup(char *src);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
int			ft_isdigit(int c);
char		*ft_strjoin(char const *s1, char const *s2);
long int	ft_atol(const char *nptr);
char		**new_args(int argc, char **argv, char **args);
t_stack	*ft_valid_and_convert(char **args);
void	ft_flag_search_parsing(char **args, t_bench *bench);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* ALGORITHMS */
void		ft_bubble_sort(t_stack *lst, t_bench *bench);
void		ft_bucket(t_stack *lst_a, t_bench *bench);
void		ft_radix(t_stack **lst_a, t_stack **lst_b, t_bench *bench);
float		disorder_metric(t_stack *lst);
t_bench		*initialise_bench();


#endif
