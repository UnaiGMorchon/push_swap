/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:52:39 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Comprobar si la cadena de entrada 'str' empieza con el flag "--bench" usando 'ft_strncmp'.
	2. Devolver 1 si se detecta el flag de benchmark.
	3. Devolver 0 si la cadena no coincide con el flag de benchmark.
*/

int	ft_is_bench(char *str)
{
	if (ft_strncmp(str, "--bench", 7) == 0)
		return (1);
	return (0);
}
/*
	1. Comprobar si la cadena de entrada coincide con el flag de estrategia de algoritmo "--simple".
	2. Comprobar si la cadena de entrada coincide con el flag de estrategia de algoritmo "--medium".
	3. Comprobar si la cadena de entrada coincide con el flag de estrategia de algoritmo "--complex".
	4. Comprobar si la cadena de entrada coincide con el flag de estrategia de algoritmo "--adaptive".
	5. Devolver 1 si coincide con cualquier flag de estrategia válido.
	6. Devolver 0 si la cadena de entrada no coincide con ningún flag de algoritmo conocido.
*/

int	ft_is_flag(char *str)
{
	if (ft_strncmp(str, "--simple", 8) == 0)
		return (1);
	if (ft_strncmp(str, "--medium", 8) == 0)
		return (1);
	if (ft_strncmp(str, "--complex", 10) == 0)
		return (1);
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (1);
	return (0);
}
/*
	1. Comprobar si el argumento actual en el índice '*i' es el flag de benchmark usando 'ft_is_bench'.
	2. Almacenar el puntero del flag de benchmark en 'flag_bench' y avanzar el contador de índice de argumentos '*i'.
	3. Comprobar si el argumento actual en el índice '*i' es un flag de estrategia válido usando 'ft_is_flag'.
	4. Almacenar el puntero del flag de estrategia en 'flag_bench' y avanzar el contador de índice de argumentos '*i'.
	5. Alternativa: si no se proporciona explícitamente un flag de estrategia, establecer por defecto el flag "--adaptive".
*/

void	ft_separate_flags(char **argv, t_isflag *flag_bench, int *i)
{
	if (ft_is_bench(argv[*i]) == 1)
	{
		flag_bench -> bench = argv[*i];
		*i += 1;
	}
	if (ft_is_flag(argv[*i]) == 1)
	{
		flag_bench -> flag = argv[*i];
		*i += 1;
	}
	else
	{
		flag_bench -> flag = "--adaptive";
	}
}
/*
	1. Declarar el índice 'j', el recuento de parámetros restantes 'param', y el puntero al array de cadenas 'args'.
	2. Inicializar el contador de índice del array 'j' en 0.
	3. Calcular el número total de argumentos restantes a partir del índice de desplazamiento '*i'.
	4. Devolver NULL si no quedan argumentos por procesar.
	5. Manejar el caso de un único argumento con formato de cadena dividiendo las palabras por espacios usando 'ft_split'.
	6. Asignar memoria para el array de punteros de cadenas según el recuento 'param' más el terminador NULL.
	7. Devolver NULL si la asignación dinámica de memoria falla.
	8. Recorrer los argumentos restantes de la línea de comandos en el array 'argv'.
	9. Duplicar cada cadena de argumento dentro del array 'args' y avanzar el índice de argumentos '*i'.
	10. Establecer el último elemento del array como NULL para crear un array correctamente terminado.
	11. Devolver el puntero al array de argumentos recién ensamblado.
*/

char	**ft_new_args(int argc, char **argv, int *i)
{
	int		j;
	int		param;
	char	**args;

	j = 0;
	param = ft_args_count(i, argc);
	if (param == 0)
		return (NULL);
	if (param == 1)
	{
		args = ft_split(argv[*i], ' ');
		*i += 1;
		return (args);
	}
	args = malloc(sizeof(*args) * (param + 1));
	if (args == NULL)
		return (NULL);
	while (argv[*i])
	{
		args[j] = ft_strdup(argv[*i]);
		*i += 1;
		j++;
	}
	args[j] = NULL;
	return (args);
}
/*
	1. Declarar el array de argumentos 'args', las estructuras de seguimiento 'bench' y 'flag_bench', y el índice 'i'.
	2. Inicializar el índice de desplazamiento de argumentos 'i' en 1 (saltando el nombre del ejecutable).
	3. Asignar e inicializar la estructura de métricas 'bench' y el contenedor de flags 'flag_bench'.
	4. Extraer los flags de benchmark y de estrategia de algoritmo a partir de las entradas en 'argv'.
	5. Formatear y procesar los argumentos numéricos brutos dentro del array 'args'.
	6. Limpiar las asignaciones de memoria y devolver -1 si el procesamiento de argumentos falló.
	7. Analizar los flags y activar el flujo de ejecución de ordenación correspondiente.
	8. Imprimir las métricas de salida del benchmark si se especificó el flag de benchmark.
	9. Liberar el array de cadenas asignado 'args', el contenedor de flags 'flag_bench' y la memoria de 'bench'.
	10. Devolver 0 indicando la finalización exitosa de la ejecución.
*/

int	push_swap(int argc, char **argv)
{
	char		**args;
	t_bench		*bench;
	t_isflag	*flag_bench;
	int			i;

	i = 1;
	args = NULL;
	bench = ft_initialise_bench();
	flag_bench = ft_initialise_flag_bench();
	ft_separate_flags(argv, flag_bench, &i);
	args = ft_new_args(argc, argv, &i);
	if (args == NULL)
	{
		free(flag_bench);
		free(bench);
		return (-1);
	}
	ft_flag_search_parsing(args, flag_bench, bench);
	if (flag_bench -> bench || (flag_bench -> bench && bench -> disorder == 0))
		ft_print_bench(bench);
	ft_free_split(args);
	free(flag_bench);
	free(bench);
	return (0);
}
