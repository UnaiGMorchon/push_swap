/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/06 15:19:30 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
convertirlo a string separados por espacios, concatenar. (contar los que tenemos?)
trocear hacerle el split?. trocerar
validar que sea números, convertirlos a números isdigit? validar
sin duplicados, sin negativos, no se salgan de los limites, atoi? convertir
*/


int	main(int argc, char **argv)
{
	//char	dest[50] = "";
	//int		i;
	//char	string;
	//char	**resultado_split;
	//int		isdigit;
	int	rest;
	//int	rest_repeat;

	if (argc < 2)
		return (1);

/* 	i = 1;
	while (i < argc)
	{
		resultado_split = ft_split(argv[i], ' ');
		i++;
	}
 */
		rest = ft_is_validint(argc, argv);

 
	//rest_repeat = ft_isrepeat(*argv);
	
	
	/* i = 1;
	while (i < argc)
	{ */
		//isdigit = ft_isdigit(argv[i]);
		//string = ft_strlcat(dest, argv[i], 50);
		//string = ft_strjoin(dest, argv[i]);
		//
/* 
		i++;
	} */


	printf("Número total de argumentos: %d\n", argc);
	printf("El primer número es: %s\n", argv[1]);
	//printf("total string size: %d\n", string);
	printf("resultado: %d\n", rest);
	//printf("repeat: %d\n", rest_repeat);
	//printf("total string size: %p\n", resultado_split);
	//printf("total string size: %d\n", isdigit);
	//printf("string destino: %s\n", dest);
	return (0);
}
