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


int	ft_max_number(t_node_list **lst_a)
{
	int	temp;
	t_node_list	*temp_list;

	temp_list = *lst_a;
	temp = (*lst_a) -> content;
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

int	ft_min_number(t_node_list **lst_a)
{
	int	temp;
	t_node_list	*temp_list;

	if (!lst_a || !*lst_a)
		return (0);
	temp_list = *lst_a;
	temp = (*lst_a) -> content;
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

}



void	ft_bucket(t_node_list **lst_a)
{
	t_node_list	*lst_b;
	int number_min; // Para guardar el VALOR del número más pequeño
	int total; // Para guardar la cantidad total de elementos
	int bucket_number; // Para guardar el tamaño del bloque (raíz cuadrada)
	int number_limit; // Para guardar tu "número límite" actual
	int	end_of_bucket;
	int	number_max;
	
	if (lst_a == NULL || *lst_a == NULL || (*lst_a) -> next == NULL)
		return ;
	lst_b = NULL;
	//lst_b =  malloc(sizeof(t_node_list));
	number_min = ft_min_number(lst_a);
	number_max = ft_max_number(lst_a);
	total = ft_lstsize (*lst_a);
	bucket_number = sqroot(total);
	number_limit = (bucket_number + number_min);
	end_of_bucket = ft_lstlast(*lst_a) -> content;

	printf("nmber limit %i\n", number_limit);
	printf("nmber %i\n", number_min);
	printf("bucket %i\n", bucket_number);
	while (*lst_a != NULL && number_limit <= end_of_bucket)
	{
		while (*lst_a != NULL && (*lst_a) -> content < number_limit)
		{
			ft_pb(&lst_b, lst_a);
			printf("push %i\n",lst_b -> content);
		}
		if ((*lst_a) -> content == end_of_bucket)
		{
			number_limit = number_limit + bucket_number;
			printf("nmber limit %i\n", number_limit);
		}
		if ((*lst_a) -> next != NULL)
			ft_ra(lst_a);
	}
	printf("salio \n");

	if((*lst_a) -> content == number_max)
	{
		printf("last node %i\n", (*lst_a) -> content);
		ft_pb(&lst_b, lst_a);
		printf("push %i\n",lst_b -> content);
	}
	/* while ((*lst_b))
		{
			ft_pa();
		} */

 	printf("First B node: %d\n", lst_b -> content);
	printf("Second B node: %d\n", lst_b -> next -> content);
	printf("Third B node: %d\n", lst_b -> next -> next -> content);
	printf("Fourth B node: %d\n", lst_b -> next -> next -> next -> content);
	printf("Fifth B node: %d\n", lst_b -> next -> next -> next -> next -> content);
	printf("Sixth B node: %d\n", lst_b -> next -> next -> next -> next -> next -> content);
	printf("siete B node: %d\n", lst_b -> next -> next -> next -> next -> next -> next -> content);
	printf("ocho B node: %d\n\n", lst_b -> next -> next -> next -> next -> next -> next ->  next ->content);
}

//void lstnode(lista_ref, cant_nodos) para hacer la lista bien problema que creo que es la lista vacia del b crear los nodos vacios
// comprobar que la lista B esta a null
// hacer el prev ayuda mucho.


int	main(void)
{
	t_node_list	*lst_a;

	lst_a = NULL;
	lst_a = ft_lstnew(14);
	ft_lstadd_back(&lst_a, ft_lstnew(12));
	ft_lstadd_back(&lst_a, ft_lstnew(15));
	ft_lstadd_back(&lst_a, ft_lstnew(1));
	ft_lstadd_back(&lst_a, ft_lstnew(13));
	ft_lstadd_back(&lst_a, ft_lstnew(16));
	ft_lstadd_back(&lst_a, ft_lstnew(2));
	ft_lstadd_back(&lst_a, ft_lstnew(18));
	ft_lstadd_back(&lst_a, ft_lstnew(9));

	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
	printf("Fifth A node: %d\n", lst_a -> next -> next -> next -> next -> content);
	printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);
	printf("siete A node: %d\n", lst_a -> next -> next -> next -> next -> next -> next -> content);
	printf("ocho A node: %d\n", lst_a -> next -> next -> next -> next -> next -> next-> next -> content);
	printf("nueve A node: %d\n\n", lst_a -> next -> next -> next -> next -> next -> next-> next -> next -> content);


	ft_bucket(&lst_a);
/*
	printf("First B node: %d\n", lst_b -> content);
	printf("Second B node: %d\n", lst_b -> next -> content);
	printf("Third B node: %d\n", lst_b -> next -> next -> content);
	printf("Fourth B node: %d\n", lst_b -> next -> next -> next -> content);
	printf("Fifth B node: %d\n\n", lst_b -> next -> next -> next -> next -> content);
	//printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);
*/
	ft_lstclear(&lst_a);
	return (0);
}