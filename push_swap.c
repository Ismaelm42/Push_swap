
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

int	lowest_nbr(t_stack stack_a)
{
	int	n;
	int	i;
	int	low_nbr;

	n = 1;
	i = 0;
	low_nbr = stack_a.values[0];
	while (n < stack_a.len)
	{
		if (stack_a.values[n] < low_nbr)
		{
			low_nbr = stack_a.values[n];
			i = n;
		}
		n++;
	}
	return (i);
}

t_stack	simplified_values(t_stack stack_a)
{
	int	i;
	int	n;
	int	counter;

	stack_a.simplified_values = malloc(sizeof(int) * stack_a.len);
	stack_a.simplified_values[lowest_nbr(stack_a)] = 1;
	n = stack_a.values[lowest_nbr(stack_a)] + 1;
	counter = 1;
	while (counter < stack_a.len)
	{
		i = 0;
		while (i < stack_a.len)
		{
			if (stack_a.values[i] == n)
			{
				stack_a.simplified_values[i] = counter + 1;
				counter++;
			}
			i++;
		}
		n++;
	}
	return (stack_a);
}
