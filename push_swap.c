/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:21:30 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:33:42 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Check if the input string 'str' starts with the flag "--bench" using 'ft_strncmp'.
	2. Return 1 if the benchmark flag is detected.
	3. Return 0 if the string does not match the benchmark flag.
*/

int	ft_is_bench(char *str)
{
	if (ft_strncmp(str, "--bench", 7) == 0)
		return (1);
	return (0);
}
/*
	1. Check if the input string matches the "--simple" algorithm strategy flag.
	2. Check if the input string matches the "--medium" algorithm strategy flag.
	3. Check if the input string matches the "--complex" algorithm strategy flag.
	4. Check if the input string matches the "--adaptive" algorithm strategy flag.
	5. Return 1 if any valid strategy flag is matched.
	6. Return 0 if the input string does not match any known algorithm flag.
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
	1. Check if current argument at index '*i' is the benchmark flag using 'ft_is_bench'.
	2. Store benchmark flag pointer in 'flag_bench' and advance argument index counter '*i'.
	3. Check if the current argument at index '*i' is a valid strategy flag using 'ft_is_flag'.
	4. Store strategy flag pointer in 'flag_bench' and advance argument index counter '*i'.
	5. Fallback: if no strategy flag is explicitly given, default strategy flag to "--adaptive".
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
	1. Declare index 'j', remaining parameter count 'param', and string array pointer 'args'.
	2. Initialize array index counter 'j' to 0.
	3. Calculate total remaining number of arguments starting from offset index '*i'.
	4. Return NULL if no arguments remain to be processed.
	5. Handle single formatted string argument case by splitting words by spaces using 'ft_split'.
	6. Allocate memory for array of string pointers based on 'param' count plus NULL terminator.
	7. Return NULL if dynamic memory allocation fails.
	8. Loop through remaining command-line arguments in 'argv' array.
	9. Duplicate each argument string into 'args' array and advance argument index '*i'.
	10. Set final array element to NULL to create a properly terminated array.
	11. Return pointer to newly assembled arguments array.
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
	1. Declare argument array 'args', tracking structures 'bench' and 'flag_bench', and index 'i'.
	2. Initialize argument offset index 'i' to 1 (skipping executable name).
	3. Allocate and initialize metric structure 'bench' and flag wrapper 'flag_bench'.
	4. Extract benchmark and algorithm strategy flags from 'argv' inputs.
	5. Format and process raw numerical arguments into array 'args'.
	6. Clean up memory allocations and return -1 if argument processing failed.
	7. Parse flags and trigger the corresponding sorting execution flow.
	8. Print benchmark output metrics if benchmark flag was specified.
	9. Free allocated string array 'args', flag wrapper 'flag_bench', and benchmark memory 'bench'.
	10. Return 0 indicating successful execution completion.
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
