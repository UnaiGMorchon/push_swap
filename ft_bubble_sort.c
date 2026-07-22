/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:43:35 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:37:06 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declarar 'swapped' como una bandera tipo booleana para comprobar si se movieron elementos.
	2. Declarar un entero 'i' para contar los pasos en la pasada de ordenación actual.
	3. Comprobación de seguridad: si la pila o su cabeza es NULL, detener inmediatamente.
	4. Inicializar la bandera 'swapped' en 1 para forzar el inicio del bucle principal while.
	5. Ejecutar el bucle principal mientras se haya realizado al menos un intercambio en la pasada previa.
	6. Reiniciar el contador de pasos 'i' a 0 al comienzo de cada pasada.
	7. Reiniciar la bandera 'swapped' a 0, asumiendo que la lista ya podría estar ordenada.
	8. Ejecutar un bucle interno para comprobar parejas hasta el tamaño total de la pila menos uno.
	9. Comparar el contenido del nodo cabeza actual con el contenido del siguiente nodo.
	10. Si el nodo actual es mayor, llamar a ft_sa para intercambiar los dos elementos superiores.
	11. Establecer la bandera 'swapped' en 1 porque se realizó un cambio en la lista.
	12. Llamar a ft_ra para rotar la pila, desplazando la siguiente pareja a la parte superior.
	13. Incrementar el contador de pasos 'i' en 1 para avanzar.
	14. Llamar a ft_ra una vez adicional tras el bucle interno para corregir la alineación final de la pila.
*/

void	ft_bubble_sort(t_stack *lst, t_bench *bench)
{
	int	swapped;
	int	i;

	ft_get_index(lst);
	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < lst -> size - 1)
		{
			if (lst-> head-> index > lst-> head -> next -> index)
			{
				ft_sa(lst, bench);
				swapped = 1;
			}
			ft_ra(lst, bench);
			i ++;
		}
		ft_ra(lst, bench);
	}
	ft_clearstack(lst);
}
