/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:23:06 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/10 09:26:56 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_decide_letter(char character, va_list args)
{
	int	counter;

	counter = 0;
	if (character == 'c')
		counter = ft_putchar(va_arg(args, int));
	else if (character == 's')
		counter = ft_putstr(va_arg(args, char *));
	else if (character == 'p')
		counter = ft_put_void((unsigned long int) va_arg(args, void *));
	else if (character == 'd')
		counter = ft_putnbr(va_arg(args, int));
	else if (character == 'i')
		counter = ft_putnbr(va_arg(args, int));
	else if (character == 'u')
		counter = ft_putnbr_unsigned(va_arg(args, unsigned int ));
	else if (character == 'x')
		counter = ft_putnbr_hexa_min(va_arg(args, unsigned int));
	else if (character == 'X')
		counter = ft_putnbr_hexa_may(va_arg(args, unsigned int));
	else if (character == '%')
		counter = write(1, "%", 1);
	return (counter);
}

int	ft_printf(char const *string, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!string)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%' && string[i + 1] != '\0')
		{
			count += ft_decide_letter(string[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(string[i]);
			count ++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/* 
#include <stdio.h>

int	main(void)
{
	// void *ptr = "hola";
	
	int	total_characters;
	int	total_original;

	total_characters = ft_printf("f: %c, %s, %d, %i, %u, %x, %X, %p, %%", 'A', "casa", -2147483647, 3, -4, 10, 13, "hola");
	printf("\nft_printf total characters = f = %d\n", total_characters);
	ft_putchar('\n');
	
	total_original = printf("p: %c, %s, %d, %i, %u, %x, %X, %p, %%", 'A', "casa", -2147483647, 3, -4, 10, 13, "hola");
	printf("\nprintf total original = p = %d\n", total_original);
	ft_putchar('\n');
 */
/*
	int r;

	printf(" debe devolver 1 ");
	r = ft_printf("%c", 'A');
	printf(" -> contador ft_printf = %d\n", r);
	ft_putchar('\n');
	
	printf(" debe devolver 4 ");
	r = ft_printf("%s", "casa");
	printf(" -> contador ft_printf = %d\n", r);
	ft_putchar('\n');
	
	printf(" debe devolver 11 ");
	r = ft_printf("%d", -2147483647);
	printf(" -> contador ft_printf = %d\n", r);
	ft_putchar('\n');

	printf(" debe devolver 1 ");
	r = ft_printf("%i", 3);
	printf(" -> contador ft_printf = %d\n", r);
	ft_putchar('\n');

	printf(" debe devolver 10 ");
	r = ft_printf("%u", -4);
	printf(" -> contador ft_printf = %d\n", r);
	ft_putchar('\n');

	printf(" debe devolver 1 ");
	r = ft_printf("%x", 10);
	printf(" -> contador ft_printf = %d\n", r);
	ft_putchar('\n');

	printf(" debe devolver 1 ");
	r = ft_printf("%X", 13);
	printf(" -> contador ft_printf = %d\n", r);
	ft_putchar('\n');

	printf(" debe devolver 11 : 0x + 9 chars ");
	r = ft_printf("%p", "hola");
	printf(" -> contador ft_printf = %d\n", r);
	ft_putchar('\n');

	printf(" debe devolver 1 ");
	r = ft_printf("%%");
	printf(" -> contador ft_printf = %d\n", r);
	ft_putchar('\n');
*/
	/* return (0);
} */
