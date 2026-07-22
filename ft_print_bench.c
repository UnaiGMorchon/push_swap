/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bench.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:18:29 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/22 13:43:39 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Imprimir los conteos de operaciones individuales de intercambio (sa, sb, ss) en la salida de error estándar (fd 2).
	2. Imprimir los conteos de operaciones de empuje (pa, pb) en la salida de error estándar.
	3. Imprimir un salto de línea para dar un formato limpio al desglose de operaciones.
	4. Imprimir los conteos de operaciones individuales de rotación (ra, rb, rr) en la salida de error estándar.
	5. Imprimir los conteos de operaciones de rotación inversa (rra, rrb, rrr) en la salida de error estándar.
	6. Escribir un carácter de salto de línea final para terminar el bloque de salida de métricas.
	7. Devolver 0 para completar la ejecución de la función.
*/

static char	ft_bench_help(t_bench *bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench -> sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench -> sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench -> ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench -> pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench -> pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(bench -> ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench -> rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench -> rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench -> rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench -> rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench -> rrr, 2);
	write(2, "\n", 1);
	return (0);
}
/*
	1. Declarar variables enteras para la parte entera, la parte decimal y el desorden total escalado.
	2. Convertir la métrica flotante de desorden en una representación entera escalada (multiplicada por 10000).
	3. Calcular el componente entero del porcentaje de desorden.
	4. Calcular el componente fraccionario de dos decimales del porcentaje de desorden.
	5. Imprimir la etiqueta del porcentaje de desorden y la parte entera formateada en la salida de error estándar.
	6. Imprimir el separador de punto decimal.
	7. Añadir un cero a la izquierda si la parte decimal es menor a 10 para garantizar un formato preciso.
	8. Imprimir la parte decimal junto con el signo de porcentaje y un salto de línea.
	9. Imprimir la etiqueta de la estrategia del algoritmo seleccionada almacenada en la estructura bench.
	10. Imprimir el conteo total de instrucciones de push_swap ejecutadas.
	11. Llamar a la función auxiliar 'ft_bench_help' para imprimir los conteos detallados de cada operación individual.
	12. Devolver 0 para indicar la finalización con éxito de la salida.
*/

char	ft_print_bench(t_bench *bench)
{
	int	int_part;
	int	dec_part;
	int	total;

	total = (int)(bench -> disorder * 10000.0f);
	int_part = total / 100;
	dec_part = total % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(int_part, 2);
	write(2, ".", 1);
	if (dec_part < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(dec_part, 2);
	write(2, "%", 1);
	write(2, "\n", 1);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(bench -> strategy, 2);
	write(2, "\n", 1);
	ft_putstr_fd("[bench] total: ", 2);
	ft_putnbr_fd(bench -> total, 2);
	write(2, "\n", 1);
	ft_bench_help(bench);
	return (0);
}
