/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:51:52 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:47:36 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declarar una variable entera 'counter' para acumular el conteo de argumentos restantes.
	2. Inicializar 'counter' en 0 antes de iniciar el bucle.
	3. Iterar mientras 'counter' sea menor que el total de argumentos 'argc' menos el desplazamiento actual '*i'.
	4. Incrementar 'counter' en 1 en cada iteración para contar los elementos restantes.
	5. Devolver el conteo total de argumentos restantes a quien llamó a la función.
*/

int	ft_args_count(int *i, int argc)
{
	int	counter;

	counter = 0;
	while (counter < (argc - *i))
	{
		counter++;
	}
	return (counter);
}
/*
	1. Declarar una variable entera 'i' para rastrear el índice actual en el array de cadenas.
	2. Inicializar el índice 'i' en 0 para comenzar a recorrer desde la primera cadena.
	3. Recorrer el array de cadenas terminado en NULL hasta llegar a NULL.
	4. Liberar la memoria asignada dinámicamente para la cadena individual en el índice 'i'.
	5. Incrementar 'i' para avanzar a la siguiente cadena en el array.
	6. Liberar el array principal de punteros después de limpiar todas las asignaciones internas.
*/

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/*
	1. Declarar una variable double 'y' para almacenar la aproximación de la raíz cuadrada.
	2. Declarar un entero 'p' para encontrar la parte entera de la raíz cuadrada.
	3. Declarar un entero 'square' para contener el valor al cuadrado de p.
	4. Declarar un entero 'c' para contar los ciclos de iteración de Newton-Raphson.
	5. Inicializar los contadores de bucle y las variables de cálculo en 0.
	6. Bucle para encontrar el entero inferior más cercano cuyo cuadrado sea menor o igual a x.
	7. Incrementar 'p' para probar el siguiente valor entero.
	8. Calcular el cuadrado del siguiente entero para compararlo con 'x'.
	9. Convertir el entero 'p' encontrado a tipo double y asignarlo a 'y'.
	10. Ejecutar un bucle exactamente 10 veces para refinar la aproximación.
	11. Aplicar la fórmula babilónica / Newton-Raphson para encontrar una raíz más cercana.
	12. Si el cuadrado de la aproximación coincide exactamente con x, devolverlo inmediatamente.
	13. Incrementar el contador de ciclos de iteración 'c' en 1.
	14. Devolver el valor de aproximación de la raíz cuadrada calculado.
*/

double	ft_sqroot(int x)
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

/*
	1. Declarar 'temp' para almacenar el contenido entero máximo encontrado.
	2. Declarar un puntero 'temp_list' para iterar a través de los nodos de la pila A.
	3. Establecer 'temp_list' en el nodo cabeza de la pila A para comenzar el procesamiento.
	4. Inicializar 'temp' con el contenido del primer nodo.
	5. Recorrer los nodos de la pila usando el tamaño de la pila para evitar bucles circulares infinitos.
	6. Si el contenido del nodo actual es mayor que el 'temp' guardado, actualizarlo.
	7. Almacenar el valor de contenido más alto en la variable 'temp'.
	8. Mover 'temp_list' hacia adelante al siguiente nodo en la lista circular.
	9. Devolver el valor entero máximo encontrado en la pila.
*/
/* 
int	ft_max_number(t_stack *lst_a)
{
	int			temp;
	t_node_list	*temp_list;

	temp_list = lst_a -> head;
	temp = lst_a -> head -> content;
	while (temp_list -> next != NULL)
	{
		if (temp > temp_list -> next -> content)
		{
			temp = temp_list -> content;
		}
		temp_list = temp_list -> next;
	}
	return (temp);
} */

/*
	1. Declarar 'temp' para almacenar el contenido entero mínimo encontrado.
	2. Declarar un puntero 'temp_list' para iterar a través de los nodos de la pila A.
	3. Establecer 'temp_list' en el nodo cabeza de la pila A para comenzar el procesamiento.
	4. Inicializar 'temp' con el contenido del primer nodo.
	5. Recorrer los nodos de la pila usando el tamaño de la pila para evitar bucles circulares infinitos.
	6. Si el contenido del nodo actual es menor que el 'temp' guardado, actualizarlo.
	7. Almacenar el valor de contenido más bajo en la variable 'temp'.
	8. Mover 'temp_list' hacia adelante al siguiente nodo en la lista circular.
	9. Devolver el valor entero mínimo encontrado en la pila.
*/
/* 
t_node_list	*ft_min_index(t_stack *lst)
{
	t_node_list	*tmp;
	t_node_list	*min_node;
	int			nodes;

	tmp = lst -> head;
	min_node = lst ->head;
	nodes = 0;
	while (nodes < lst -> size)
	{
		if (tmp -> index < min_node -> index)
			min_node = tmp;
		tmp = tmp -> next;
		nodes++;
	}
	return (min_node);
} */
