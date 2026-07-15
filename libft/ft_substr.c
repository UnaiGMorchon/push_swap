/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 07:37:46 by unai              #+#    #+#             */
/*   Updated: 2026/05/19 07:43:03 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i; // Índice para recorrer las cadenas y copiar los caracteres
	char	*subs; // Puntero donde reservaremos memoria para la nueva subcadena
	size_t	s_len; // Variable para almacenar la longitud de la cadena original 's'
// 1. Protección contra punteros nulos
	if ((const char *)s == NULL)
		return (NULL);
// Obtener la longitud de la cadena original
	s_len = ft_strlen(s);
// 2. Si el índice de inicio (start) está fuera de los límites de la cadena 's'
	if (start >= s_len)
	{
// Retorna una cadena vacía asignada con memoria (un solo byte '\0') usando ft_calloc
		return (ft_calloc(1, sizeof(char)));
	}
// 3. Ajuste de longitud (len)
    // Si la longitud solicitada es mayor que los caracteres disponibles desde 'start' hasta el final,
    // recortamos 'len' para que solo copie lo que realmente existe. Evita desbordamientos.
	if (len > s_len - start)
		len = s_len - start;
// 4. Reserva de memoria
    // Reservamos memoria para 'len' caracteres más 1 byte para el carácter nulo ('\0') terminador
	subs = malloc(sizeof(char) * (len + 1));
// Si malloc falla y no puede asignar memoria, retornamos NULL
	if (subs == NULL)
		return (NULL);
// 5. Copia de caracteres
	i = 0;
// Copiamos mientras no hayamos alcanzado la longitud deseada (len) 
    // y la cadena original en esa posición no haya terminado
	while (i < len && s[start + i])
	{
		subs[i] = s[start + i]; // Copia el carácter correspondiente
		i++;
	}
// 6. Cierre de la cadena
    // Añadimos el carácter nulo al final para que sea una cadena de texto válida en C
	subs[i] = '\0';
// Retornamos el puntero a la nueva subcadena creada
	return (subs);
}
/*
#include <stdio.h>

int	main(void)
{
// Cadena de prueba
	char	result[] = "Hello world";

// Llama a la función empezando en el índice 2 ('l') con una longitud de 6 caracteres.
    // Debería imprimir: "llo wo"
	printf("%s\n", ft_substr(result, 2, 6));
	return (0);
}*/
