/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_sqrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:22:44 by patperez          #+#    #+#             */
/*   Updated: 2026/06/24 11:00:05 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double  sqroot(int x)
{
    double	y;
    int p;
    int square;
    int c;

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

int	main(void)
{
	printf("square root of 14 is %f", sqroot(14));
	return (0);
}
