/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:22:32 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/04/17 14:28:55 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**argv_stack(int argc, char **argv)
{
	char	**argv_stack;
	int		i;

	if (argc == 2)
		argv_stack = ft_split(argv[1], 32);
	if (argc > 2)
	{
		i = 0;
		argv_stack = malloc (sizeof(char *) * argc);
		while (i < (argc - 1))
		{
			argv_stack[i] = ft_strdup(argv[1 + i]);
			i++;
		}
		argv_stack[i] = NULL;
	}
	check_int_numbers(argv_stack);
	return (argv_stack);
}

t_stack	init_stack_a(char **argv_stack)
{
	t_stack	stack_a;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (argv_stack[len] != NULL)
		len++;
	stack_a.len = len;
	stack_a.values = malloc(sizeof(int) * len);
	while (i < len)
	{
		stack_a.values[i] = push_swap_atoi(argv_stack[i]);
		i++;
	}
	check_dup_stack_a(stack_a);
	stack_a.id = 'a';
	return (stack_a);
}

t_stack	init_stack_b(t_stack stack_a)
{
	t_stack	stack_b;
	int		i;

	i = 0;
	stack_b.len = stack_a.len;
	stack_b.simplified_values = malloc(sizeof(int) * stack_a.len);
	while (i < stack_b.len)
	{
		stack_b.simplified_values[i] = 0;
		i++;
	}
	stack_b.id = 'b';
	return (stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		int_error();
	stack_a = init_stack_a(argv_stack(argc, argv));
	stack_a = simplified_values(stack_a);
	stack_b = init_stack_b(stack_a);
	push(stack_b, stack_a);
	push(stack_b, stack_a);
	push(stack_b, stack_a);
	printfunction(stack_a, stack_b);
	rev_rotate(stack_a);
	printfunction(stack_a, stack_b);
	push(stack_b, stack_a);
	printfunction(stack_a, stack_b);
	return (0);
}
