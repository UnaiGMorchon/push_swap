void    ft_reva(t_node_list **lst_a)
{
    t_node_list *tmp_newfirst;
    //t_node_list   *tmp_newlast;
    t_node_list *tmp_lst_copy;
    //t_node_list **tmp_lst_find;

    tmp_lst_copy = (*lst_a);
    //tmp_lst_find = lst_a;

    if (!lst_a || lst_a == NULL)
        return ;
    tmp_newfirst = ft_lstlast(tmp_lst_copy); // saves last node "15"
    //tmp_newlast = ft_lstfind(tmp_lst_find); // saves second to last node "14"
    ft_lstadd_front(lst_a, tmp_newfirst); // pushes "15" to top of list
    //ft_lstadd_back(lst_a, tmp_newlast);
}

t_node_list *ft_lstfind(t_node_list **lst)
{

    if (!lst || (*lst) -> next == NULL)
        return (NULL);
    while ((*lst) -> next != NULL && (*lst) -> next -> next != NULL)
    {
        *lst = (*lst) -> next;
    }
    return (*lst);
}


