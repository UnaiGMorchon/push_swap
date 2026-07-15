/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:56:46 by unai              #+#    #+#             */
/*   Updated: 2026/07/06 10:41:32 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	string1[] = "Hello";
	char	string2[] = "world";
	char	*result;

	result = ft_strjoin(string1, string2);
// Debería imprimir: "Helloworld" (todo junto, ya que la función no añade espacios por sí sola)
	printf("%s\n", result);

// Recuerda que al salir de la función, si esto fuera un programa real,
	// deberías liberar la memoria reservada:
	// free(result);
	return (0);
}*/
