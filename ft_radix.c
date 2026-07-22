/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 09:19:02 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:48:14 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declarar una variable entera 'bits' para contar la longitud máxima de bits necesaria.
	2. Inicializar el contador 'bits' en 0 antes de procesar el tamaño.
	3. Iterar mientras 'size' sea mayor que 0 para calcular la profundidad de bits binarios.
	4. Dividir 'size' entre 2 en cada iteración para desplazar bit a bit.
	5. Incrementar el contador 'bits' para realizar el seguimiento del total de dígitos binarios requeridos.
	6. Devolver el número total de bits necesarios para representar el valor de índice más grande.
*/

static int	ft_get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while (size != 0)
	{
		size = size / 2;
		bits ++;
	}
	return (bits);
}
/*
	1. Declarar el puntero 'lst_b' para la pila auxiliar, el contador 'i', 'max_bits' y 'size'.
	2. Inicializar la pila vacía 'lst_b' para albergar elementos durante las pasadas de ordenación binaria.
	3. Reiniciar el contador de posición de bit actual 'i' a 0.
	4. Determinar los bits máximos necesarios según el índice más alto (tamaño de la pila menos uno).
	5. Recorrer cada posición de bit desde 0 hasta 'max_bits' - 1.
	6. Guardar el tamaño actual de 'lst_a' para iterar a través de todos los elementos en la pasada actual.
	7. Recorrer todos los elementos actualmente en la pila A.
	8. Comprobar si el i-ésimo bit del índice del nodo cabeza actual es igual a 1.
	9. Si el bit es 1, rotar la pila A con 'ft_ra' para mantener el elemento en la pila A.
	10. Si el bit es 0, empujar el elemento superior de la pila A a la pila B usando 'ft_pb'.
	11. Empujar todos los elementos de la pila B de vuelta a la pila A usando 'ft_pa' para finalizar la pasada.
	12. Incrementar el índice de bit 'i' para evaluar el siguiente nivel de significación binaria.
	13. Liberar toda la memoria asociada con la pila auxiliar B una vez finalizada la ordenación.
*/

void	ft_radix(t_stack *lst_a, t_bench *bench)
{
	t_stack		*lst_b;
	int			i;
	int			max_bits;
	int			size;

	lst_b = ft_newstack();
	i = 0;
	max_bits = ft_get_max_bits(lst_a->size - 1);
	while (i < max_bits)
	{
		size = lst_a -> size;
		while (size-- > 0)
		{
			if (((lst_a -> head -> index >> i) & 1) == 1)
				ft_ra(lst_a, bench);
			else
				ft_pb(lst_b, lst_a, bench);
		}
		while (lst_b-> size)
			ft_pa(lst_a, lst_b, bench);
		i++;
	}
	ft_clearstack(lst_b);
}
