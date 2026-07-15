/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 08:08:10 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 07:47:20 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str; // Puntero para la nueva cadena recortada
	int		i; // Índice para rellenar la nueva cadena
	int		start; // Índice para marcar dónde empieza el texto real (sin caracteres del set)
	int		end; // Índice para marcar dónde termina el texto real

// 1. Protección contra punteros nulos
	// Si la cadena original o el set de caracteres no existen, abortamos devolviendo NULL
	if (s1 == NULL || set == NULL)
		return (NULL);
// 2. Encontrar el inicio (Trim por la izquierda)
	start = 0;
// Mientras no lleguemos al final de s1 Y el carácter actual de s1 esté en el 'set'
	while (s1[start] && ft_strchr(set, s1[start]))
		start++; // Avanzamos el índice de inicio hacia la derecha
// 3. Encontrar el final (Trim por la derecha)
	end = ft_strlen(s1); // Empezamos desde la longitud total de la cadena
	// Mientras no hayamos cruzado el 'start' Y el carácter anterior esté en el 'set'
	// (Usamos end - 1 porque el índice final es la longitud, que apunta al '\0')
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--; // Retrocedemos el índice final hacia la izquierda
// 4. Reserva de memoria
	// Reservamos el tamaño exacto: (fin - inicio) + 1 para el carácter nulo '\0'
	str = (char *)malloc (sizeof(char) * (end - start + 1));
// Si malloc falla, devolvemos NULL (0)
	if (!str)
		return (0);
// 5. Copiar la subcadena limpia
	i = 0;
// Copiamos los caracteres desde la posición 'start' hasta justo antes de 'end'
	while (start < end)
	{
		str[i++] = s1[start++]; // Copia y avanza ambos índices
	}
	// 6. Cierre de la cadena
	str[i] = '\0'; // Añadimos el terminador nulo al final
// Devolvemos la nueva cadena recortada
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	string[] = "abchello worldbac";
	char	*set = "abc";
	char	*result;
	
	result = ft_strtrim(string, set);
	// Debería imprimir: "result = hello world"
	// Ya que elimina las 'a', 'b' y 'c' tanto del principio como del final.
	printf("result = %s\n", result);
	
// Recuerda que en un entorno real deberías liberar la memoria:
	// free(result);
	return (0);
}*/
