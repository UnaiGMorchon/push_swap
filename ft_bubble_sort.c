/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/06/22 15:40:26 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	ft_sa(t_node_list **lst_a)
{
	t_node_list	*temp;

	if (lst_a == NULL || *lst_a == NULL || (*lst_a)->next == NULL)
		return ;
	temp = (*lst_a)->next;
	(*lst_a)->next = temp->next;
	temp->next = (*lst_a);
	(*lst_a) = temp;
}

void    ft_ra(t_node_list **lst)
{
    t_node_list *tmp_first;
    t_node_list *tmp_last;

    if (!lst)
        return ;
    if ((*lst) == NULL || lst == NULL || (*lst)->next == NULL)
        return ;
    {
        tmp_first = (*lst);
        (*lst) = (*lst)->next;
        tmp_first->next = NULL;
        tmp_last = ft_lstlast(*lst);
        tmp_last->next = tmp_first;
    }
}

void	bubble_sort(t_node_list **lst)
{
	int	swapped;

	if (lst == NULL || *lst == NULL || (*lst) -> next == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		if (*lst -> content > *lst -> next -> content)
		{
			ft_sa(lst);
			ft_ra(lst);
			swapped = 1;
		}
		else if (*lst -> content < *lst -> next -> content)
		{
			ft_ra(lst);
			swapped = 1;
		}
	}
}

int	main(void)
{
	t_node_list   *lst_a;

	lst_a = NULL;
	lst_a = ft_lstnew(14);
	ft_lstadd_back(&lst_a, ft_lstnew(12));
	ft_lstadd_back(&lst_a, ft_lstnew(15));
	ft_lstadd_back(&lst_a, ft_lstnew(1));
	ft_lstadd_back(&lst_a, ft_lstnew(13));

	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);    
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
    printf("Fifth A node: %d\n\n", lst_a -> next -> next -> next -> next -> content);
	//printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);

	bubble_sort(&lst_a);
	printf("First A node: %d\n", lst_a -> content);
	printf("Second A node: %d\n", lst_a -> next -> content);
	printf("Third A node: %d\n", lst_a -> next -> next -> content);
	printf("Fourth A node: %d\n", lst_a -> next -> next -> next -> content);
	printf("Fifth A node: %d\n\n", lst_a -> next -> next -> next -> next -> content);
	//printf("Sixth A node: %d\n", lst_a -> next -> next -> next -> next -> next -> content);

	ft_lstclear(&lst_a);
	return (0);
}
