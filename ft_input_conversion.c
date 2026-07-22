/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:58:07 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:42:52 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declarar los contadores de bucle 'i' y 'j', y un entero largo 'result' para la validación de valores.
	2. Inicializar el contador de índice del array 'j' en -1 para comenzar a comprobar cada cadena de argumentos.
	3. Recorrer cada cadena de argumentos en el array 'args' hasta llegar a NULL.
	4. Reiniciar el índice de caracteres de la cadena 'i' a 0 para el argumento actual.
	5. Comprobar si la cadena empieza con un signo negativo '-'; si es así, avanzar 'i' más allá del signo.
	6. Iterar a través de los caracteres restantes de la cadena del argumento actual.
	7. Si algún carácter no es un dígito (0-9), devolver 0 para marcar la entrada como no válida.
	8. Convertir la cadena del argumento en un entero largo usando 'ft_atol'.
	9. Comprobar si 'result' excede los límites estándar de un entero de 32 bits (INT_MAX o INT_MIN).
	10. Devolver 0 si el número convertido está fuera de los límites válidos de un entero de 32 bits.
	11. Devolver 1 si todos los argumentos contienen solo cadenas de enteros válidas y dentro del rango.
*/

long int	ft_is_validint(char **args)
{
	int			i;
	int			j;
	long int	result;

	j = -1;
	while (args[++j])
	{
		i = 0;
		if (args[j][0] == '-')
			i++;
		while (args[j][i])
		{
			if (!ft_isdigit(args[j][i++]))
			{
				return (0);
			}
		}
		result = ft_atol(args[j]);
		if (result > 2147483647 || result < -2147483648)
		{
			return (0);
		}
	}
	return (1);
}

/*
	1. Declarar el contador externo 'i', el contador interno 'j', y las variables 'result' y 'tmp'.
	2. Inicializar 'i' en 0 para iterar a través de todos los elementos del array de argumentos.
	3. Convertir el argumento actual en el índice 'i' a un entero largo 'result'.
	4. Ejecutar un bucle interno 'j' para comparar 'result' con todos los argumentos procesados anteriormente.
	5. Convertir el argumento anterior en el índice 'j' a un entero largo 'tmp'.
	6. Si 'result' es igual a 'tmp', existe un valor duplicado; devolver 0 inmediatamente.
	7. Incrementar 'j' para continuar comprobando los elementos anteriores.
	8. Incrementar 'i' para evaluar el siguiente argumento en el array.
	9. Devolver 1 si todos los argumentos son únicos y no se encontraron repeticiones.
*/

int	ft_isrepeat(char **args)
{
	int			i;
	int			j;
	long int	result;
	long int	tmp;

	i = 0;
	while (args[i])
	{
		j = 0;
		result = ft_atol(args[i]);
		while (j < i)
		{
			tmp = ft_atol(args[j]);
			if (result == tmp)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
/*
	1. Declarar el contador de bucle 'i' y un puntero 'stack_a' para la estructura de la pila principal.
	2. Inicializar la nueva pila 'stack_a'; si la asignación falla, devolver NULL inmediatamente.
	3. Recorrer todas las cadenas de argumentos, convirtiendo cada una a un nodo y añadiéndola al final de la pila.
	4. Calcular la métrica de desorden inicial de 'stack_a' y almacenarla en la estructura bench.
	5. Hacer un casteo explícito de 'flag_bench' a void para evitar advertencias del compilador por variable no usada.
	6. Comprobar si la pila ya está completamente ordenada (métrica de desorden igual a 0).
	7. Imprimir la información del benchmark si la bandera de benchmark está activada.
	8. Limpiar la memoria liberando los datos del benchmark, la pila y el array de argumentos divididos.
	9. Salir directamente de la ejecución del programa con código 0 si la pila ya estaba ordenada.
	10. Devolver el puntero a la pila 'stack_a' poblada si se requiere ordenación.
*/

t_stack	*ft_input_conversion(char **args, t_bench *bench, t_isflag *flag_bench)
{
	int			i;
	t_stack		*stack_a;

	i = 0;
	stack_a = ft_newstack();
	if (!stack_a)
		return (NULL);
	while (args[i])
	{
		ft_stackadd_back(stack_a, ft_newnode(ft_atol(args[i])));
		i++;
	}
	bench -> disorder = ft_disorder_metric(stack_a);
	(void)flag_bench;
	if (bench -> disorder == 0)
	{
		if (flag_bench -> bench)
			ft_print_bench(bench);
		free(bench);
		free(flag_bench);
		ft_clearstack(stack_a);
		ft_free_split(args);
		exit(0);
	}
	return (stack_a);
}

/*
	1. Validar argumentos usando 'ft_is_validint' y la comprobación de duplicados 'ft_isrepeat'.
	2. Si la validación falla (cualquiera devuelve 0), liberar los datos asignados del benchmark y los argumentos divididos.
	3. Escribir "Error\n" en la salida de error estándar (fd 2) y salir del programa con estado de error.
	4. Si la validación tiene éxito, devolver el resultado de 'ft_input_conversion' para construir la pila.
*/

t_stack	*ft_valid_and_convert(char **args, t_bench *bench, t_isflag *flag_bench)
{
	if (ft_is_validint(args) == 0 || ft_isrepeat(args) == 0)
	{
		free(bench);
		free(flag_bench);
		ft_free_split(args);
		exit(write(2, "Error\n", 6));
	}
	return (ft_input_conversion(args, bench, flag_bench));
}

/*
	1. Declarar el puntero 'converted_stack' para contener la estructura de la pila inicializada.
	2. Validar las entradas y convertir el array de argumentos en 'converted_stack'.
	3. Comprobar si la bandera explícita está configurada en "--simple" para la estrategia de ordenación O(n2).
	4. Establecer la etiqueta de estrategia en "Simple / O(n2)" y ejecutar 'ft_bubble_sort'.
	5. En caso contrario, comprobar si la bandera está en "--medium" para la estrategia de bloques O(n√n).
	6. Establecer la etiqueta de estrategia en "Medium / O(n√n)" y ejecutar 'ft_bucket'.
	7. En caso contrario, comprobar si la bandera está en "--complex" para la estrategia radix O(n log n).
	8. Establecer etiqueta de estrategia, asignar índices a nodos, ejecutar 'ft_radix' y limpiar memoria de la pila.
	9. En caso contrario, si la bandera está en "--adaptive" o se omite, usar por defecto 'ft_adaptive_algo'.
*/

void	ft_flag_search_parsing(char **args, t_isflag *flag_bench,
			t_bench *bench)
{
	t_stack	*converted_stack;

	converted_stack = ft_valid_and_convert(args, bench, flag_bench);
	if (ft_strncmp(flag_bench -> flag, "--simple", 8) == 0)
	{
		bench -> strategy = "Simple / O(n2)";
		ft_bubble_sort(converted_stack, bench);
	}
	else if (ft_strncmp(flag_bench -> flag, "--medium", 8) == 0)
	{
		bench -> strategy = "Medium / O(n√n)";
		ft_bucket(converted_stack, bench);
	}
	else if (ft_strncmp(flag_bench -> flag, "--complex", 9) == 0)
	{
		bench -> strategy = "Complex / O(n log n)";
		ft_get_index(converted_stack);
		ft_radix(converted_stack, bench);
		ft_clearstack(converted_stack);
	}
	else if (ft_strncmp(flag_bench -> flag, "--adaptive", 10) == 0
		|| !flag_bench -> flag)
	{
		ft_adaptive_algo(converted_stack, bench);
	}
}
