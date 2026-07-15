/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:09:41 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:40:15 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb; // Usamos un 'long' para evitar el desbordamiento (overflow) con el número mínimo de int
	char	c; // Variable auxiliar para convertir el dígito numérico a carácter ASCII

	nb = n; // Copiamos el valor de 'n' en nuestro long
// 1. Protección del Descriptor de Archivo (fd)
    // Los descriptores válidos en Unix van de 0 en adelante. Los inválidos son los negativos.
    // Cambiar '!fd' por 'fd < 0' permite usar el fd 0 (STDIN).
	if (!fd)
		return ;
// 2. Gestión de números negativos
	if (nb < 0)
	{
		write(fd, "-", 1); // Escribe el signo menos en el archivo/terminal
		nb = -nb; // Convierte el número a positivo para poder procesar sus dígitos
	}
// 3. Caso especial: El mínimo entero (INT_MIN)
    // NOTA: Al haber usado un 'long' arriba y hacer 'nb = -nb', el número -2147483648 
    // ya se habrá convertido en positivo (2147483648). Esta condición 'nb == -2147483648' 
    // nunca se cumplirá aquí abajo. (Ver explicación detallada abajo).
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
// 4. Paso recursivo (Descomponer el número)
	// Si el número tiene más de un dígito (es mayor o igual a 10)...
	if (nb >= 10)
	{
	// ...llamamos a la función a sí misma pasándole el número sin el último dígito (nb / 10).
	// Esto creará una pila de llamadas que viajará hasta el primer dígito del número.
		ft_putnbr_fd(nb / 10, fd);
	}
	// 5. Paso base y conversión a ASCII (Imprimir el dígito)
	// Cuando la recursividad empieza a volver hacia atrás, se ejecuta esta parte.
	// Tomamos el último dígito con el operador módulo (nb % 10) y le sumamos '0' 
	// para transformarlo en su valor correspondiente en la tabla ASCII.
	c = (nb % 10) + '0';
	write(fd, &c, 1); // Pintamos el carácter del dígito
}
/*
#include <stdio.h>

int	main(void)
{
	int	n;

	n = 96;
	// Imprime '96' en la salida estándar (1 = terminal)
	ft_putnbr_fd(n, 1);
	return (0);
}*/
