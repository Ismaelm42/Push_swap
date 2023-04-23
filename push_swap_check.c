#include "push_swap.h"

void	int_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	check_int_numbers(char **argv_stack)
{
	int	n;
	int	i;

	n = 0;
	if (argv_stack[n] == NULL)
		int_error();
	while (argv_stack[n] != NULL)
	{
		i = 0;
		while (argv_stack[n][i] != 0)
		{
			if ((i == 0)
				&& (argv_stack[n][i] == '-' || argv_stack[n][i] == '+'))
			{
				if (argv_stack[n][i + 1] < '0' || argv_stack[n][i + 1] > '9')
					int_error();
			}
			else if (argv_stack[n][i] < '0' || argv_stack[n][i] > '9')
				int_error();
			i++;
		}
		n++;
	}
}

void	check_dup_stack_a(t_stack stack_a)
{
	int	n;
	int	i;

	n = 0;
	while (n < stack_a.len - 1)
	{
		i = n + 1;
		while (i < stack_a.len)
		{
			if (stack_a.values[n] == stack_a.values[i])
				int_error();
			i++;
		}
		n++;
	}
}

long int	push_swap_atoi(const char *str)
{
	long int	i;
	long int	j;
	long int	k;

	i = 0;
	while (str[i] == 32 || str[i] == 12 || str[i] == 10
		|| str[i] == 13 || str[i] == 11 || str[i] == 9)
		i++;
	k = 1;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			k = -1;
		i++;
	}
	j = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		j = j * 10 + str[i] - '0';
		i++;
	}
	if ((k * j) < -2147483648 || (k *j) > 2147483647)
		int_error();
	return ((k * j));
}
// void	already_sorted()
// {

// }
