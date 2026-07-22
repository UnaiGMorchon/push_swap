/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:39:23 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declarar 'tmp' para iterar a través de los nodos de la pila B.
	2. Declarar 'max_node' para almacenar el puntero al nodo con el índice más alto.
	3. Declarar 'nodes' como un contador de bucle para hacer el seguimiento de los elementos procesados.
	4. Inicializar 'tmp' y 'max_node' para que apunten a la cabeza de la pila B.
	5. Inicializar el contador de bucle 'nodes' en 0.
	6. Recorrer la pila B exactamente tantas veces como su tamaño para evitar bucles infinitos.
	7. Comparar el índice del nodo actual 'tmp' con el índice máximo actual.
	8. Si el índice del nodo actual es mayor, actualizar 'max_node' para que apunte a él.
	9. Mover el puntero 'tmp' hacia adelante al siguiente nodo de la lista circular.
	10. Incrementar el contador 'nodes' en 1.
	11. Devolver el puntero al nodo que contiene el índice máximo.
*/

t_node_list	*ft_max_index(t_stack *lst_b)
{
	t_node_list	*tmp;
	t_node_list	*max_node;
	int			nodes;

	tmp = lst_b -> head;
	max_node = lst_b ->head;
	nodes = 0;
	while (nodes < lst_b -> size)
	{
		if (tmp -> index > max_node -> index)
			max_node = tmp;
		tmp = tmp -> next;
		nodes++;
	}
	return (max_node);
}

/*
	1. Declarar 'tmp' para encontrar la posición física del nodo objetivo.
	2. Declarar 'tmp_max_index' para guardar la dirección del nodo con el índice máximo.
	3. Declarar 'physical_node_position' para contar su distancia desde la cabeza.
	4. Encontrar y guardar la dirección del nodo con el índice más alto en la pila B.
	5. Mantener el bucle hasta que el nodo con el índice máximo llegue a la parte superior (cabeza).
	6. Reiniciar la variable de posición a 0 en cada paso del cálculo de rotación.
	7. Establecer 'tmp' en el nodo cabeza para empezar a medir la distancia.
	8. Ejecutar un bucle interno para contar los pasos desde la cabeza hasta alcanzar el nodo objetivo.
	 9. Mover 'tmp' hacia adelante al siguiente nodo.
	10. Incrementar el contador de posición en 1.
	11. Comprobar si el nodo objetivo está más cerca de la parte superior por la mitad superior de la pila.
	12. Llamar a ft_rb para rotar hacia arriba ya que el nodo está en la primera mitad de la pila.
	13. Llamar a ft_rrb para rotar en sentido inverso hacia abajo si está en la segunda mitad.
*/

void	ft_rotate_decide(t_stack *lst_b, t_bench *bench)
{
	t_node_list	*tmp;
	t_node_list	*tmp_max_index;
	int			physical_node_position;

	tmp_max_index = ft_max_index(lst_b);
	while (lst_b -> head != tmp_max_index)
	{
		physical_node_position = 0;
		tmp = lst_b -> head;
		while (tmp != tmp_max_index)
		{
			tmp = tmp -> next;
			physical_node_position++;
		}
		if (physical_node_position <= lst_b -> size / 2)
		{
			ft_rb(lst_b, bench);
		}
		else
		{
			ft_rrb(lst_b, bench);
		}
	}
}

/*
	1. Declarar 'tmp' para iterar a través de los nodos de la pila A.
	2. Declarar 'nodes' como un contador de bucle para evitar iteraciones circulares infinitas.
	3. Apuntar 'tmp' al nodo cabeza de la pila A para comenzar el escaneo.
	4. Inicializar el contador de iteraciones del bucle en 0.
	5. Recorrer los nodos de la pila según su tamaño total.
	6. Comprobar si el índice del nodo actual es menor que el límite del bloque (bucket) especificado.
	7. Devolver 1 inmediatamente si se encuentra un nodo coincidente dentro del bloque actual.
	8. Mover 'tmp' hacia adelante al siguiente nodo en la lista circular.
	9. Incrementar el contador 'nodes' en 1.
	10. Devolver 0 si el bucle termina y ningún nodo cumple la restricción del bloque.
*/

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

