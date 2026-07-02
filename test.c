
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

void	ft_ra(t_stack *lst_a)
{
	t_node_list *tmp_first;

	if (!lst_a)
		return ;
// 1. Guardas de seguridad: comprobar que la lista exista y tenga al menos dos nodos
	if (lst_a == NULL || lst_a == NULL || lst_a -> head-> next == NULL)
		return ;
// 2. Guardar el nodo que actualmente está al principio en una variable temporal
	tmp_first = lst_a -> head;
// 3. Mover la cabeza de la lista al segundo nodo (el segundo pasa a ser el primero)
	lst_a -> head = lst_a-> head -> next;
// 4. Conectar el antiguo primer nodo al final de la lista (después del actual tail)
	lst_a -> tail -> next = tmp_first;
// 5. Actualizar el puntero tail para que apunte al nuevo último nodo
	lst_a -> tail = tmp_first;
}

/* take first element atop a and put it atop b. nothing done if a empty */
void	ft_pb(t_stack *lst_b, t_stack *lst_a)
{
	t_node_list	*tmp;

	if (!lst_b || !lst_a || !lst_a->head)
		return ;
	tmp = lst_a->head;
	lst_a -> head = lst_a ->head ->next;
	if (lst_a -> size == 1)
	{
		lst_a->head = NULL;
		lst_a->tail = NULL;
	}
	else
	{
		lst_a->head->prev = lst_a->tail;
		lst_a->tail->next = lst_a->head;
	}
	lst_a -> size -= 1;
	tmp->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(lst_b, tmp);
}

int	ft_max_index(t_stack *lst_b)
{
	t_node_list	*tmp;
	int			max;
	int			nodes;

	tmp = lst_b -> head;
	max = lst_b ->head -> index;
	nodes = 0;
	while (nodes < lst_b -> size)
	{
		if (tmp -> index > max)
			max = tmp -> index;
		tmp = tmp -> next;
		nodes++;
	}
	return (max);
}

int	ft_exist_bucket(t_stack *lst_a, int number_limit)
{
	t_node_list	*tmp;
	int			nodes;

	tmp = lst_a -> head;
	nodes = 0;
	while (nodes < lst_a -> size)
	{
		if (tmp -> index < number_limit)
		{
			return (1);
		}
		tmp = tmp -> next;
		nodes++;
	}
	return (0);
}

void	ft_get_index(t_stack *lst_a)
{
	int			index_count;
	t_node_list	*current;
	t_node_list	*current_aux;
	int			i;
	int			j;

	current = lst_a -> head;
	i = 0;
	while (i < lst_a->size)
	{
		index_count = 0;
		current_aux = lst_a->head;
		j = 0;
		while (j < lst_a->size)
		{
			if (current_aux -> content < current -> content)
			{
				index_count += 1;
			}
			current_aux = current_aux -> next;
			j++;
		}
		current -> index = index_count;
		current = current ->next;
		i++;
	}
}

void	ft_bucket(t_stack *lst_a, t_stack *lst_b)
{
	int	number_limit;
	int	exist_bucket;

	if (lst_a == NULL || lst_a -> head == NULL || lst_a -> size <= 1)
		return ;
	number_limit = sqroot(lst_a -> size);
	printf("number limit %i\n", number_limit);
	while (lst_a -> size)
	{
		if (lst_a -> head -> index < number_limit)
		{
			ft_pb(lst_b, lst_a);
			printf("push %i\n", lst_b -> head-> content);
		}
		else
		{
			exist_bucket = ft_exist_bucket(lst_a, number_limit);
			if (exist_bucket)
			{
				ft_ra(lst_a);
			}
			else
			{
				number_limit += number_limit;
				printf("nmber limit %i\n", number_limit);
			}
		}
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
			"  next       : %p\n"
			"  index      : %d\n\n",
			counter,
			(void *)lst_tmp,
			lst_tmp->content,
			(void *)lst_tmp->prev,
			(void *)lst_tmp->next,
			lst_tmp->index
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
	ft_get_index(lst_a);
	printf("---------------STACK A-----------\n");
	ft_print_list(lst_a, lst_a -> size);

	ft_bucket(lst_a, lst_b);

	printf("---------------sorted B--------------- \n");
	ft_print_list(lst_b, lst_b -> size);
	printf("---------------%d lista tamaño A-----------\n", lst_a-> size);

	printf("---------------resultado A-----------\n");
	ft_print_list(lst_a, lst_a -> size);

	ft_lstclear(lst_a);
	return (0);
}
