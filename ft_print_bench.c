/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bench.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:18:29 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/23 10:37:16 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

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
