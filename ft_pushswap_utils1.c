/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:20:17 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:45:54 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declarar una variable puntero 'new_node' de tipo t_node_list.
	2. Asignar memoria para la estructura de un nodo usando malloc.
	3. Comprobación de seguridad: si malloc falla y devuelve NULL, salir devolviendo NULL.
	4. Inicializar el puntero next del nuevo nodo a NULL.
	5. Inicializar el puntero prev del nuevo nodo a NULL.
	6. Establecer el valor de índice por defecto del nodo en 0.
	7. Asignar el entero 'content' pasado como argumento al contenido del nodo.
	8. Devolver el nuevo nodo creado e inicializado correctamente.
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
	1. Declarar una variable puntero 'stack' de tipo t_stack.
	2. Asignar memoria para la estructura de control de la pila usando malloc.
	3. Comprobación de seguridad: si malloc falla y devuelve NULL, salir devolviendo NULL.
	4. Inicializar el puntero cabeza (head) de la pila a NULL (comienza vacía).
	5. Inicializar el puntero cola (tail) de la pila a NULL (comienza vacía).
	6. Establecer el contador de tamaño inicial de la pila en 0.
	7. Devolver la estructura de la pila creada e inicializada correctamente.
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
	1. Comprobación de seguridad: si los punteros de stack o new_node son NULL, detener.
	2. Si la cola (tail) de la pila es NULL, la lista está completamente vacía.
	3. Establecer tanto la cabeza como la cola de la pila al nuevo nodo.
	4. Apuntar next y prev de new_node a sí mismo para formar el primer bucle circular.
	5. Si la lista no está vacía, ejecutar el bloque else para elementos existentes.
	6. Conectar next de new_node a la cabeza actual de la pila.
	7. Conectar prev de new_node a la cola de la pila para mantener la circularidad.
	8. Actualizar el prev de la cabeza antigua para que apunte de vuelta a new_node.
	9. Actualizar el next de la cola para que apunte hacia adelante a new_node.
	10. Actualizar el puntero cabeza de la pila para hacer de new_node el nuevo primer elemento.
	11. Incrementar en 1 el contador del tamaño total de la pila.
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
	1. Comprobación de seguridad: si los punteros de stack o new_node son NULL, detener.
	2. Si la cabeza (head) de la pila es NULL, la lista está completamente vacía.
	3. Establecer tanto la cabeza como la cola de la pila al nuevo nodo.
	4. Apuntar next y prev de new_node a sí mismo para formar el primer bucle circular.
	5. Si la lista no está vacía, ejecutar el bloque else para elementos existentes.
	6. Conectar prev de new_node a la cola actual de la pila.
	7. Conectar next de new_node a la cabeza actual de la pila.
		8. Actualizar el next de la cola antigua para que apunte hacia adelante a new_node.
	9. Actualizar el prev de la cabeza para que apunte de vuelta a new_node.
	10. Actualizar el puntero cola de la pila para hacer de new_node el nuevo último elemento.
	11. Reforzar la circularidad vinculando prev de la cabeza a la cola actualizada.
	12. Reforzar la circularidad vinculando next de la cola a la cabeza actualizada.
	13. Incrementar en 1 el contador del tamaño total de la pila.
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
	1. Declarar 'buffer' para guardar el puntero del siguiente nodo antes de liberar el actual.
	2. Declarar 'tmp' para iterar a través de los nodos de la pila.
	3. Inicializar 'buffer' en NULL como mecanismo de programación defensiva.
	4. Comprobación de seguridad: si el puntero de la pila no existe, salir de la función.
	5. Apuntar 'tmp' al primer nodo (cabeza) de la pila para comenzar el bucle.
	6. Recorrer la pila hasta que todos los nodos sean procesados según el tamaño de la pila.
	7. Guardar la dirección del siguiente nodo en 'buffer' para evitar pérdidas de memoria.
	8. Liberar la memoria asignada para el nodo actual apuntado por 'tmp'.
	9. Mover 'tmp' al siguiente nodo guardado en el buffer.
	10. Decrementar el contador de tamaño de la pila por cada nodo liberado con éxito.
	11. Una vez finalizado el bucle, establecer el puntero cabeza de la pila a NULL.
	12. Establecer el puntero cola de la pila a NULL.
	13. Asegurar que el contador de tamaño de la pila se establezca explícitamente en 0.
	14. Liberar la memoria asignada para la estructura de control principal de la pila.
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
