
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
	return (argv_stack);
}

int	*stack(char **argv_stack)
{
	int	*stack;
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (argv_stack[len] != NULL)
		len++;
	stack = malloc(sizeof(int) * len);
	while (i < len)
	{
		stack[i] = ft_atoi(argv_stack[i]);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	int	*stack_values;

	stack_values = stack(argv_stack(argc, argv));
	return (0);
}
