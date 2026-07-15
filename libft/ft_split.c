/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:40:29 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/05/19 08:34:50 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	int	count_words; // Contador total de palabras
	int	i; // Índice para recorrer la cadena

	count_words = 0;
	i = 0;
// Salta todos los caracteres delimitadores 'c' seguidos (ej. espacios)
	while (str[i] != '\0')
	{
		while (str[i] == c)
		{
			i++;
		}
// Si después de saltar los delimitadores no hemos llegado al final,
	// significa que hemos encontrado el inicio de una palabra.
		if (str[i])
			count_words++;
// Recorre y salta toda la palabra hasta encontrar el siguiente delimitador o el '\0'
		while (str[i] && str[i] != c)
		{
			i++;
		}
	}
	return (count_words); // Devuelve el número total de palabras encontradas
}

// =========================================================================
// 2. FUNCIÓN AUXILIAR: Libera la memoria en caso de fallo (Previene Memory Leaks)
// =========================================================================
static char	**ft_free_words(char **words, int index)
{
// Va hacia atrás liberando la memoria de cada palabra guardada hasta el momento
	while (index > 0)
	{
		index--;
		free(words[index]);
	}
	free(words); // Finalmente libera el array de punteros principal
	return (NULL);
}

// =========================================================================
// 3. FUNCIÓN AUXILIAR: Reserva memoria y copia cada palabra en el array
// =========================================================================
static int	ft_fill_words(char const *str, char c, char **words)
{
	int	i;
	int	start; // Guarda el índice donde empieza una palabra
    int	word_index; // Índice para saber en qué posición del array 'words' guardar la palabra

	i = 0;
	word_index = 0;
	while (str[i] != '\0')
	{
		// Salta los delimitadores iniciales
		while (str[i] == c)
			i++;
		start = i; // Marca el inicio de la palabra
		// Avanza hasta el final de la palabra
		while (str[i] && str[i] != c)
			i++;
		// Si la posición avanzó (i > start), encontramos una palabra válida
		if (i > start)
		{
			// Extrae la palabra usando la función ft_substr que programaste antes.
			// Longitud de la palabra = posición actual (i) menos el inicio (start).
			words[word_index] = ft_substr(str, start, i - start);
			// Si ft_substr falla (malloc interno), aborta devolviendo 0 (falso)
			if (!words[word_index])
				return (0);
			word_index++; // Avanza a la siguiente posición del array
		}
	}
	words[word_index] = NULL; // El array de punteros DEBE terminar en NULL (puntero nulo)
	return (1); // Éxito total
}

char	**ft_split(char const *s, char c)
{
	char const	*str;
	char		**words; // El array bidimensional (array de strings)

	str = (char const *)s;
	// Protección contra puntero nulo
	if (!str)
		return (NULL);
// Reserva memoria para el array de punteros. 
	// Tamaño: (Número de palabras + 1) multiplicado por el tamaño de un puntero (char *)
	// El "+ 1" es para el puntero NULL obligatorio al final.
	words = malloc(sizeof(char *) * (ft_count_words (str, c) + 1));
	if (!words)
		return (NULL);
// Rellena el array con las palabras. 
	// Si la función de rellenar devuelve 0 (falló un malloc interno)...
	if (!ft_fill_words(s, c, words))
	// ...llama a ft_free_words para limpiar lo que se llegó a reservar y evitar leaks.
		return (ft_free_words(words, ft_count_words(s, c)));
	return (words); // Devuelve el array bidimensional completamente listo
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello world green";
	char	character = ' ';
	char	**result;
	int		k;

	k = 0;
	// Divide la cadena usando el espacio como delimitador
	result = ft_split(str, character);
	// Recorre el array bidimensional hasta encontrar el puntero NULL del final
	while (result[k])
	{
		printf("%s\n", result[k]);
		// Imprimirá en líneas separadas:
		// Hello
		// world
		// green
		k++;
	}
	return (0);
}*/
