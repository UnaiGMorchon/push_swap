
#include "pushswaplib.h"

double	sqroot(int x)
{
	double	y;
	int		p;
	int		square;
	int		c;

	p = 0;
	square = 0;
	c = 0;
	while (x > square)
	{
		p++;
		square = (p + 1) * (p + 1);
	}
	y = (double)p;
	while (c < 10)
	{
		y = (x / y + y) / 2;
		if (y * y == x)
			return (y);
		c++;
	}
	return (y);
}

void	ft_get_index(t_stack *lst_a)
{
	int			index_count;
	t_node_list	*current;
	t_node_list	*current_aux;

	current = lst_a -> head;
	while (current != NULL)
	{
		index_count = 0;
		current_aux = lst_a -> head;
		while (current_aux != NULL)
		{
			if (current_aux -> content < current -> content)
			{
				index_count += 1;
			}
			current_aux = current_aux -> next;
		}
		current -> index = index_count;
		current = current ->next;
	}
}

void	ft_bucket(t_stack *lst_a, t_stack *lst_b)
{
	int	total;
	int	bucket_number;
	int	number_limit;
	int	count;

	if (lst_a == NULL || lst_a -> head -> next == NULL)
		return ;
	//lst_b = NULL;
	//lst_b =  malloc(sizeof(t_stack));
	total = ft_lstsize (lst_a -> head);
	bucket_number = sqroot(total);
	number_limit = bucket_number;

	printf("number limit %i\n", number_limit);
	printf("bucket %i\n", bucket_number);
	count = 0;
	while (lst_a-> head != NULL)
	{
		while (lst_a -> head != NULL && lst_a -> head -> index < number_limit)
		{
			ft_pb(lst_b, lst_a);
			printf("push %i\n", lst_b -> head-> content);
			count += 1;
		}
		if (count == ft_lstsize(lst_a -> head))
		{
			number_limit = number_limit + bucket_number;
			printf("nmber limit %i\n", number_limit);
		}
		if (lst_a -> head -> next != NULL)
			ft_ra(lst_a);
	}
	printf("salio \n");
}

static void	ft_print_list(t_stack *stack, int size)
{
	int			counter;
	t_node_list	*lst_tmp;

	counter = 0;
	lst_tmp = stack->head;

	while (counter < size)
	{
		printf(
			"Node %d\n"
			"  addr       : %p\n"
			"  content    : %d\n"
			"  prev       : %p\n"
			"  next       : %p\n\n",
			counter,
			(void *)lst_tmp,
			lst_tmp->content,
			(void *)lst_tmp->prev,
			(void *)lst_tmp->next
			);
		lst_tmp = lst_tmp->next;
		counter++;
	}
}

int	main(void)
{
	t_stack	*lst_a;
	t_stack	*lst_b;

	lst_a = ft_newstack();
	lst_b = ft_newstack();
	// STACK_A
	ft_lstadd_back(lst_a, ft_lstnew(12));
	ft_lstadd_back(lst_a, ft_lstnew(15));
	ft_lstadd_back(lst_a, ft_lstnew(1));
	ft_lstadd_back(lst_a, ft_lstnew(13));
	ft_lstadd_back(lst_a, ft_lstnew(16));
	ft_lstadd_back(lst_a, ft_lstnew(18));
	ft_lstadd_back(lst_a, ft_lstnew(2));
	ft_lstadd_back(lst_a, ft_lstnew(9));
	// STACK_B
	printf("---------------STACK A-----------\n");
	ft_print_list(lst_a, lst_a -> size);

	ft_bucket(lst_a, lst_b);

	printf("---------------sorted B--------------- \n");
	ft_print_list(lst_b, lst_b -> size);
	printf("---------------%d lista tamaño A-----------\n", lst_a-> size);
	ft_lstclear(lst_a);
	return (0);
}
