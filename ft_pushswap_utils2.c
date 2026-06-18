/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:51:52 by patperez          #+#    #+#             */
/*   Updated: 2026/06/18 11:53:52 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswaplib.h"

void    ft_lstclear(t_node_list **lst)
{
    t_node_list *buffer;

    buffer = NULL;
    if (!lst)
        return ;
    while (*lst)
    {
        buffer = (*lst)-> next;
        free(*lst);
        *lst = buffer;
    }
    free(*lst);
}
