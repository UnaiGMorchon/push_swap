/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bench.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:18:29 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/22 13:29:30 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Print individual swap operation counts (sa, sb, ss) to standard error (fd 2).
	2. Print push operation counts (pa, pb) to standard error.
	3. Output a newline to format the operation breakdown neatly.
	4. Print single rotate operation counts (ra, rb, rr) to standard error.
	5. Print reverse rotate operation counts (rra, rrb, rrr) to standard error.
	6. Write a final newline character to end the metrics output block.
	7. Return 0 to complete function execution.
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
	1. Declare integer variables for the integer part, decimal part, and total scaled disorder.
	2. Convert the disorder float metric into a scaled integer representation (multiplied by 10000).
	3. Calculate the integer component of the disorder percentage.
	4. Calculate the two-decimal fractional component of the disorder percentage.
	5. Output the disorder percentage label and formatted integer part to standard error.
	6. Print the decimal point separator.
	7. Append a leading zero if the decimal part is less than 10 for accurate formatting.
	8. Print the decimal part along with the percent sign and newline.
	9. Print the selected algorithm strategy label stored in the bench structure.
	10. Output the total count of executed push_swap instructions.
	11. Call helper function 'ft_bench_help' to print detailed individual operation counts.
	12. Return 0 to indicate successful output completion.
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
