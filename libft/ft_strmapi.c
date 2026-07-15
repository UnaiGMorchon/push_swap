/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:51:00 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:02:18 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i; // Índice para recorrer la cadena 's' y rellenar 'temp'
	char	*temp; // Puntero donde reservaremos la memoria para la nueva cadena
	size_t	str_len; //Variable para almacenar la longitud de la cadena original

// 1. Protección contra punteros nulos
	// Si la cadena 's' no existe O la función 'f' es un puntero nulo, abortamos devolviendo NULL
	if (!s || !f)
		return (NULL);
// 2. Obtener la longitud de la cadena original
	str_len = ft_strlen((char *)s);
// 3. Reserva de memoria
	// Reservamos memoria para la nueva cadena: longitud de 's' + 1 byte para el '\0'
	temp = malloc(sizeof(char) * (str_len + 1));
// Si malloc falla al asignar memoria, devolvemos NULL
	if (temp == NULL)
		return (NULL);
// 4. Bucle de transformación
	i = 0;
// Recorremos la cadena original hasta encontrar el carácter nulo
	while (s[i])
	{
// Llamamos a la función 'f' pasándole:
		// - El índice actual 'i' (unsigned int)
		// - El carácter actual 's[i]'
		// El resultado devuelto por la función 'f' se guarda en la misma posición de 'temp'
		temp[i] = f(i, s[i]);
		i++;
	}
// 5. Cierre de la cadena
	// Añadimos el terminador nulo al final de la nueva cadena modificada
	temp[i] = '\0';
// Devolvemos el puntero a la nueva cadena creada y transformada
	return (temp);
}
/*
#include <stdio.h>

// Esta es una función de ejemplo que se adapta a lo que pide 'ft_strmapi'.
// Recibe un índice y un carácter. Si el índice es par y la letra es minúscula, la pasa a mayúscula.
char	f(unsigned int i, char c)
{
	if (i % 2 == 0 && (c >= 'a' && c <= 'z'))
		return (c - 32); // Restar 32 en ASCII convierte minúscula a mayúscula
	return (c);
}

int	main(void)
{
	char	*s;
	char	*res;

	s = "Hello world";
// Pasamos la cadena 's' y la dirección de la función 'f'
	res = ft_strmapi(s, f);
// Debería imprimir la cadena modificada intercalando mayúsculas en posiciones pares
	printf("%s\n", res);
	// Como 'ft_strmapi' usa malloc dentro, es obligatorio liberar la memoria al terminar
	free (res);
	return (0);
}*/
