/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:58:07 by patperez          #+#    #+#             */
/*   Updated: 2026/07/22 13:28:43 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

/*
	1. Declare loop counters 'i' and 'j', and a long integer 'result' for value validation.
	2. Initialize array index counter 'j' to -1 to start checking each argument string.
	3. Loop through each argument string in the 'args' array until reaching NULL.
	4. Reset string character index 'i' to 0 for the current argument.
	5. Check if the string starts with a negative sign '-'; if so, advance 'i' past it.
	6. Iterate through the remaining characters of the current argument string.
	7. If any character is not a digit (0-9), return 0 to flag the input as invalid.
	8. Convert the argument string into a long integer using 'ft_atol'.
	9. Check if 'result' exceeds standard 32-bit integer limits (INT_MAX or INT_MIN).
	10. Return 0 if the converted number falls outside valid 32-bit integer limits.
	11. Return 1 if all arguments contain only valid, range-compliant integer strings.
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
	1. Declare outer counter 'i', inner counter 'j', and variables 'result' and 'tmp'.
	2. Initialize 'i' to 0 to iterate through all elements in the arguments array.
	3. Convert the current argument at index 'i' into a long integer 'result'.
	4. Run an inner loop 'j' to check 'result' against all previously processed arguments.
	5. Convert the previous argument at index 'j' into a long integer 'tmp'.
	6. If 'result' equals 'tmp', a duplicate value exists; return 0 immediately.
	7. Increment 'j' to continue checking prior elements.
	8. Increment 'i' to evaluate the next argument in the array.
	9. Return 1 if all arguments are unique and no repetitions were found.
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
	1. Declare loop counter 'i' and a pointer 'stack_a' for the main stack structure.
	2. Initialize new stack 'stack_a'; if allocation fails, return NULL immediately.
	3. Loop through all argument strings, converting each to a node and pushing to back of stack.
	4. Calculate the initial disorder metric of 'stack_a' and store it in the bench structure.
	5. Explicitly cast 'flag_bench' to void to suppress unused variable compiler warnings.
	6. Check if the stack is already fully sorted (disorder metric equals 0).
	7. Print benchmark information if the benchmark flag is set.
	8. Clean up memory by freeing benchmark data, the stack, and the split arguments array.
	9. Exit program execution directly with code 0 if the stack was already sorted.
	10. Return the populated 'stack_a' pointer if sorting is required.
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
	1. Validate arguments using 'ft_is_validint' and duplicate check 'ft_isrepeat'.
	2. If validation fails (either returns 0), free allocated benchmark data and split arguments.
	3. Write "Error\n" to standard error (fd 2) and exit the program with error status.
	4. If validation succeeds, return result of 'ft_input_conversion' to construct stack.
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
	1. Declare pointer 'converted_stack' to hold the initialized stack structure.
	2. Validate inputs and convert argument array into 'converted_stack'.
	3. Check if explicit flag is set to "--simple" for O(n2) sorting strategy.
	4. Set strategy label to "Simple / O(n2)" and execute 'ft_bubble_sort'.
	5. Else, check if flag is set to "--medium" for O(n√n) bucket sorting strategy.
	6. Set strategy label to "Medium / O(n√n)" and execute 'ft_bucket'.
	7. Else, check if flag is set to "--complex" for O(n log n) radix sorting strategy.
	8. Set strategy label, assign node indexes, execute 'ft_radix', and clear stack memory.
	9. Else, if flag is set to "--adaptive" or omitted, default to 'ft_adaptive_algo'.
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
