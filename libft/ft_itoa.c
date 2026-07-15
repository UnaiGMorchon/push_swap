/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 08:56:17 by unai              #+#    #+#             */
/*   Updated: 2026/05/19 09:21:35 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// =========================================================================
// 1. FUNCIÓN AUXILIAR: Cuenta cuántos caracteres ocupará el número
// =========================================================================
static int	ft_number_len(int num)
{
	int	i;

	i = 0;
// Caso base: si el número es 0, ocupará exactamente 1 carácter ('0')
	if (num == 0)
		return (1);
// Si el número es negativo, sumamos 1 espacio para el carácter del signo menos ('-')
	if (num < 0)
	{
		i++;
	}
// Descomponemos el número dividiéndolo entre 10 hasta que quede en 0
	while (num != 0)
	{
		num = num / 10;
		i++; // Sumamos 1 por cada dígito encontrado
	}
	return (i);
}

// =========================================================================
// 2. FUNCIÓN PRINCIPAL: ft_itoa
// ========================================================================
char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	number; // Usamos un 'long' para evitar desbordamientos con INT_MIN (-2147483648)

	number = n;
// Calculamos la longitud total de la cadena que necesitamos crear
	len = ft_number_len(n);
// Reservamos memoria para los caracteres numéricos más el terminador nulo '\0' (+1)
	(result = (char *)malloc((len + 1) * sizeof(char)));
// Protección clásica de malloc por si el sistema se queda sin memoria
	if (!result)
		return (NULL);
// Colocamos el terminador nulo al final absoluto del string
	result[len] = '\0';
// Caso especial: si el número es 0, lo ponemos directamente en la primera posición
	if (number == 0)
		result[0] = '0';
// Gestión de números negativos
	if (number < 0)
	{
		result[0] = '-'; // Colocamos el signo menos al principio del string
		number = -number; // Convertimos el número a positivo dentro de la seguridad del long
	}
	// Rellenamos el string de derecha a izquierda (desde el final hacia el principio)
	while (number > 0)
	{
		// El pre-decremento (--len) hace que restemos 1 al índice antes de escribir.
		// Tomamos el último dígito con el módulo (number % 10), le sumamos '0' 
		// para pasarlo a ASCII y lo guardamos en la posición actual.
		result[--len] = (number % 10) + '0';
		// Eliminamos el último dígito del número para procesar el siguiente en la próxima vuelta
		number = number / 10;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	str = ft_itoa(1125);

	if (str)
	{
		printf("%s\n", str); // Debería imprimir "1125"
		free(str); // Recuerda liberar la memoria reservada por itoa al terminar
	}
	return (0);
}*/