/*
	1. Declarar 'index_count' para rastrear cuántos valores son menores que el actual.
	2. Declarar el puntero 'current' para seleccionar el nodo que se está evaluando.
	3. Declarar el puntero 'current_aux' para comparar todos los demás nodos contra 'current'.
	4. Declarar 'i' como el contador de iteraciones del bucle principal.
	5. Declarar 'j' como el contador de iteraciones del bucle secundario.
	6. Establecer 'current' en el nodo cabeza para comenzar a calcular los índices.
	7. Inicializar el contador 'i' en 0.
	8. Recorrer todos los nodos usando 'i' para asignar índices a cada elemento.
	9. Reiniciar el rastreador de elementos menores 'index_count' a 0 para el nodo actual.
	10. Apuntar el iterador secundario 'current_aux' de nuevo a la cabeza de la pila A.
	11. Reiniciar el contador de iteración secundaria 'j' a 0.
	12. Comparar 'current' con cada nodo de la pila mediante un bucle secundario.
	13. Si 'current_aux' contiene un valor menor que 'current', incrementar index_count.
	14. Sumar 1 al valor de la posición relativa del índice.
	15. Mover 'current_aux' hacia adelante para comparar el siguiente nodo de la lista.
	16. Guardar la posición de clasificación relativa calculada en el índice del nodo.
	17. Mover 'current' hacia adelante para procesar el siguiente nodo en la pila A.
*/

void	ft_get_index(t_stack *lst_a)
{
	int			index_count;
	t_node_list	*current;
	t_node_list	*current_aux;
	int			i;
	int			j;

	current = lst_a -> head;
	i = 0;
	while (i++ < lst_a->size)
	{
		index_count = 0;
		current_aux = lst_a->head;
		j = 0;
		while (j++ < lst_a->size)
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

/*
	1. Declarar 'number_limit' para definir el umbral de índice superior del bloque actual.
	2. Declarar 'end_bucket' para guardar el paso de incremento de tamaño fijo para los bloques.
	3. Comprobación de seguridad: si la pila A no existe, está vacía o tiene 1 nodo, detener.
	4. Calcular el tamaño base de partición del bloque usando la función auxiliar ft_sqroot.
	5. Guardar el tamaño del bloque en 'end_bucket' para futuras ampliaciones del umbral.
	6. Bucle hasta que todos los nodos de la pila A se vacíen y se empujen a la pila B.
	7. Si el elemento superior de A encaja en el bloque actual, empujarlo inmediatamente a B.
	8. Si no, si otro nodo en A encaja en el bloque, rotar A para encontrarlo.
	9. De lo contrario, aumentar el límite para abrir el siguiente rango de números del bloque.
	10. Bucle hasta que la pila B quede completamente vacía para restaurar los elementos a A.
	11. Encontrar el elemento máximo en B y rotarlo hasta la posición superior.
	12. Empujar el elemento ordenado de vuelta a la parte superior de la pila A.
*/

void	ft_bucket(t_stack *lst_a, t_bench *bench)
{
	int		number_limit;
	int		end_bucket;
	t_stack	*lst_b;

	lst_b = ft_newstack();
	ft_get_index(lst_a);
	number_limit = ft_sqroot(lst_a -> size);
	end_bucket = number_limit;
	while (lst_a -> size)
	{
		if (lst_a -> head -> index < number_limit)
			ft_pb(lst_b, lst_a, bench);
		else if (ft_exist_bucket(lst_a, number_limit))
			ft_ra(lst_a, bench);
		else
			number_limit += end_bucket;
	}
	while (lst_b -> size)
	{
		ft_rotate_decide(lst_b, bench);
		ft_pa(lst_a, lst_b, bench);
	}
	ft_clearstack(lst_b);
	ft_clearstack(lst_a);
}
