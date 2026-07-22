/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_adaptive_algo.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:09:11 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:41:19 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declarar un puntero 'bench' para contener la estructura de seguimiento de métricas/operaciones.
	2. Asignar memoria dinámicamente para la estructura 't_bench' usando malloc.
	3. Inicializar el campo flotante de la métrica de desorden en 0.0.
	4. Establecer el puntero inicial del nombre de la estrategia en NULL.
	5. Establecer el contador total de operaciones en 0.
	6. Reiniciar todos los contadores de operaciones individuales (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr) a 0.
	7. Devolver el puntero a la estructura bench recién asignada e inicializada.
*/

t_bench	*ft_initialise_bench(void)
{
	t_bench	*bench;

	bench = malloc(sizeof(t_bench));
	bench -> disorder = 0.0;
	bench -> strategy = NULL;
	bench -> total = 0;
	bench -> sa = 0;
	bench -> sb = 0;
	bench -> ss = 0;
	bench -> pa = 0;
	bench -> pb = 0;
	bench -> ra = 0;
	bench -> rb = 0;
	bench -> rr = 0;
	bench -> rra = 0;
	bench -> rrb = 0;
	bench -> rrr = 0;
	return (bench);
}

/*
	1. Declarar un puntero 'flag_bench' para contener la estructura contenedora de banderas y métricas.
	2. Asignar memoria dinámicamente para la estructura 't_isflag' usando malloc.
	3. Inicializar el campo del puntero 'flag' en NULL.
	4. Inicializar el campo del puntero 'bench' en NULL.
	5. Devolver el puntero a la estructura flag/bench recién asignada.
*/

t_isflag	*ft_initialise_flag_bench(void)
{
	t_isflag	*flag_bench;

	flag_bench = malloc(sizeof(t_isflag));
	flag_bench -> flag = NULL;
	flag_bench -> bench = NULL;
	return (flag_bench);
}
/*
	1. Declarar un puntero temporal 'tmp' para recorrer los nodos por delante de la cabeza actual.
	2. Declarar 'mistakes' como un número flotante para contar las inversiones de parejas (elementos desordenados).
	3. Declarar 'total_pairs' como un número flotante para contar el total de parejas únicas comparadas.
	4. Declarar los contadores de bucle 'i' y 'j' para la iteración anidada sobre la pila.
	5. Inicializar los contadores de errores y total de parejas a 0.00f.
	6. Ejecutar un bucle externo 'i' para evaluar cada elemento como el elemento principal de comparación.
	7. Establecer 'tmp' para que apunte al nodo inmediatamente posterior al nodo cabeza actual.
	8. Ejecutar un bucle interno 'j' para comparar el nodo cabeza con todos los nodos restantes después de él.
	9. Incrementar la cuenta de 'total_pairs' por cada pareja evaluada.
	10. Comprobar si el valor de la cabeza actual es mayor que el valor de 'tmp'; si es así, incrementar 'mistakes'.
	11. Mover 'tmp' al siguiente nodo de la lista para el bucle de comparación interno.
	12. Desplazar 'head' al siguiente nodo para avanzar el punto de comparación principal.
	13. Restaurar/avanzar la referencia de la cabeza tras finalizar los bucles para mantener el estado de la lista.
	14. Devolver el coeficiente de desorden dividiendo los errores totales entre las comparaciones totales de parejas.
*/

float	ft_disorder_metric(t_stack *lst)
{
	t_node_list	*tmp;
	float		mistakes;
	float		total_pairs;
	int			i;
	int			j;

	mistakes = 0.00f;
	total_pairs = 0.00f;
	i = 0;
	while (i < lst -> size - 1)
	{
		tmp = lst -> head -> next;
		j = i + 1;
		while (j++ < lst -> size)
		{
			total_pairs += 1;
			if (lst -> head -> content > tmp -> content)
				mistakes += 1;
			tmp = tmp -> next;
		}
		lst -> head = lst -> head -> next;
		i++;
	}
	lst -> head = lst -> head -> next;
	return (mistakes / total_pairs);
}

/*
	1. Comprobar si el tamaño de la pila es igual o menor a 5.
	2. Establecer la cadena de estrategia en "Adaptive / O(n2)", indexar elementos y llamar a 'ft_shortlist_sort'.
	3. En caso contrario, comprobar si la métrica de desorden calculada es baja (menor a 0.2).
	4. Establecer la cadena de estrategia en "Adaptive / O(n2)" y llamar a 'ft_bubble_sort' para datos casi ordenados.
	5. En caso contrario, comprobar si el desorden es moderado (entre 0.2 inclusive y 0.5 exclusivo).
	6. Establecer la cadena de estrategia en "Adaptive / O(n√n)" y llamar al algoritmo 'ft_bucket'.
	7. En caso contrario, si el desorden es alto (mayor o igual a 0.5).
	8. Establecer la cadena de estrategia en "Adaptive / O(n log n)", indexar elementos y llamar a 'ft_radix'.
*/

void	ft_adaptive_algo(t_stack *lst, t_bench *bench)
{
	if (lst -> size <= 5)
	{
		bench -> strategy = "Adaptive / O(n2)";
		ft_get_index(lst);
		ft_shortlist_sort(lst, bench);
	}
	else if (bench -> disorder < 0.2)
	{
		bench -> strategy = "Adaptive / O(n2)";
		ft_bubble_sort(lst, bench);
	}
	else if (bench -> disorder >= 0.2 && bench -> disorder < 0.5)
	{
		bench -> strategy = "Adaptive / O(n√n)";
		ft_bucket(lst, bench);
	}
	else if (bench -> disorder >= 0.5)
	{
		bench -> strategy = "Adaptive / O(n log n)";
		ft_get_index(lst);
		ft_radix(lst, bench);
	}
}
