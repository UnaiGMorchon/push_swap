/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaplib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:24:41 by patperez          #+#    #+#             */
/*   Updated: 2026/07/23 13:09:59 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAPLIB_H
# define PUSHSWAPLIB_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "./libft/libft.h"

typedef struct s_alist
{
	int					content;
	int					index;
	struct s_alist		*prev;
	struct s_alist		*next;
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
	char	*strategy;
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

typedef struct s_isflag
{
	char	*flag;
	char	*bench;
}					t_isflag;

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

int			push_swap(int argc, char **argv);

t_node_list	*ft_newnode(int content);
t_stack		*ft_newstack(void);
void		ft_stackadd_front(t_stack *stack, t_node_list *new_node);
void		ft_stackadd_back(t_stack *stack, t_node_list *new_node);
void		ft_clearstack(t_stack *lst);
void		ft_get_index(t_stack *lst_a);
double		ft_sqroot(int x);
long int	ft_is_validint(char **args);
int			ft_isrepeat(char **args);
t_stack		*ft_input_conversion(char **args, t_bench *bench,
				t_isflag *flag_bench);
long int	ft_atol(const char *nptr);
char		**ft_new_args(int argc, char **argv, int *i);
t_stack		*ft_valid_and_convert(char **args,
				t_bench *bench, t_isflag *flag_bench);
void		ft_flag_search_parsing(char **args,
				t_isflag *flag_bench, t_bench *bench);
void		ft_separate_flags(char **argv, t_isflag *flag_bench,
				int *i, t_bench *bench);
char		ft_print_bench(t_bench *bench);
void		ft_free_split(char **split);
int			ft_args_count(int *i, int argc);
void		ft_free_if_null(t_bench *bench, t_isflag *flag_bench);

void		ft_bubble_sort(t_stack *lst, t_bench *bench);
void		ft_bucket(t_stack *lst_a, t_bench *bench);
void		ft_radix(t_stack *lst_a, t_bench *bench);
void		ft_adaptive_algo(t_stack *lst, t_bench *bench);
void		ft_shortlist_sort(t_stack *lst, t_bench *bench);
float		ft_disorder_metric(t_stack *lst);
t_bench		*ft_initialise_bench(void);
t_isflag	*ft_initialise_flag_bench(void);

#endif