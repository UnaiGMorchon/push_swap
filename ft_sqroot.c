/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqroot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:22:44 by patperez          #+#    #+#             */
/*   Updated: 2026/06/24 12:40:48 by patperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double  sqroot(int x)
{
	double	y;
	int adder;
	int square;
	int count;

	adder = 0;
	square = 0;
	count = 0;
	while (x > square)
	{
		adder++;
		square = (adder + 1) * (adder + 1);
	}
	y = (double)adder;
	while (count < 10)
	{
		y = (x / y + y) / 2;
		if (y * y == x)
			return (y);
		count++;
	}
	return (y);
}

/*int	main(void)
{
	printf("square root of 14 is %f", sqroot(14));
	return (0);
}*/
