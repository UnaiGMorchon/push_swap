
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

/* int	ft_max_number(t_stack *lst_a)
{
	int			temp;
	t_node_list	*temp_list;

	temp_list = lst_a -> head;
	temp = lst_a -> head -> content;
	while (temp_list != NULL)
	{
		if (temp < temp_list -> content)
		{
			temp = temp_list -> content;
		}
		temp_list = temp_list -> next;
	}
	printf("TEMPmax>>>>> %i\n", temp);
	return (temp);

}

int	ft_min_number(t_stack *lst_a)
{
	int			temp;
	t_node_list	*temp_list;

	if (!lst_a || !lst_a -> head)
		return (0);
	temp_list = lst_a -> head;
	temp = lst_a -> head-> content;
	while (temp_list != NULL)
	{
		if (temp > temp_list -> content)
		{
			temp = temp_list -> content;
		}
		temp_list = temp_list -> next;
	}
	printf("TEMPmin>>>>> %i\n", temp);
	return (temp);

} */

void	ft_bucket(t_stack *lst_a, t_stack *lst_b)
{
	int		number_min;
	int		total;
	int		bucket_number;
	int		number_limit;
	int		end_of_bucket;
	int		number_max;

	
	if (lst_a == NULL || lst_a -> head -> next == NULL)
		return ;
	//lst_b = NULL;
	//lst_b =  malloc(sizeof(t_stack));
	//number_min = ft_min_number(lst_a);
	//number_max = ft_max_number(lst_a);
	total = ft_lstsize (lst_a -> head);
	bucket_number = sqroot(total);
	number_limit = (bucket_number + number_min);
	end_of_bucket = lst_a-> tail -> content;

	printf("number limit %i\n", number_limit);
	printf("number %i\n", number_min);
	printf("bucket %i\n", bucket_number);
	while (lst_a-> head != NULL)
	{
		while (lst_a != NULL && lst_a -> head -> content < number_limit)
		{
			ft_pb(lst_b, lst_a);
			printf("push %i\n", lst_b -> head-> content);
		}
		if (lst_a -> head -> content == end_of_bucket)
		{
			number_limit = number_limit + bucket_number;
			printf("nmber limit %i\n", number_limit);
		}
		if (lst_a -> head -> next != NULL)
			ft_ra(lst_a);
	}
	printf("salio \n");

	if (lst_a -> head -> content == number_max)
	{
		printf("last node %i\n", lst_a -> head -> content);
		ft_pb(lst_b, lst_a);
		printf("push %i\n", lst_b -> head -> content);
	}
	/* while ((*lst_b))
		{
			ft_pa();
		} */
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
