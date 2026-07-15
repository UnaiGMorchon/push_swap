/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:44:19 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:03:21 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlen(const char *s)
{
	size_t	i; // Variable de tipo 'size_t' (entero sin signo) para contar los caracteres

	i = 0; // Inicializamos el contador en 0

	// Bucle principal: recorre la cadena caracter por caracter.
	// La condición 's[i]' es equivalente a 's[i] != '\0''.
	// El bucle se ejecutará y sumará hasta que se tope con el carácter nulo terminador.
	while (s[i])
		i++; // Incrementamos el contador por cada carácter válido encontrado

	// Retornamos el valor de 'i', que representa la longitud exacta de la cadena
	// (sin contar el carácter nulo '\0' del final).
	return (i);
}

/*
#include <stdio.h>

int main(void)
{
	int	example;

	// "Hola_Mundo" tiene exactamente 10 caracteres.
	example = ft_strlen("Hola_Mundo");

	// Imprime el resultado en consola
	printf("%d", example); 
	return (0);
}
*/
