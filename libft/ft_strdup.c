/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:57:41 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:23:17 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*ptr; // Puntero donde guardaremos la dirección de la nueva cadena duplicada

// 1. Reserva de memoria
	// Calculamos el tamaño necesario: la longitud de 'src' + 1 byte para el terminador nulo '\0'
	ptr = malloc(ft_strlen(src) + 1);
// Si malloc falla y no puede asignar la memoria, devolvemos NULL para evitar un segfault
	if (ptr == NULL)
		return (NULL);
// 2. Copia de la cadena
	// Usamos la función ft_strlcpy que programaste antes. 
	// Le pasamos el destino (ptr), el origen (src) y el tamaño total reservado (longitud + 1).
	// Esto asegura que la cadena se copie por completo y quede correctamente cerrada con el '\0'.
	ft_strlcpy(ptr, src, ft_strlen(src) + 1);
// 3. Devolvemos el puntero a la nueva cadena duplicada en memoria ram
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*dest;
// Duplicamos la cadena "hello world"
	dest = ft_strdup("hello world");
// Imprimimos el resultado para verificar que se copió correctamente
	printf("%s", dest);
// Al haber usado malloc dentro de ft_strdup, es de vital importancia 
	// liberar la memoria con free() cuando ya no la vayamos a usar para evitar leaks.
	free(dest);
	return (0);
}*/
