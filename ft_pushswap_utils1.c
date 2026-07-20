/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:20:17 by patperez          #+#    #+#             */
/*   Updated: 2026/07/20 07:48:04 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswaplib.h"

/*
	1. Declare a pointer variable 'new_node' of type t_node_list.
	2. Allocate memory for one node structure using malloc.
	3. Security check: if malloc fails and returns NULL, exit returning NULL.
	4. Initialize the next pointer of the new node to NULL.
	5. Initialize the prev pointer of the new node to NULL.
	6. Set the default index value of the node to 0.
	7. Assign the integer 'content' passed as argument to the node's content.
	8. Return the successfully created and initialized new node.
*/

t_node_list	*ft_newnode(int content)
{
	t_node_list	*new_node;

	new_node = malloc(sizeof(t_node_list));
	if (!new_node)
		return (NULL);
	new_node -> next = NULL;
	new_node -> prev = NULL;
	new_node -> index = 0;
	new_node -> content = content;
	return (new_node);
}

/*
	1. Declare a pointer variable 'stack' of type t_stack.
	2. Allocate memory for the stack control structure using malloc.
	3. Security check: if malloc fails and returns NULL, exit returning NULL.
	4. Initialize the head pointer of the stack to NULL (starts empty).
	5. Initialize the tail pointer of the stack to NULL (starts empty).
	6. Set the initial size counter of the stack to 0.
	7. Return the successfully created and initialized stack structure.
*/

t_stack	*ft_newstack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack -> head = NULL;
	stack -> tail = NULL;
	stack -> size = 0;
	return (stack);
}

/*
	1. Security check: if stack or new_node pointers are NULL, stop.
	2. If stack tail is NULL, the list is completely empty.
	3. Set both head and tail pointers of the stack to the new_node.
	4. Point new_node's next and prev to itself to form the first circular loop.
	5. If the list is not empty, execute the else block for existing elements.
	6. Connect new_node's next to the current head of the stack.
	7. Connect new_node's prev to the tail of the stack for circularity.
	8. Update the old head's prev to point back to the new_node.
	9. Update the tail's next to point forward to the new_node.
	10. Update the stack's head pointer to make new_node the new first element.
	11. Increment the total size counter of the stack by 1.
*/

void	ft_stackadd_front(t_stack *stack, t_node_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack -> tail == NULL)
	{
		stack -> head = new_node;
		stack -> tail = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node -> next = stack -> head;
		new_node -> prev = stack -> tail;
		stack -> head -> prev = new_node;
		stack -> tail -> next = new_node;
		stack -> head = new_node;
	}
	stack -> size += 1;
}
/*
	1. Security check: if stack or new_node pointers are NULL, stop.
	2. If stack head is NULL, the list is completely empty.
	3. Set both head and tail pointers of the stack to the new_node.
	4. Point new_node's next and prev to itself to form the first circular loop.
	5. If the list is not empty, execute the else block for existing elements.
	6. Connect new_node's prev to the current tail of the stack.
	7. Connect new_node's next to the current head of the stack.
	8. Update the old tail's next to point forward to the new_node.
	9. Update the head's prev to point back to the new_node.
	10. Update the stack's tail pointer to make new_node the new last element.
	11. Enforce circularity by linking head's prev to the updated tail.
	12. Enforce circularity by linking tail's next to the updated head.
	13. Increment the total size counter of the stack by 1.
*/

void	ft_stackadd_back(t_stack *stack, t_node_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack -> head == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node -> prev = stack -> tail;
		new_node->next = stack->head;
		stack-> tail-> next = new_node;
		stack->head->prev = new_node;
		stack -> tail = new_node;
	}
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	stack -> size += 1;
}
/*
	1. Declare 'buffer' to save the next node pointer before freeing current one
	2. Declare 'tmp' to iterate through the stack nodes.
	3. Initialize 'buffer' to NULL as a defensive programming mechanism.
	4. Security check: if the stack pointer does not exist, exit the function.
	5. Point 'tmp' to the first node (head) of the stack to begin the loop.
	6. Loop through the stack until all nodes are processed based on stack size.
	7. Save the next node's address into 'buffer' to prevent memory loss.
	8. Free the memory allocated for the current node pointed by 'tmp'.
	9. Move 'tmp' to the next node saved in the buffer.
	10.Decrement the stack size counter for every node that is successfully freed
	11. Once the loop ends, set the stack's head pointer to NULL.
	12. Set the stack's tail pointer to NULL.
	13. Ensure the stack size counter is explicitly set to 0.
	14. Free the memory allocated for the main stack control structure.
*/

void	ft_clearstack(t_stack *lst)
{
	t_node_list	*buffer;
	t_node_list	*tmp;

	buffer = NULL;
	if (!lst)
		return ;
	tmp = lst -> head;
	while (lst->size)
	{
		buffer = tmp-> next;
		free(tmp);
		tmp = buffer;
		lst->size -= 1;
	}
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
	free(lst);
}